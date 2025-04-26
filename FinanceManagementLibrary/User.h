/**
* \file User.cpp
* \brief File containing the implementation of the User class for managing user data and accounts.
* \author Abderrahmen Sallem
* \version 1.0
*/
#pragma once
#include "pch.h"
#include "Account.h"
namespace Finance_Management
    /**  
    * \class User  
    * \brief This class is used for managing user data and accounts.  
    *  
    *        The class maintains user information in a consistent state.  
    *        It provides methods to access and modify user details such as  
    *        username, password hash, and email. Additionally, it allows  
    *        managing associated accounts by adding, removing, and verifying  
    *        the presence of accounts.  
    *  
    * \invariant The class ensures that the user data remains valid and consistent.  
    *            The validity of the user data can be verified using the  
    *            verifieInvariant() method.  
    */
{
	class User
	{
	public:
		User(int p_userId, const std::string& p_userName, const std::string& p_passwordHash, const std::string& p_email);
		User(const User& p_user);
		~User();
		int getUserId() const;
		const std::string& getUserName() const;
		const std::string& getPasswordHash() const;
		const std::string& getEmail() const;
		void setUserName(const std::string& p_userName);
		void setPasswordHash(const std::string& p_passwordHash);
		void setEmail(const std::string& p_email);
		void addAccount(const Account& p_account);
		void removeAccount(int p_accountId);
		bool accountPresent(int p_accountId);
		bool operator==(const User& p_user) const;
		bool operator<(const User& p_user) const;
		bool operator>(const User& p_user) const;
		bool operator<=(const User& p_user) const;
		bool operator>=(const User& p_user) const;
		bool operator!=(const User& p_user) const;
		const std::vector<std::unique_ptr<Account>>& getAccounts() const;
		void verifieInvariant() const;

	private:
		int m_userId;
		std::string m_userName;
		std::string m_passwordHash;
		std::string m_email;
		std::vector<std::unique_ptr<Account>> m_accounts;
	};
} // namespace Finance_Management
