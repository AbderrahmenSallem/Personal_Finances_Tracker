/**  
* \file Transaction.cpp  
* \brief Implementation of the Transaction class  
* \author Abderrahmen Sallem  
* \version 1.0  
*/  
#include "pch.h"  

using namespace std;  
using namespace util;  
namespace Finance_Management  
{  
  /**  
  * \brief Constructor for the Transaction class  
  * \param[in] p_transactionId Transaction ID  
  * \param[in] p_date Transaction date  
  * \param[in] p_description Transaction description  
  * \param[in] p_amount Transaction amount  
  * \param[in] p_transactionType Transaction type  
  * \param[in] p_category Transaction category  
  * \pre p_transactionId > 0  
  * \pre p_amount >= 0  
  * \pre !p_description.empty()  
  * \pre !p_transactionType.empty()  
  * \pre !p_category.empty()  
  * \post m_transactionId == p_transactionId  
  * \post m_date == p_date  
  * \post m_description == p_description  
  * \post m_amount == p_amount  
  * \post m_transactionType == p_transactionType  
  * \post m_category == p_category  
  */  
  Transaction::Transaction(int p_transactionId, const Date& p_date, const string& p_description,  
      double p_amount, const string& p_transactionType, const string& p_category)  
      : m_transactionId(p_transactionId), m_date(p_date), m_description(p_description),  
      m_amount(p_amount), m_transactionType(p_transactionType), m_category(p_category) {  
      PRECONDITION(p_transactionId > 0);  
      PRECONDITION(p_amount >= 0);  
      PRECONDITION(!p_description.empty());  
      PRECONDITION(!p_transactionType.empty());  
      PRECONDITION(!p_category.empty());  
      POSTCONDITION(m_transactionId == p_transactionId);  
      POSTCONDITION(m_date == p_date);  
      POSTCONDITION(m_description == p_description);  
      POSTCONDITION(m_amount == p_amount);  
      POSTCONDITION(m_transactionType == p_transactionType);  
      POSTCONDITION(m_category == p_category);  
      verifieInvariant();  
  }  

  /**  
  * \brief Copy constructor for the Transaction class  
  * \param[in] p_transaction Transaction object to copy  
  * \post All attributes are copied from p_transaction  
  */  
  Transaction::Transaction(const Transaction& p_transaction)  
      : m_transactionId(p_transaction.m_transactionId), m_date(p_transaction.m_date),  
      m_description(p_transaction.m_description), m_amount(p_transaction.m_amount),  
      m_transactionType(p_transaction.m_transactionType), m_category(p_transaction.m_category) {  
      verifieInvariant();  
  }  

  /**  
  * \brief Destructor for the Transaction class  
  */  
  Transaction::~Transaction() {  
  }  

  /**  
  * \brief Retrieves the transaction ID  
  * \return The transaction ID  
  */  
  int Transaction::getTransactionId() const {  
      return m_transactionId;  
  }  

  /**  
  * \brief Retrieves the transaction date  
  * \return The transaction date  
  */  
  const Date& Transaction::getDate() const {  
      return m_date;  
  }  

  /**  
  * \brief Retrieves the transaction description  
  * \return The transaction description  
  */  
  const string& Transaction::getDescription() const {  
      return m_description;  
  }  

  /**  
  * \brief Retrieves the transaction amount  
  * \return The transaction amount  
  */  
  double Transaction::getAmount() const {  
      return m_amount;  
  }  

  /**  
  * \brief Retrieves the transaction type  
  * \return The transaction type  
  */  
  const string& Transaction::getTransactionType() const {  
      return m_transactionType;  
  }  

  /**  
  * \brief Retrieves the transaction category  
  * \return The transaction category  
  */  
  const string& Transaction::getCategory() const {  
      return m_category;  
  }  

  /**  
  * \brief Assigns a new description to the transaction  
  * \param[in] p_description The new description  
  * \pre !p_description.empty()  
  * \post m_description == p_description  
  */  
  void Transaction::setDescription(const string& p_description) {  
      PRECONDITION(!p_description.empty());  
      m_description = p_description;  
      POSTCONDITION(m_description == p_description);  
      verifieInvariant();  
  }  

