class Account
{
        private:
                int number;
                int balance;
                std::string name;
        public:
                //  Constructor and cp assignment operator
                Account();
		Account(std::string, int);
                Account& operator=(Account&) = default;
                // Disabling copy move constructors and move assignment operator
                Account(const Account&) = delete;
                Account(Account&&) = delete;
                Account& operator=(Account&&) = delete;
                // Managing Accounts
                void deposit(int);
                void withdraw(int);
                // Getter Setter functions for Display info
                int getbalance() const;
                std::string getname() const;
		int getnumber() const;
		void setname(std::string);
		void setnumber(int);
		void setbalance(int);
};


class Bank
{
	private:
		int capacity;
		int count;
		Account* accounts;

	public:
		// Constructor allocate memory for Accounts and copy ctor
		Bank(); 
		~Bank();
		// Disabling copy  move constructors and assignment operators
		Bank (const Bank&) = delete;
		Bank& operator=(const Bank&) = delete;
		Bank(Bank&&) = delete;
		Bank& operator=(Bank&&) = delete; 
		// Managing Accounts
		int createAccount();
		void Deposit(int, int);
		void Withdraw(int, int);
		void displayInfo(int);
};
