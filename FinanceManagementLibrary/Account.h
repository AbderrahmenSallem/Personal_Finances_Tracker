#pragma once
#include "pch.h"
namespace Finance_Management
{
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
}