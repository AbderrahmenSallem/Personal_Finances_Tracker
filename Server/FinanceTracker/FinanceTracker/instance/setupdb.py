import hashlib
import sqlite3

# Define database name
DATABASE_NAME = "app.db"

def create_database():
    connection = sqlite3.connect(DATABASE_NAME)
    cursor = connection.cursor()

    # Create 'users' table
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL CHECK(LENGTH(name) <= 100),
        address TEXT NOT NULL CHECK(LENGTH(address) <= 200),
        hash TEXT NOT NULL CHECK(LENGTH(hash) <= 256),
        verified INTEGER NOT NULL CHECK(verified IN (0, 1)) DEFAULT 0
    )
    """)

    # Create 'accounts' table
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS accounts (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        owner_id INTEGER NOT NULL,
        account_name TEXT NOT NULL CHECK(LENGTH(account_name) <= 100),
        account_type TEXT NOT NULL CHECK(account_type IN ('Savings', 'Checking', 'Investment')),
        balance INTEGER NOT NULL DEFAULT 0,
        m_currency TEXT NOT NULL CHECK(LENGTH(m_currency) <= 10),
        FOREIGN KEY (owner_id) REFERENCES users(id) ON DELETE CASCADE
    )
    """)

    # Create 'category' table
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS category (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        description TEXT NOT NULL CHECK(LENGTH(description) <= 100)
    )
    """)

    # Create 'transactions' table
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS transactions (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        date TEXT NOT NULL CHECK(LENGTH(date) = 10),  -- Format: DD-MM-YYYY
        description TEXT NOT NULL CHECK(LENGTH(description) <= 255),
        amount INTEGER NOT NULL,
        type TEXT NOT NULL CHECK(type IN ('Income', 'Expense')),
        category_id INTEGER NOT NULL,
        account_id INTEGER NOT NULL,
        FOREIGN KEY (category_id) REFERENCES category(id) ON DELETE SET NULL,
        FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
    )
    """)

    # Commit changes and close connection
    connection.commit()
    connection.close()
    print("Database schema created successfully!")


def hash_password(password):
    # Use SHA-256 to hash the password
    hashed = hashlib.sha256(password.encode('utf-8')).hexdigest()
    return hashed

# Execute the schema setup
if __name__ == "__main__":
    create_database()
