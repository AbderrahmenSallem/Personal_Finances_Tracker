/**  
* \file Transaction.h  
* \brief File containing the declaration of the Transaction class for managing financial transactions.  
* \author Abderrahmen Sallem  
* \version 1.0  
*/  
#pragma once  
#include "pch.h"  
#include <string>  
#include <sstream>  

namespace Finance_Management  
{  
/**  
* \class Transaction  
* \brief This class is used for managing financial transactions.  
*  
*        The class maintains transaction information in a consistent state.  
*        It provides methods to access and modify transaction details such as  
*        transaction ID, date, description, amount, type, and category.  
*  
* \invariant The class ensures that the transaction data remains valid and consistent.  
*            The validity of the transaction data can be verified using the  
*            verifieInvariant() method.  
*/  
class Transaction  
{  
public:  
Transaction(int p_transactionId, const util::Date& p_date, const std::string& p_description,  
	double p_amount, const std::string& p_transactionType, const std::string& p_category);  
Transaction(const Transaction& p_transaction);  
~Transaction();  
int getTransactionId() const;  
const util::Date& getDate() const;  
const std::string& getDescription() const;  
double getAmount() const;  
const std::string& getTransactionType() const;  
const std::string& getCategory() const;  
void setDescription(const std::string& p_description);  
void setAmount(double p_amount);  
void setTransactionType(const std::string& p_transactionType);  
void setCategory(const std::string& p_category);  
bool operator==(const Transaction& p_transaction) const;  
bool operator<(const Transaction& p_transaction) const;  
bool operator>(const Transaction& p_transaction) const;  
bool operator<=(const Transaction& p_transaction) const;  
bool operator>=(const Transaction& p_transaction) const;  
bool operator!=(const Transaction& p_transaction) const;  
friend std::ostream& operator<<(std::ostream& p_os, const Transaction& p_transaction);  
private:  
int m_transactionId;  
util::Date m_date;  
std::string m_description;  
double m_amount;  
std::string m_transactionType;  
std::string m_category;  
void verifieInvariant() const;  
};  
} // namespace Finance_Management
