import sqlite3
from tabulate import tabulate

def generate_transaction_table():
    connection = sqlite3.connect("app.db")
    cursor = connection.cursor()

    cursor.execute("""
        SELECT id, date, description, amount, type, category_id, account_id
        FROM transactions
        ORDER BY id ASC  -- Change ASC to DESC if you want newest first
    """)
    transactions = cursor.fetchall()
    
    headers = ["ID", "Date", "Description", "Amount", "Type", "Category ID", "Account ID"]
    
    connection.close()
    return tabulate(transactions, headers, tablefmt="grid")

print(generate_transaction_table())