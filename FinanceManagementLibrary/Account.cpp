/**  
* \file Account.cpp  
* \brief Implementation of the Account class  
* \author Abderrahmen Sallem  
* \version 1.0  
*/  
#include "pch.h"  
#include "Account.h"  

using namespace std;
namespace Finance_Management {  

   /**  
   * \brief Constructor for the Account class  
   * \param[in] p_accountId Account ID  
   * \param[in] p_accountName Account name  
   * \param[in] p_accountType Account type  
   * \param[in] p_balance Account balance  
   * \param[in] p_currency Account currency  
   * \pre p_accountId > 0  
   * \pre p_accountName is not empty  
   * \pre p_accountType is not empty  
   * \pre p_currency is not empty  
   * \post m_accountId == p_accountId  
   * \post m_accountName == p_accountName  
   * \post m_accountType == p_accountType  
   * \post m_balance == p_balance  
   * \post m_currency == p_currency  
   */  
   Account::Account(int p_accountId, const std::string& p_accountName, const std::string& p_accountType,
       double p_balance, const std::string& p_currency)
       : m_accountId(p_accountId), m_accountName(p_accountName), m_accountType(p_accountType),  
         m_balance(p_balance), m_currency(p_currency) {  
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

   /**  
   * \brief Copy constructor for the Account class  
   * \param[in] p_account Account object to copy  
   * \post m_accountId == p_account.m_accountId  
   * \post m_accountName == p_account.m_accountName  
   * \post m_accountType == p_account.m_accountType  
   * \post m_balance == p_account.m_balance  
   * \post m_currency == p_account.m_currency  
   */  
   Account::Account(const Account& p_account)  
       : m_accountId(p_account.m_accountId), m_accountName(p_account.m_accountName),  
         m_accountType(p_account.m_accountType), m_balance(p_account.m_balance),  
         m_currency(p_account.m_currency) {  
       POSTCONDITION(m_accountId == p_account.m_accountId);  
       POSTCONDITION(m_accountName == p_account.m_accountName);  
       POSTCONDITION(m_accountType == p_account.m_accountType);  
       POSTCONDITION(m_balance == p_account.m_balance);  
       POSTCONDITION(m_currency == p_account.m_currency);  
       INVARIANTS();  
   }  

   /**  
   * \brief Destructor for the Account class  
   * \details Cleans up any resources used by the Account object.  
   */  
   Account::~Account() {  
   }  

   /**  
   * \brief Gets the account ID.  
   * \return The account ID.  
   */  
   int Account::getAccountId() const {  
       return m_accountId;  
   }  

   /**  
   * \brief Gets the account name.  
   * \return The account name.  
   */  
   const string& Account::getAccountName() const {  
       return m_accountName;  
   }  

   /**  
   * \brief Gets the account type.  
   * \return The account type.  
   */  
   const string& Account::getAccountType() const {  
       return m_accountType;  
   }  

   /**  
   * \brief Gets the account balance.  
   * \return The account balance.  
   */  
   double Account::getBalance() const {  
       return m_balance;  
   }  

   /**  
   * \brief Gets the account currency.  
   * \return The account currency.  
   */  
   const string& Account::getCurrency() const {  
       return m_currency;  
   }  

   /**  
   * \brief Sets the account name.  
   * \param[in] p_accountName The new account name.  
   * \pre p_accountName is not empty.  
   * \post m_accountName == p_accountName.  
   */  
   void Account::setAccountName(const string& p_accountName) {  
       PRECONDITION(!p_accountName.empty());  
       m_accountName = p_accountName;  
       POSTCONDITION(m_accountName == p_accountName);  
       INVARIANTS();  
   }  

   /**  
   * \brief Sets the account type.  
   * \param[in] p_accountType The new account type.  
   * \pre p_accountType is not empty.  
   * \post m_accountType == p_accountType.  
   */  
   void Account::setAccountType(const string& p_accountType) {  
       PRECONDITION(!p_accountType.empty());  
       m_accountType = p_accountType;  
       POSTCONDITION(m_accountType == p_accountType);  
       INVARIANTS();  
   }  

   /**  
   * \brief Sets the account balance.  
   * \param[in] p_balance The new account balance.  
   */  
   void Account::setBalance(double p_balance) {  
       m_balance = p_balance;  
   }  

   /**  
   * \brief Sets the account currency.  
   * \param[in] p_currency The new account currency.  
   * \pre p_currency is not empty.  
   * \post m_currency == p_currency.  
   */  
   void Account::setCurrency(const string& p_currency) {  
       PRECONDITION(!p_currency.empty());  
       m_currency = p_currency;  
       POSTCONDITION(m_currency == p_currency);  
       INVARIANTS();  
   }  

   /**  
   * \brief Equality operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if the accounts are equal, false otherwise.  
   */  
   bool Account::operator==(const Account& p_account) const {  
       return m_accountId == p_account.m_accountId;  
   }  

   /**  
   * \brief Less-than operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if this account is less than the other account, false otherwise.  
   */  
   bool Account::operator<(const Account& p_account) const {  
       return m_accountId < p_account.m_accountId;  
   }  

   /**  
   * \brief Greater-than operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if this account is greater than the other account, false otherwise.  
   */  
   bool Account::operator>(const Account& p_account) const {  
       return m_accountId > p_account.m_accountId;  
   }  

   /**  
   * \brief Less-than-or-equal-to operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if this account is less than or equal to the other account, false otherwise.  
   */  
   bool Account::operator<=(const Account& p_account) const {  
       return m_accountId <= p_account.m_accountId;  
   }  

   /**  
   * \brief Greater-than-or-equal-to operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if this account is greater than or equal to the other account, false otherwise.  
   */  
   bool Account::operator>=(const Account& p_account) const {  
       return m_accountId >= p_account.m_accountId;  
   }  

   /**  
   * \brief Inequality operator for the Account class.  
   * \param[in] p_account The account to compare with.  
   * \return True if the accounts are not equal, false otherwise.  
   */  
   bool Account::operator!=(const Account& p_account) const {  
       return m_accountId != p_account.m_accountId;  
   }  

   /**  
   * \brief Stream insertion operator for the Account class.  
   * \param[in] p_os The output stream.  
   * \param[in] p_account The account to output.  
   * \return The output stream.  
   */  
   ostream& operator<<(ostream& p_os, const Account& p_account) {  
       p_os << "Account ID: " << p_account.getAccountId() << "\n"  
            << "Account Name: " << p_account.getAccountName() << "\n"  
            << "Account Type: " << p_account.getAccountType() << "\n"  
            << "Balance: " << p_account.getBalance() << "\n"  
            << "Currency: " << p_account.getCurrency() << "\n";  
       return p_os;  
   }

   /**
   * \brief Formats the account information as a string.
   * \return a string.
   */
   std::string Account::accountFormat() const 
   {
       ostringstream p_os;
       p_os << "Account ID: " << m_accountId << "\n"
           << "Account Name: " << m_accountName << "\n"
           << "Account Type: " << m_accountType << "\n"
           << "Balance: " << m_balance << "\n"
           << "Currency: " << m_currency << "\n";
       return p_os.str();
   }

   /**  
   * \brief Verifies the class invariants.  
   * \details This method ensures that the class invariants are maintained.  
   */  
   void Account::verifieInvariant() const {  
       INVARIANT(m_accountId > 0);  
       INVARIANT(!m_accountName.empty());  
       INVARIANT(!m_accountType.empty());  
       INVARIANT(!m_currency.empty());  
   }  

} // namespace Finance_Management