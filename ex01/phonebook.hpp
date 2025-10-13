#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
private:
	int		count;
public:
	Contact arr_contact[8];

	void add_contact(Contact contact);

	void print_contact_value(std::string string);
	void search_contact();

	// void print_contacts()
	// {
	// 	for (int i = 0; i < count; i++) {
	// 	std::cout << i << ": " << arr_contact[i].get_first_name() << std::endl;
	// 	std::cout << i << ": " << arr_contact[i].get_last_name() << std::endl;
	// 	std::cout << i << ": " << arr_contact[i].get_nickname() << std::endl;
	// 	std::cout << i << ": " << arr_contact[i].get_phone_number() << std::endl;
	// 	std::cout << i << ": " << arr_contact[i].get_darkest_secret() << std::endl;
	// }
	// }
};

#endif