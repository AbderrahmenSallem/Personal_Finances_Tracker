"""
Routes and views for the flask application.
"""

from datetime import datetime
from flask import render_template, session
from FinanceTracker import app
from .auth import auth

# Register the auth blueprint
app.register_blueprint(auth, url_prefix='/auth')

@app.route('/')
@app.route('/home')
@app.route('/dashboard')
def home():
    if (session.get("logged_in")):
        return render_template('dashboard.html')
    return render_template(
        'index.html',
        video = "background.mp4"
    )
