/**
* \file User.cpp
* \brief Implementation of the User class
* \author Abderrahmen Sallem
* \version 1.0
*/
#include "pch.h"  
#include "User.h"  

using namespace std;  
namespace Finance_Management
{

    /**
     * \brief Constructor for the User class
     * \param[in] p_userId User ID
     * \param[in] p_userName User name
     * \param[in] p_passwordHash Password hash
     * \param[in] p_email User email
     * \pre p_userId > 0
     * \pre p_userName is not empty
     * \pre p_passwordHash is not empty
     * \pre p_email is not empty
     * \post m_userId == p_userId
     * \post m_userName == p_userName
     * \post m_passwordHash == p_passwordHash
     * \post m_email == p_email
     */
    User::User(int p_userId, const std::string& p_userName, const std::string& p_passwordHash, const std::string& p_email)
        : m_userId(p_userId), m_userName(p_userName), m_passwordHash(p_passwordHash), m_email(p_email) {
        PRECONDITION(p_userId > 0);
        PRECONDITION(!p_userName.empty());
        PRECONDITION(!p_passwordHash.empty());
        PRECONDITION(!p_email.empty());

        POSTCONDITION(m_userId == p_userId);
        POSTCONDITION(m_userName == p_userName);
        POSTCONDITION(m_passwordHash == p_passwordHash);
        POSTCONDITION(m_email == p_email);

        INVARIANTS();
    }

    /**
    * \brief Copy constructor for the User class
    * \param[in] p_user User object to copy
    * \post m_userId == p_user.m_userId
    * \post m_userName == p_user.m_userName
    * \post m_passwordHash == p_user.m_passwordHash
    * \post m_email == p_user.m_email
    * \post m_accounts == p_user.m_accounts
    */
    User::User(const User& p_user)
        : m_userId(p_user.m_userId), m_userName(p_user.m_userName), m_passwordHash(p_user.m_passwordHash), m_email(p_user.m_email) {
		vector<unique_ptr<Account>>::const_iterator it;
        for (it = p_user.m_accounts.begin(); it != p_user.m_accounts.end(); ++it) 
        {
			m_accounts.push_back(make_unique<Account>(**it));
        }
        PRECONDITION(!p_user.m_email.empty());
        POSTCONDITION(m_userId == p_user.m_userId);
        POSTCONDITION(m_userName == p_user.m_userName);
        POSTCONDITION(m_passwordHash == p_user.m_passwordHash);
        POSTCONDITION(m_email == p_user.m_email);
        POSTCONDITION(m_accounts == p_user.m_accounts);
        INVARIANTS();
    }

    /**
    * \brief Destructor for the User class
    * \details Cleans up any resources used by the User object.
    * \post All dynamically allocated memory is released.
    */
    /**
    * \brief Destructor for the User class.
    * \details Cleans up any resources used by the User object.
    */
    User::~User() {
    }

    /**
    * \brief Gets the user ID.
    * \return The user ID.
    */
    int User::getUserId() const {
        return m_userId;
    }

    /**
    * \brief Gets the user name.
    * \return The user name.
    */
    const string& User::getUserName() const {
        return m_userName;
    }

    /**
    * \brief Gets the password hash.
    * \return The password hash.
    */
    const string& User::getPasswordHash() const {
        return m_passwordHash;
    }

    /**
    * \brief Gets the email address.
    * \return The email address.
    */
    const string& User::getEmail() const {
        return m_email;
    }

    /**
    * \brief Sets the user name.
    * \param[in] p_userName The new user name.
    * \pre p_userName is not empty.
    * \post m_userName == p_userName.
    */
    void User::setUserName(const string& p_userName) {
        m_userName = p_userName;
        PRECONDITION(!p_userName.empty());
        POSTCONDITION(m_userName == p_userName);
        INVARIANTS();
    }

    /**
    * \brief Sets the password hash.
    * \param[in] p_passwordHash The new password hash.
    * \pre p_passwordHash is not empty.
    * \post m_passwordHash == p_passwordHash.
    */
    void User::setPasswordHash(const string& p_passwordHash) {
        m_passwordHash = p_passwordHash;
        PRECONDITION(!p_passwordHash.empty());
        POSTCONDITION(m_passwordHash == p_passwordHash);
        INVARIANTS();
    }