  /**  
  * \brief Assigns a new amount to the transaction  
  * \param[in] p_amount The new amount  
  * \pre p_amount >= 0  
  * \post m_amount == p_amount  
  */  
  void Transaction::setAmount(double p_amount) {  
      PRECONDITION(p_amount >= 0);  
      m_amount = p_amount;  
      POSTCONDITION(m_amount == p_amount);  
      verifieInvariant();  
  }  

  /**  
  * \brief Assigns a new transaction type  
  * \param[in] p_transactionType The new transaction type  
  * \pre !p_transactionType.empty()  
  * \post m_transactionType == p_transactionType  
  */  
  void Transaction::setTransactionType(const string& p_transactionType) {  
      PRECONDITION(!p_transactionType.empty());  
      m_transactionType = p_transactionType;  
      POSTCONDITION(m_transactionType == p_transactionType);  
      verifieInvariant();  
  }  

  /**  
  * \brief Assigns a new category to the transaction  
  * \param[in] p_category The new category  
  * \pre !p_category.empty()  
  * \post m_category == p_category  
  */  
  void Transaction::setCategory(const string& p_category) {  
      PRECONDITION(!p_category.empty());  
      m_category = p_category;  
      POSTCONDITION(m_category == p_category);  
      verifieInvariant();  
  }  

  /**  
  * \brief Equality operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if the transactions are equal, false otherwise  
  */  
  bool Transaction::operator==(const Transaction& p_transaction) const {  
      return m_transactionId == p_transaction.m_transactionId;  
  }  

  /**  
  * \brief Less-than operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if this transaction is less than the other, false otherwise  
  */  
  bool Transaction::operator<(const Transaction& p_transaction) const {  
      return m_transactionId < p_transaction.m_transactionId;  
  }  

  /**  
  * \brief Greater-than operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if this transaction is greater than the other, false otherwise  
  */  
  bool Transaction::operator>(const Transaction& p_transaction) const {  
      return m_transactionId > p_transaction.m_transactionId;  
  }  

  /**  
  * \brief Less-than-or-equal-to operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if this transaction is less than or equal to the other, false otherwise  
  */  
  bool Transaction::operator<=(const Transaction& p_transaction) const {  
      return m_transactionId <= p_transaction.m_transactionId;  
  }  

  /**  
  * \brief Greater-than-or-equal-to operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if this transaction is greater than or equal to the other, false otherwise  
  */  
  bool Transaction::operator>=(const Transaction& p_transaction) const {  
      return m_transactionId >= p_transaction.m_transactionId;  
  }  

  /**  
  * \brief Inequality operator for comparing two transactions  
  * \param[in] p_transaction The transaction to compare with  
  * \return True if the transactions are not equal, false otherwise  
  */  
  bool Transaction::operator!=(const Transaction& p_transaction) const {  
      return !(*this == p_transaction);  
  }  

  /**  
  * \brief Stream insertion operator for displaying a transaction  
  * \param[in,out] p_os The output stream  
  * \param[in] p_transaction The transaction to display  
  * \return The output stream  
  */  
  ostream& operator<<(ostream& p_os, const Transaction& p_transaction) {  
      p_os << "Transaction ID: " << p_transaction.m_transactionId << ", Date: " << p_transaction.m_date.reqDateFormatee()  
           << ", Description: " << p_transaction.m_description << ", Amount: " << p_transaction.m_amount  
           << ", Type: " << p_transaction.m_transactionType << ", Category: " << p_transaction.m_category;  
      return p_os;  
  }  

  /**  
  * \brief Verifies the class invariants  
  * \pre None  
  * \post The class invariants are satisfied  
  */  
  void Transaction::verifieInvariant() const {  
      INVARIANT(m_transactionId > 0);  
      INVARIANT(m_amount >= 0);  
      INVARIANT(!m_description.empty());  
      INVARIANT(!m_transactionType.empty());  
      INVARIANT(!m_category.empty());  
  }  
} // namespace Finance_Management
