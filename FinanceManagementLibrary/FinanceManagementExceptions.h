/**
    /**  
    * \file   FinanceManagementExceptions.h contenant la d�claration de la classe FinanceManagementExceptions et de ses h�ritiers  
    * \brief  Hi�rarchie de classe pour la gestion des erreurs dans le syst�me de gestion financi�re  
    *  
    * Ces classes constituent la hi�rarchie pour la gestion des  
    * exceptions sp�cifiques au domaine de la gestion financi�re.  
    * Elles maintiennent les donn�es n�cessaires � la sauvegarde des  
    * renseignements de l'erreur. Cette classe et sa hi�rarchie sont  
    * utilis�es pour signaler des erreurs sp�cifiques au domaine.  
    *  
    * En release, d�finir la constante NDEBUG pour d�sactiver les Macros  
    *  
    * <pre>  
    * Classes:  
    * std::runtime_error             Classe de base des exceptions d'ex�cution  
    * FinanceManagementExceptions:   Classe de base des exceptions de gestion financi�re.  
    * AccountNotFoundException:      Classe de gestion des erreurs de compte introuvable.  
    * TransactionNotFoundException:  Classe de gestion des erreurs de transaction introuvable.  
    * AccountAlreadyExistsException: Classe de gestion des erreurs de compte d�j� existant.  
    *  
    * Attributs:  
    *      std::string  m_message: Le message d'erreur d�crivant le probl�me.  
    * </pre>  
    *  
    * \note  Cette hi�rarchie de classe est inspir�e des meilleures pratiques  
    * pour la gestion des exceptions dans les syst�mes financiers.  
    *  
    * \author Abderrahmen, Sallem
    * \version V1.0 r�vis�e balises Doxygen C++ normes  
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


