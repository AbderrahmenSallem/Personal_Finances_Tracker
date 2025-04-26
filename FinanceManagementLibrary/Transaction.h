#pragma once
#include "pch.h"
#include <string>
#include <sstream>

namespace Finance_Management
{
	class Transaction
	{
	public:
		Transaction(int p_transactionId, const util::Date& p_date, const std::string& p_description,
			double p_amount, const std::string& p_transactionType, const std::string& p_category);
		Transaction(const Transaction& p_transaction);
		~Transaction();
		int reqTransactionId() const;
		const util::Date& reqDate() const;
		const std::string& reqDescription() const;
		double reqamount() const;
		const std::string& reqTransactionType() const;
		const std::string& reqCategory() const;
		void asgDescription(const std::string& p_description);
		void asgamount(double p_amount);
		void asgTransactionType(const std::string& p_transactionType);
		void asgCategory(const std::string& p_category);
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
}

