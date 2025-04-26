#include "pch.h"
#include "Account.h"

Finance_Management::Account::Account(int p_accountId, const std::string& p_accountName, const std::string& p_accountType,
	double p_balance, const std::string& p_currency)
	: m_accountId(p_accountId), m_accountName(p_accountName), m_accountType(p_accountType),
	m_balance(p_balance), m_currency(p_currency)
{
	PRECONDITION(p_accountId > 0);
	PRECONDITION(!p_accountName.empty());
	PRECONDITION(!p_accountType.empty());
	PRECONDITION(!p_currency.empty());

	POSTCONDITION(m_accountId == p_accountId);
	POSTCONDITION(m_accountName == p_accountName);
	POSTCONDITION(m_accountType == p_accountType);
	POSTCONDITION(m_balance == p_balance);
	POSTCONDITION(m_currency == p_currency);
	INVARIANTS();
}
Finance_Management::Account::Account(const Account& p_account)
	: m_accountId(p_account.m_accountId), m_accountName(p_account.m_accountName),
	m_accountType(p_account.m_accountType), m_balance(p_account.m_balance),
	m_currency(p_account.m_currency)
{
	POSTCONDITION(m_accountId == p_account.m_accountId);
	POSTCONDITION(m_accountName == p_account.m_accountName);
	POSTCONDITION(m_accountType == p_account.m_accountType);
	POSTCONDITION(m_balance == p_account.m_balance);
	POSTCONDITION(m_currency == p_account.m_currency);

	INVARIANTS();
}
Finance_Management::Account::~Account()
{
	// Destructor
}
int Finance_Management::Account::getAccountId() const
{
	return m_accountId;
}
const std::string& Finance_Management::Account::getAccountName() const
{
	return m_accountName;
}
const std::string& Finance_Management::Account::getAccountType() const
{
	return m_accountType;
}
double Finance_Management::Account::getBalance() const
{
	return m_balance;
}
const std::string& Finance_Management::Account::getCurrency() const
{
	return m_currency;
}
void Finance_Management::Account::setAccountName(const std::string& p_accountName)
{
	PRECONDITION(!p_accountName.empty());
	POSTCONDITION(m_accountName == p_accountName);
	m_accountName = p_accountName;
	INVARIANTS();
}
void Finance_Management::Account::setAccountType(const std::string& p_accountType)
{
	PRECONDITION(!p_accountType.empty());
	POSTCONDITION(m_accountType == p_accountType);
	m_accountType = p_accountType;
	INVARIANTS();
}
void Finance_Management::Account::setBalance(double p_balance)
{
	m_balance = p_balance;
}
void Finance_Management::Account::setCurrency(const std::string& p_currency)
{
	PRECONDITION(!p_currency.empty());
	POSTCONDITION(m_currency == p_currency);
	m_currency = p_currency;
	INVARIANTS();
}
bool Finance_Management::Account::operator==(const Account& p_account) const
{
	return m_accountId == p_account.m_accountId;
}
bool Finance_Management::Account::operator<(const Account& p_account) const
{
	return m_accountId < p_account.m_accountId;
}
bool Finance_Management::Account::operator>(const Account& p_account) const
{
	return m_accountId > p_account.m_accountId;
}
bool Finance_Management::Account::operator<=(const Account& p_account) const
{
	return m_accountId <= p_account.m_accountId;
}
bool Finance_Management::Account::operator>=(const Account& p_account) const
{
	return m_accountId >= p_account.m_accountId;
}
bool Finance_Management::Account::operator!=(const Account& p_account) const
{
	return m_accountId != p_account.m_accountId;
}
std::ostream& Finance_Management::operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "Account ID: " << p_account.getAccountId() << "\n"
		<< "Account Name: " << p_account.getAccountName() << "\n"
		<< "Account Type: " << p_account.getAccountType() << "\n"
		<< "Balance: " << p_account.getBalance() << "\n"
		<< "Currency: " << p_account.getCurrency() << "\n";
	return p_os;
}
void Finance_Management::Account::verifieInvariant() const
{
	INVARIANT(m_accountId > 0);
	INVARIANT(!m_accountName.empty());
	INVARIANT(!m_accountType.empty());
	INVARIANT(!m_currency.empty());
}