"""
The flask application package.
"""

from flask import Flask
app = Flask(__name__)
app.secret_key = "a_secure_and_unique_key"
#app.jinja_env.add_extension('pypugjs.ext.jinja.PyPugJSExtension')
import FinanceTracker.views
