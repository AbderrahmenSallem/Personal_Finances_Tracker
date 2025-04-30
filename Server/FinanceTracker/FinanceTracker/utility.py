import sqlite3
import hashlib
import re
from flask import session
import os
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

class UserAlreadyExistsError(Exception):
    """Custom exception for duplicate user entries."""
    pass


class InputValidationError(Exception):
    """Custom exception for input validation errors."""
    pass

class UserDoesNotExistError(Exception):
    """Raised when no user exists with the given email and password."""
    pass

class UserNotVerifiedError(Exception):
    """Raised when the user exists but has not been verified."""
    pass


DATABASE_PATH = "./FinanceTracker/instance/app.db"  # Path to the database file

def validate_inputs(name, email, password):
    """
    Validates name, email, and password.
    Raises InputValidationError with a message if validation fails.
    """

    # Validate name: Only letters and spaces allowed; max 100 characters
    name_regex = r'^[A-Za-z\s]{1,100}$'
    if not re.match(name_regex, name):
        raise InputValidationError("Invalid name: Only alphabetic characters and spaces allowed, max 100 characters.")

    # Validate email: Standard email regex
    email_regex = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
    if not re.match(email_regex, email):
        raise InputValidationError("Invalid email: Must be a valid email format.")

    # Validate password: At least 8 characters, one letter, one digit, one special character
    password_regex = r'^(?=.*[A-Za-z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$'
    if not re.match(password_regex, password):
        raise InputValidationError(
            "Invalid password: Must be at least 8 characters, include at least one letter, one digit, and one special character."
        )

def hash_password(password):
    """
    Hashes the password using SHA-256.
    """
    return hashlib.sha256(password.encode('utf-8')).hexdigest()

def addUserDb(username, password, email):
    """
    Adds a user to the database if the email is unique.
    Throws UserAlreadyExistsError if the email is already in use.
    """
    connection = None  # Initialize connection to None
    try:
        # Connect to the database
        connection = sqlite3.connect(DATABASE_PATH)
        cursor = connection.cursor()

        # Check if a user with the given email already exists
        cursor.execute("SELECT COUNT(*) FROM users WHERE address = ?", (email,))
        user_count = cursor.fetchone()[0]
        if user_count > 0:
            connection.close()
            raise UserAlreadyExistsError(f"User with email '{email}' already exists.")

        # Hash the password
        hashed_password = hash_password(password)

        # Add the user to the database
        cursor.execute("INSERT INTO users (name, address, hash) VALUES (?, ?, ?)", (username, email, hashed_password))

        # Commit changes and close the connection
        connection.commit()
        connection.close()
    except sqlite3.Error as e:
        print(f"Database error: {e}")
    finally:
        if connection:
            connection.close()

def LogUserIn(email, password):
    """
    Authenticates and logs in a user based on email and password.

    Parameters:
        email (str): The user's email address.
        password (str): The user's plaintext password.

    Raises:
        UserDoesNotExistError: If no user exists with the given email and hashed password.
        UserNotVerifiedError: If the user exists but has not been verified.

    Actions:
        Saves user data (id, name, email, hash) to session cookies if verified.
    """
    connection = None
    try:
        # Connect to the database
        connection = sqlite3.connect(DATABASE_PATH)
        cursor = connection.cursor()

        # Query the database for all user data
        cursor.execute("SELECT id, name, address, hash, verified FROM users WHERE address = ? AND hash = ?", 
                       (email, hash_password(password)))
        row = cursor.fetchone()

        # Check if the user exists
        if not row:
            raise UserDoesNotExistError("Email or password is wrong or something.")

        # Extract user data
        user_id, name, address, hashed_password, verified = row

        # Check if the user is verified
        if verified == 0:
            session['email'] = address
            raise UserNotVerifiedError("User account has not been verified.")

        # Save user data to cookies (pseudo-code for Flask)
        session['user_id'] = user_id
        session['name'] = name
        session['email'] = address
        session['hash'] = hashed_password
        session['logged_in'] = True

        print("User logged in successfully.")

    except sqlite3.Error as e:
        print(f"Database error: {e}")
    finally:
        if connection:
            connection.close()



def send_verification_email(to_email, verification_code, html_template_path):
    """
    Sends an email with an HTML template containing the verification code.

    Args:
        to_email (str): Recipient's email address.
        verification_code (str): The code to be included in the email.
        html_template_path (str): Path to the HTML template file.

    Returns:
        None
    """
    print(os.getcwd())
    # Fetch email credentials from environment variables
    sender_email = os.getenv("EMAIL_ADDRESS")
    sender_password = os.getenv("EMAIL_PASSWORD")
    if not sender_email or not sender_password:
        raise ValueError("Email credentials not found in environment variables.")

    # Read HTML template and insert verification code
    with open(html_template_path, "r", encoding="utf-8") as file:
        html_content = file.read().replace("{{VERIFICATION_CODE}}", verification_code)

    # Create email message
    msg = MIMEMultipart()
    msg["From"] = sender_email
    msg["To"] = to_email
    msg["Subject"] = "Your Verification Code"

    # Attach HTML content
    msg.attach(MIMEText(html_content, "html"))

    try:
        # Connect to SMTP server and send email
        server = smtplib.SMTP("smtp.gmail.com", 587)  # Change this based on your email provider
        server.starttls()
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, to_email, msg.as_string())
        server.quit()

        print("Verification email sent successfully!")

    except Exception as e:
        print(f"Failed to send email: {e}")

def verifyEmail():
    connection = None 
    try:
        connection = sqlite3.connect(DATABASE_PATH)
        cursor = connection.cursor()
        cursor.execute("UPDATE users SET verified = 1 WHERE address = ?", (session.get("email"),))
        connection.commit()
        connection.close()
    except sqlite3.Error as e:
        print(f"Database error: {e}")
    finally:
        if connection:
            connection.close()