from flask import Blueprint, jsonify
from flask import render_template, request, redirect, url_for, flash
from .utility import *
import random
auth = Blueprint('auth', __name__)  

# Route for user signup  
@auth.route('/signup', methods=['POST', 'GET'])
def signup():
    if (session.get("logged_in")):
        return render_template('dashboard.html')
    if request.method == 'POST':
        try:
            # Get form data
            username = request.form.get('username')
            password = request.form.get('password')
            email = request.form.get('email')

            # Validate inputs
            validate_inputs(username, email, password)
            addUserDb(username, password, email)
            # If validation is successful, redirect to the login page
            return jsonify({"status": "success", "message": "Signup successful!", "redirect_url": url_for('auth.login')}), 200

            #treat exception
        except InputValidationError as e:
            return jsonify({"status": "error", "message": str(e)}), 400
        except UserAlreadyExistsError as e:
            return jsonify({"status": "error", "message": str(e)}), 400

    
    # Render the signup page (for both GET or in case of validation error)
    return render_template(
        'signup.html',
        video='test.mp4'
    )

# Route for user login  
@auth.route('/login', methods=['POST', 'GET'])  
def login():
    if (session.get("logged_in")):
        return render_template('dashboard.html')
    if request.method == 'POST':
        try:
            # Get form data
            password = request.form.get('password')
            email = request.form.get('email')

            # Validate inputs
            validate_inputs("ValidUserName", email, password)
            LogUserIn(email, password)
            # If validation is successful, redirect to the login page
            return jsonify({"status": "success", "message": "LogIn successful!", "redirect_url": url_for('home')}), 200

            #treat exception
        except InputValidationError as e:
            return jsonify({"status": "error", "message": str(e)}), 400
        except UserDoesNotExistError as e:
            return jsonify({"status": "error", "message": str(e)}), 400
        except UserNotVerifiedError as e:
            return jsonify({"status": "error", "message": str(e), "redirect_url": url_for('auth.verify')}), 200
    return render_template(
    'login.html',
    video = 'test.mp4'
   )

@auth.route('/verify', methods=['POST', 'GET'])  
def verify():
    if request.method == 'POST':
        # Get the verification code from the form
        verifCode = request.form.get('verifCode')
        if (verifCode == session.get("verifCode")):
            verifyEmail()
            return jsonify({"status": "success", "message": "Account verified successfully!", "redirect_url": url_for('auth.login')}), 200
        else:
            return jsonify({"status": "error", "message": "Invalid verification code."}), 400
    session["verifCode"] = str(random.randint(0,999999))
    send_verification_email(session.get("email"), session.get("verifCode"), "FinanceTracker/templates/verifyaccount.html")
    return render_template(
        'validate.html',
        video = 'test.mp4')

