#include <iostream>
#include <string>
#include "phonebook.hpp"

Contact arr_contact[8];

void PhoneBook::add_contact(Contact contact)
{
	if (count < 8)
	{
		// arr_contact[count].set_first_name(contact.get_first_name());
		// arr_contact[count].set_last_name(contact.get_last_name());
		// arr_contact[count].set_nickname(contact.get_nickname());
		// arr_contact[count].set_phone_number(contact.get_phone_number());
		// arr_contact[count].set_darkest_secret(contact.get_darkest_secret());
		arr_contact[count] = contact;
		count++;
	}
	else
	{
		int i;			
		for (i = 0; i < 7; i++)
		{
			arr_contact[i] = arr_contact[i + 1];
		}
		arr_contact[i] = contact;
	}
}

void PhoneBook::print_contact_value(std::string string)
{
	int space;

	if (string.length() > 10)
		std::cout << string.substr(0,9) + ".";
	else
	{
		space = 10 - string.length();
		for (int i = 0; i < space; i++)
			std::cout << " ";
		std::cout << string;
	}
}

void PhoneBook::search_contact()
{
	std::string	s_index;
	int			index;

	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|" << "     Index" << "|" << "First Name" << "|" << " Last Name" << "|" << "  Nickname" << "|" << std::endl;
	std::cout << "|" << "----------" << "|" << "----------" << "|" << "----------" << "|" << "----------" << "|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << "         " << i + 1 << "|";
		print_contact_value(arr_contact[i].get_first_name());
		std::cout << "|";
		print_contact_value(arr_contact[i].get_last_name());
		std::cout << "|";
		print_contact_value(arr_contact[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;
	while (true)
	{
		std::cout << "Select an index : ";
		std::cin >> index;
		if (std::cin.fail() || index < 1 || index > count)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		break;
	}
	std::cin.ignore(1000, '\n');
	std::cout << "First Name" << " : " << arr_contact[index - 1].get_first_name() << std::endl;
	std::cout << "Last Name" << " : " << arr_contact[index - 1].get_last_name() << std::endl;
	std::cout << "Nickname" << " : " << arr_contact[index - 1].get_nickname() << std::endl;
	std::cout << "Phone Number" << " : " << arr_contact[index - 1].get_phone_number() << std::endl;
	std::cout << "Darkest Secret" << " : " << arr_contact[index - 1].get_darkest_secret() << std::endl;

}

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
