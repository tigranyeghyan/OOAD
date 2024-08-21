#ifndef HEADER_H
#define HEADER_H

class User
{
	private:
		std::string m_email;
		std::string m_password;
		std::string m_fullname;
		// Setters for constructor
		void set_fullname();
		void set_email();
		void set_password();
		// Account Parameters Managment
		void change_password();
		void update_fullname();
                void update_email();
		// Security
		bool login();
		// Parameter syntax check
		bool is_email(std::string);
		bool is_password(std::string);
		bool is_fullname(std::string);
	public:
		// Constructors
		//User() = default;
		// Account Managment
		std::string get_email() const;
		void create_user();
		void change_user_parametres();
		void show_info() const;
};

#endif
