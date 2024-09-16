#include <iostream>
#include "../header/Transaction.h"


Transaction::Transaction(Account *from, Account *to, double amount, const std::string& type) : m_fromAccount {from}, m_toAccount{to}, m_amount {amount}, m_transactionType {type} { }

void Transaction::log() const
{
	if (fromAccount != nullptr) std::cout << "From Account --> " << fromAccount -> getAccountType() << std::endl;
	if (toAccount != nullptr) std::cout << "To Account --> " << toAccount -> getAccountType() << std::endl;
	std::cout << "Amount of Transaction --> " << amount << std::endl;
	std::cout << "Transaction Type --> " << transactionType << std::endl;
}
