#include <iostream>
#include "../header/Transaction.h"
#include "../header/Account.h"


Transaction::Transaction(Account *from, Account *to, double amount, const std::string& type) : m_fromAccount {from}, m_toAccount{to}, m_amount {amount}, m_transactionType {type} { }

void Transaction::log() const
{
	if (m_fromAccount != nullptr) std::cout << "From Account --> " << m_fromAccount -> getAccountType() << std::endl;
	if (m_toAccount != nullptr) std::cout << "To Account --> " << m_toAccount -> getAccountType() << std::endl;
	std::cout << "Amount of Transaction --> " << m_amount << std::endl;
	std::cout << "Transaction Type --> " << m_transactionType << std::endl;
}
