#ifndef HEADER_H
#define HEADER_H

class Bank
{
	private;
		//Data Members
		std::vector<Account> accounts;
		bool already_used(std::string);
                bool log_in(std::string, std::string, int&);
	public:
		//Constructors and Operations
		Bank() = default;
		Bank(const Bank&) = delete;
		Bank(Bank&&) = delete;
		Bank& operator=(const Bank&) = delete;
		Bank& operator=(Bank&&) = delete;
		//Destructor
		~Bank() = default;
		//Account managment
		void createAccount();
		void deleteAccount();
		void changeAccountSettings();
		//Get account info
		void displayAccountDetails();
		void loadAccountDetails();
		void displayTransactionHistory();
		void loadTransactionHistory();	
		//Balance Managment actions
		void checkAccountBalance();
		void DepositToAccount();
		void WithdrawFromAccount();
		void TransferToAnotherAccount();
};

class Account
{
	private:
		//Data Members
		std::string username;
		std::string name;
		std::string lastname;
		std::string password;
		//status Basic 1
		//Status Advanced 2
		//Status Enterprice 3
		int status_id;
		int number;
		double balance;
		std::vector<std::vector<std::string>> transaction_history; 
		// Constructors and Operations
		Account() = default;
		Account(const Account&) = delete;
                Account(Account&&) = delete;
                Account& operator=(const Account&) = delete;
                Account& operator=(Account&&) = delete;
		//Destructor
		~Account() = default;
		//For Account Editing
		void set_username(std::string);
		void set_name(std::string);
		void set_lastname(std::string);
		void set_password(std::string);
		void set_number(int);
		//Change Account status
		void change_status(int);
		//Get Account Information
		std::string get_name() const;
		std::string get_lastname() const;
		std::string get_username() const;
		double get_balance() const;
		std::string get_status() const;
		int get_number() const;
		//Actions for transaction history
		void add_action(std::string);
		std::vector<std::string>& get_transaction_history() const;
		//Deposits and WithDraws
		void Deposit(double);
	       	double WithDraw(double);
	public:
		friend class Bank;
}

bool is_username(std::string);
bool is_name(std::string);
bool is_password(std::string);

#endif
