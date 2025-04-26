/**  
* \file Account.h  
* \brief File containing the interface of the Account class used for managing and manipulating financial accounts.  
* \author Abderrahmen Sallem  
* \version 1.0  
*/
#pragma once
#include "pch.h"
namespace Finance_Management
{
	/**
	* \class Account
	* \brief This class is used for managing and manipulating financial accounts.
	*
	*        The class maintains a consistent state for account information.
	*        It validates the data assigned to it.
	*        This class can be used to represent various types of accounts,
	*        perform operations such as comparisons, and manage account details.
	*        The class ensures that the account data is valid, and it is the
	*        responsibility of the user to provide valid input.
	* \invariant The validity of the account data can be ensured by using the
	*            provided setter methods and verifying the state of the object.
	*/
	class Account
	{
	public:
		Account(int p_accountId, const std::string& p_accountName, const std::string& p_accountType,
			double p_balance, const std::string& p_currency);
		Account(const Account& p_account);
		~Account();
		int getAccountId() const;
		const std::string& getAccountName() const;
		const std::string& getAccountType() const;
		double getBalance() const;
		const std::string& getCurrency() const;
		void setAccountName(const std::string& p_accountName);
		void setAccountType(const std::string& p_accountType);
		void setBalance(double p_balance);
		void setCurrency(const std::string& p_currency);
		bool operator==(const Account& p_account) const;
		bool operator<(const Account& p_account) const;
		bool operator>(const Account& p_account) const;
		bool operator<=(const Account& p_account) const;
		bool operator>=(const Account& p_account) const;
		bool operator!=(const Account& p_account) const;
		friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
		void verifieInvariant() const;
	private:
		int m_accountId;
		std::string m_accountName;
		std::string m_accountType;
		double m_balance;
		std::string m_currency;
	};
} // namespace Finance_Management