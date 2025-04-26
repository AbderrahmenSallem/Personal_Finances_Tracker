/**
* \file FinanceManagementExceptions.cpp
* \brief Implantation de la classe FinanceManagementExceptions et de ses héritiers
* \author Abderrahmen Sallem
* \version v1.0
* \date 2023-10-01
* \details
* Cette classe est utilisée pour gérer les exceptions liées à la gestion financière.
* Elle hérite de std::runtime_error et fournit des classes spécifiques pour différents types d'exceptions.
*/
#include "pch.h"
#include "FinanceManagementExceptions.h"

using namespace std;
using namespace Finance_Management;

/**
* \brief Constructeur de la classe de base FinanceManagementExceptions
 * \param message Message d'erreur
 *
 * Cette classe est la classe de base pour toutes les exceptions liées à la gestion financière.
 * Elle hérite de std::runtime_error.
*/
FinanceManagementExceptions::FinanceManagementExceptions(const string& message)
	: runtime_error(message) {
}

/**
* \brief Constructeur de la classe AccountNotFoundException
 * \param accountId Identifiant du compte
 *
 * Cette classe est utilisée pour signaler qu'un compte n'a pas été trouvé.
*/
AccountNotFoundException::AccountNotFoundException(int accountId)
	: FinanceManagementExceptions("Account with ID " + to_string(accountId) + " not found.") {
}

/**
* \brief Constructeur de la classe TransactionNotFoundException
 * \param transactionId Identifiant de la transaction
 *
 * Cette classe est utilisée pour signaler qu'une transaction n'a pas été trouvée.
*/
TransactionNotFoundException::TransactionNotFoundException(int transactionId)
	: FinanceManagementExceptions("Transaction with ID " + to_string(transactionId) + " not found.") {
}

/**
* \brief Constructeur de la classe AccountAlreadyExistsException
 * \param accountId Identifiant du compte
 *
 * Cette classe est utilisée pour signaler qu'un compte existe déjà.
*/
AccountAlreadyExistsException::AccountAlreadyExistsException(int accountId)
	: FinanceManagementExceptions("Account with ID " + to_string(accountId) + " already exists.") {
}
