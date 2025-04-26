/**
    /**  
    * \file   FinanceManagementExceptions.h contenant la déclaration de la classe FinanceManagementExceptions et de ses héritiers  
    * \brief  Hiérarchie de classe pour la gestion des erreurs dans le système de gestion financière  
    *  
    * Ces classes constituent la hiérarchie pour la gestion des  
    * exceptions spécifiques au domaine de la gestion financière.  
    * Elles maintiennent les données nécessaires à la sauvegarde des  
    * renseignements de l'erreur. Cette classe et sa hiérarchie sont  
    * utilisées pour signaler des erreurs spécifiques au domaine.  
    *  
    * En release, définir la constante NDEBUG pour désactiver les Macros  
    *  
    * <pre>  
    * Classes:  
    * std::runtime_error             Classe de base des exceptions d'exécution  
    * FinanceManagementExceptions:   Classe de base des exceptions de gestion financière.  
    * AccountNotFoundException:      Classe de gestion des erreurs de compte introuvable.  
    * TransactionNotFoundException:  Classe de gestion des erreurs de transaction introuvable.  
    * AccountAlreadyExistsException: Classe de gestion des erreurs de compte déjà existant.  
    *  
    * Attributs:  
    *      std::string  m_message: Le message d'erreur décrivant le problème.  
    * </pre>  
    *  
    * \note  Cette hiérarchie de classe est inspirée des meilleures pratiques  
    * pour la gestion des exceptions dans les systèmes financiers.  
    *  
    * \author Abderrahmen, Sallem
    * \version V1.0 révisée balises Doxygen C++ normes  
    */
#pragma once
#include "pch.h"
class FinanceManagementExceptions : public std::runtime_error
{
public:
    explicit FinanceManagementExceptions(const std::string& message);
};

class AccountNotFoundException : public FinanceManagementExceptions
{
public:
    AccountNotFoundException(int accountId);
};

class TransactionNotFoundException : public FinanceManagementExceptions
{
public:
    TransactionNotFoundException(int transactionId);
};

class AccountAlreadyExistsException : public FinanceManagementExceptions
{
public:
    AccountAlreadyExistsException(int accountId);
};