    /**
    * \brief Sets the email address.
    * \param[in] p_email The new email address.
    * \pre p_email is not empty.
    * \post m_email == p_email.
    */
    void User::setEmail(const string& p_email) {
        m_email = p_email;
        PRECONDITION(!p_email.empty());
        POSTCONDITION(m_email == p_email);
        INVARIANTS();
    }

    /**
    * \brief Adds an account to the user.
    * \param[in] p_account The account to add.
    * \throws AccountAlreadyExistsException if the account already exists.
    */
    void User::addAccount(const Account& p_account) {
        if (!accountPresent(p_account.getAccountId())) {
            m_accounts.push_back(make_unique<Account>(p_account));
        }
        else {
            throw AccountAlreadyExistsException(p_account.getAccountId());
        }
    }

    /**
    * \brief Removes an account from the user.
    * \param[in] p_accountId The ID of the account to remove.
    * \throws AccountNotFoundException if the account does not exist.
    */
    void User::removeAccount(int p_accountId) {
        if (accountPresent(p_accountId)) {
            vector<unique_ptr<Account>>::iterator it;
            for (it = m_accounts.begin(); it != m_accounts.end(); ++it) {
                if ((*it)->getAccountId() == p_accountId) {
                    m_accounts.erase(it);
                    break;
                }
            }
        }
        else {
            throw AccountNotFoundException(p_accountId);
        }
    }

    /**
    * \brief Gets the list of accounts.
    * \return A constant reference to the vector of accounts.
    */
    const vector<unique_ptr<Account>>& User::getAccounts() const {
        return m_accounts;
    }

    /**
    * \brief Checks if an account is present.
    * \param[in] p_accountId The ID of the account to check.
    * \return True if the account is present, false otherwise.
    */
    bool User::accountPresent(int p_accountId) {
        for (const auto& account : m_accounts) {
            if (account->getAccountId() == p_accountId) {
                return true;
            }
        }
        return false;
    }

    /**
    * \brief Equality operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if the users are equal, false otherwise.
    */
    bool User::operator==(const User& p_user) const {
        return m_userId == p_user.m_userId;
    }

    /**
    * \brief Less-than operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if this user is less than the other user, false otherwise.
    */
    bool User::operator<(const User& p_user) const {
        return m_userId < p_user.m_userId;
    }

    /**
    * \brief Greater-than operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if this user is greater than the other user, false otherwise.
    */
    bool User::operator>(const User& p_user) const {
        return m_userId > p_user.m_userId;
    }

    /**
    * \brief Less-than-or-equal-to operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if this user is less than or equal to the other user, false otherwise.
    */
    bool User::operator<=(const User& p_user) const {
        return m_userId <= p_user.m_userId;
    }

    /**
    * \brief Greater-than-or-equal-to operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if this user is greater than or equal to the other user, false otherwise.
    */
    bool User::operator>=(const User& p_user) const {
        return m_userId >= p_user.m_userId;
    }

    /**
    * \brief Inequality operator for the User class.
    * \param[in] p_user The user to compare with.
    * \return True if the users are not equal, false otherwise.
    */
    bool User::operator!=(const User& p_user) const {
        return !(*this == p_user);
    }

    /**
    * \brief Verifies the class invariants.
    * \details This method can be used to ensure that the class invariants are maintained.
    */
    void User::verifieInvariant() const {
        INVARIANT(!m_userName.empty());
        INVARIANT(!m_passwordHash.empty());
        INVARIANT(!m_email.empty());
        INVARIANT(m_userId > 0);
    };

	/**
	* \brief Formats the user information as a string.
    * \return string
    */
    std::string User::userFormat() const 
    {
		ostringstream p_os;
		p_os << "User ID: " << m_userId << "\n"
			<< "User Name: " << m_userName << "\n"
			<< "Password Hash: " << m_passwordHash << "\n"
			<< "Email: " << m_email << "\n";
		return p_os.str();
    }
} //namespace Finance_Management