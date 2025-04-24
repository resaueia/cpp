#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	void set_first_name(std::string str);
	std::string get_first_name();
	void set_last_name(std::string str);
	std::string get_last_name();
	void set_nickname(std::string str);
	std::string get_nickname();
	void set_phone_number(std::string str);
	std::string get_phone_number();
	void set_darkest_secret(std::string str);
	std::string get_darkest_secret();
};

class Phonebook
{
  private:
	Contact contacts[8];
	int total_contacts;

  public:
	Phonebook(); // C++ initializes automatically, but this is a good practice
	void add_contact();
	void show_table();
	void show_contact();
};

#endif