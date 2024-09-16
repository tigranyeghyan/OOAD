//Transaction Manager

#pragma once

class TransactionManager
{
public:
	virtual void logTransaction(const std::string &, double) = 0;
	virtual void showTransactionHistory() const = 0;
};
