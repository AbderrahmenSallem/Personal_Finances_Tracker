import sqlite3
import hashlib
import random
# Define the database name
DATABASE_NAME = "app.db"

def hash_password(password):
    """
    Hash the user's password using SHA-256.
    """
    return hashlib.sha256(password.encode('utf-8')).hexdigest()

# adds a user
def insert_user(name, address, password):
    """
    Insert a user into the 'users' table in the database.
    """
    try:
        # Connect to the SQLite database
        connection = sqlite3.connect(DATABASE_NAME)
        cursor = connection.cursor()

        # Hash the password
        hashed_password = hash_password(password)

        # SQL to insert user data
        cursor.execute("""
        INSERT INTO users (name, address, hash, verified)
        VALUES (?, ?, ?, ?)
        """, (name, address, hashed_password, 1))

        # Commit the transaction
        connection.commit()

        print("User added successfully!")

    except sqlite3.Error as e:
        print(f"An error occurred: {e}")

    finally:
        # Close the database connection
        connection.close()

def display_users():
    """
    Fetch and display all users from the 'users' table.
    """
    try:
        # Connect to the SQLite database
        connection = sqlite3.connect(DATABASE_NAME)
        cursor = connection.cursor()

        # Fetch all user data
        cursor.execute("SELECT * FROM users")
        rows = cursor.fetchall()

        # Print the results
        print("Users in the database:")
        for row in rows:
            print(f"ID: {row[0]}, Name: {row[1]}, Address: {row[2]}, Password Hash: {row[3]}, Verified {row[4]}")

    except sqlite3.Error as e:
        print(f"An error occurred: {e}")

    finally:
        # Close the database connection
        connection.close()

# adds two accounts for user ID 1
def add_accounts():
    connection = sqlite3.connect(DATABASE_NAME)
    cursor = connection.cursor()

    # Insert two accounts for user ID 1
    cursor.executemany("""
    INSERT INTO accounts (owner_id, account_name, account_type, balance, m_currency)
    VALUES (?, ?, ?, ?, ?)
    """, [
        (1, "Personal Savings", "Savings", 5000, "USD"),
        (1, "Daily Expenses", "Checking", 1000, "USD")
    ])

    connection.commit()
    connection.close()
    print("Added two accounts successfully!")

# adds a 100 transaction for user ID 0
def add_transactions():
    connection = sqlite3.connect(DATABASE_NAME)
    cursor = connection.cursor()

    # Generate 100 random transactions
    transactions = []
    for _ in range(100):
        account_id = random.choice([1, 2])  # Assuming IDs 1 & 2 belong to our accounts
        amount = random.randint(10, 500)  # Random amount between $10 and $500
        type_ = random.choice(["Income", "Expense"])
        category_id = random.randint(1, 5)  # Assuming categories exist (IDs 1-5)
        description = f"Auto-Generated {type_}"
        date = f"{random.randint(1, 28):02d}-{random.randint(1, 12):02d}-2025"  # Random day/month

        transactions.append((date, description, amount, type_, category_id, account_id))

    cursor.executemany("""
    INSERT INTO transactions (date, description, amount, type, category_id, account_id)
    VALUES (?, ?, ?, ?, ?, ?)
    """, transactions)

    connection.commit()
    connection.close()
    print("Added 100 transactions successfully!")

def generate_transaction_table():
    connection = sqlite3.connect("app.db")
    cursor = connection.cursor()

    cursor.execute("""
        SELECT id, date, description, amount, type, category_id, account_id
        FROM transactions
        ORDER BY date DESC
    """)
    transactions = cursor.fetchall()
    
    headers = ["ID", "Date", "Description", "Amount", "Type", "Category ID", "Account ID"]
    
    connection.close()
    return tabulate(transactions, headers, tablefmt="grid")


random_categories = ["Groceries", "Subscriptions", "Entertainment", "Utilities", "Dining Out",
                     "Healthcare", "Transportation", "Education", "Shopping", "Investments"]

def add_random_categories():
    connection = sqlite3.connect(DATABASE_NAME)
    cursor = connection.cursor()

    # Select 5 random categories
    selected_categories = random.sample(random_categories, 5)

    cursor.executemany("INSERT INTO category (description) VALUES (?)",
                       [(desc,) for desc in selected_categories])

    connection.commit()
    connection.close()
    print("Added 5 random categories successfully!")


# Example usage
if __name__ == "__main__":
    # Example of inserting a user
    #name = input("Enter your name (max 100 characters): ")
    #address = input("Enter your address (max 200 characters): ")
    #password = input("Enter your password: ")

    insert_user("nex", "testing@gmail.com", hash_password("ZOMBIEland@2004@"))

    # Adding accounts
    add_accounts()
    # Adding random categories
    add_random_categories()
    # Adding transactions
    add_transactions()
    # Display all users
    display_users()