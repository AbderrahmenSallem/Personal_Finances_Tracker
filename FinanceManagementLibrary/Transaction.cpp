#include "Transaction.h"
#include "pch.h"

using namespace std;
using namespace util;

Finance_Management::Transaction::Transaction(int p_transactionId, const util::Date& p_date, const string& p_description,
	double p_amount, const string& p_transactionType, const string& p_category)
	: m_transactionId(p_transactionId), m_date(p_date), m_description(p_description),
	m_amount(p_amount), m_transactionType(p_transactionType), m_category(p_category)
{
	PRECONDITION(p_transactionId > 0);
	PRECONDITION(!p_description.empty());
	PRECONDITION(p_amount != 0);
	PRECONDITION(!p_transactionType.empty());
	PRECONDITION(!p_category.empty());
	POSTCONDITION(m_transactionId == p_transactionId);
	POSTCONDITION(m_date == p_date);
	POSTCONDITION(m_description == p_description);
	POSTCONDITION(m_amount == p_amount);
	POSTCONDITION(m_transactionType == p_transactionType);
	POSTCONDITION(m_category == p_category);
	INVARIANTS();
}
Finance_Management::Transaction::Transaction(const Transaction& p_transaction)
	: m_transactionId(p_transaction.m_transactionId), m_date(p_transaction.m_date),
	m_description(p_transaction.m_description), m_amount(p_transaction.m_amount),
	m_transactionType(p_transaction.m_transactionType), m_category(p_transaction.m_category)
{
	PRECONDITION(p_transaction.m_transactionId > 0);
	PRECONDITION(!p_transaction.m_description.empty());
	PRECONDITION(p_transaction.m_amount != 0);
	PRECONDITION(!p_transaction.m_transactionType.empty());
	PRECONDITION(!p_transaction.m_category.empty());
	POSTCONDITION(m_transactionId == p_transaction.m_transactionId);
	POSTCONDITION(m_date == p_transaction.m_date);
	POSTCONDITION(m_description == p_transaction.m_description);
	POSTCONDITION(m_amount == p_transaction.m_amount);
	POSTCONDITION(m_transactionType == p_transaction.m_transactionType);
	POSTCONDITION(m_category == p_transaction.m_category);
	INVARIANTS();
}
Finance_Management::Transaction::~Transaction()
{
	// Destructor
}
int Finance_Management::Transaction::reqTransactionId() const
{
	return m_transactionId;
}
const util::Date& Finance_Management::Transaction::reqDate() const
{
	return m_date;
}
const string& Finance_Management::Transaction::reqDescription() const
{
	return m_description;
}
double Finance_Management::Transaction::reqamount() const
{
	return m_amount;
}
const string& Finance_Management::Transaction::reqTransactionType() const
{
	return m_transactionType;
}
const string& Finance_Management::Transaction::reqCategory() const
{
	return m_category;
}
void Finance_Management::Transaction::asgDescription(const string& p_description)
{
	m_description = p_description;
	PRECONDITION(!p_description.empty());
	POSTCONDITION(m_description == p_description);
	INVARIANTS();
}
void Finance_Management::Transaction::asgamount(double p_amount)
{
	m_amount = p_amount;
	PRECONDITION(p_amount != 0);
	POSTCONDITION(m_amount == p_amount);
	INVARIANTS();
}
void Finance_Management::Transaction::asgTransactionType(const string& p_transactionType)
{
	m_transactionType = p_transactionType;
	PRECONDITION(!p_transactionType.empty());
	POSTCONDITION(m_transactionType == p_transactionType);
	INVARIANTS();
}
void Finance_Management::Transaction::asgCategory(const string& p_category)
{
	m_category = p_category;
	PRECONDITION(!p_category.empty());
	POSTCONDITION(m_category == p_category);
	INVARIANTS();
}
bool Finance_Management::Transaction::operator==(const Transaction& p_transaction) const
{
	return (m_transactionId == p_transaction.m_transactionId);
}
bool Finance_Management::Transaction::operator<(const Transaction& p_transaction) const
{
	return (m_transactionId < p_transaction.m_transactionId);
}
bool Finance_Management::Transaction::operator>(const Transaction& p_transaction) const
{
	return (m_transactionId > p_transaction.m_transactionId);
}
bool Finance_Management::Transaction::operator<=(const Transaction& p_transaction) const
{
	return (m_transactionId <= p_transaction.m_transactionId);
}
bool Finance_Management::Transaction::operator>=(const Transaction& p_transaction) const
{
	return (m_transactionId >= p_transaction.m_transactionId);
}
bool Finance_Management::Transaction::operator!=(const Transaction& p_transaction) const
{
	return (m_transactionId != p_transaction.m_transactionId);
}
ostream& Finance_Management::operator<<(ostream& p_os, const Transaction& p_transaction)
{
	p_os << "Transaction ID: " << p_transaction.m_transactionId << "\n"
		<< "Date: " << p_transaction.m_date << "\n"
		<< "Description: " << p_transaction.m_description << "\n"
		<< "Amount: " << p_transaction.m_amount << "\n"
		<< "Transaction Type: " << p_transaction.m_transactionType << "\n"
		<< "Category: " << p_transaction.m_category;
	return p_os;
}
void Finance_Management::Transaction::verifieInvariant() const
{
	INVARIANT(m_transactionId > 0);
	INVARIANT(!m_description.empty());
	INVARIANT(m_amount != 0);
	INVARIANT(!m_transactionType.empty());
	INVARIANT(!m_category.empty());
}
