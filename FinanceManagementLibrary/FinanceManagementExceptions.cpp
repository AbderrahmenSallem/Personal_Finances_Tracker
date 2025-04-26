/**
* \file FinanceManagementExceptions.cpp
* \brief Implantation de la classe FinanceManagementExceptions et de ses h�ritiers
* \author Abderrahmen Sallem
* \version v1.0
* \date 2023-10-01
* \details
* Cette classe est utilis�e pour g�rer les exceptions li�es � la gestion financi�re.
* Elle h�rite de std::runtime_error et fournit des classes sp�cifiques pour diff�rents types d'exceptions.
*/
#include "pch.h"
#include "FinanceManagementExceptions.h"

using namespace std;
using namespace Finance_Management;

/**
* \brief Constructeur de la classe de base FinanceManagementExceptions
 * \param message Message d'erreur
 *
 * Cette classe est la classe de base pour toutes les exceptions li�es � la gestion financi�re.
 * Elle h�rite de std::runtime_error.
*/
FinanceManagementExceptions::FinanceManagementExceptions(const string& message)
	: runtime_error(message) {
}

/**
* \brief Constructeur de la classe AccountNotFoundException
 * \param accountId Identifiant du compte
 *
 * Cette classe est utilis�e pour signaler qu'un compte n'a pas �t� trouv�.
*/
AccountNotFoundException::AccountNotFoundException(int accountId)
	: FinanceManagementExceptions("Account with ID " + to_string(accountId) + " not found.") {
}

/**
* \brief Constructeur de la classe TransactionNotFoundException
 * \param transactionId Identifiant de la transaction
 *
 * Cette classe est utilis�e pour signaler qu'une transaction n'a pas �t� trouv�e.
*/
TransactionNotFoundException::TransactionNotFoundException(int transactionId)
	: FinanceManagementExceptions("Transaction with ID " + to_string(transactionId) + " not found.") {
}

/**
* \brief Constructeur de la classe AccountAlreadyExistsException
 * \param accountId Identifiant du compte
 *
 * Cette classe est utilis�e pour signaler qu'un compte existe d�j�.
*/
AccountAlreadyExistsException::AccountAlreadyExistsException(int accountId)
	: FinanceManagementExceptions("Account with ID " + to_string(accountId) + " already exists.") {
}
