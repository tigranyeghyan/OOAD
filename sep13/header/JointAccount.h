//Joint Account

#pragma once
#include <vector>
#include "Account.h"

class JointAccount : public Account
{
public:
	void addCustomer(const std::string &);

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;
	

	JointAccount(const JointAccount &) = delete;
	JointAccount(JointAccount &&) = delete;
	JointAccount& operator=(const JointAccount &) = delete;
	JointAccount& operator=(JointAccount &&) = delete;
	~JointAccount() = default;

private:
	std::vector<std::string> jointOwners;

};
