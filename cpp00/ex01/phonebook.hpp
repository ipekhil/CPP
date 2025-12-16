#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

class PhoneBook
{
private:
	int		count;
	Contact arr_contact[8];
public:
	PhoneBook();
	void add_contact(Contact contact);
	void print_contact_value(std::string string);
	void search_contact();
};

#endif