#include "phonebook.hpp"
#include <cstdlib>
PhoneBook::PhoneBook()
{
	count = 0;
	oldest_index = 0;
}

void PhoneBook::add_contact(Contact contact)
{
	if (count < 8)
	{
		arr_contact[count] = contact;
		count++;
	}
	else
	{
		arr_contact[oldest_index] = contact;
		oldest_index = (oldest_index + 1) % 8;
	}
}

void PhoneBook::print_contact_value(std::string string)
{
	if (string.length() > 10)
		std::cout << string.substr(0,9) + ".";
	else
	{
		std::cout << std::setw(10) << std::right << string;
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
		std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
		print_contact_value(arr_contact[i].get_first_name());
		std::cout << "|";
		print_contact_value(arr_contact[i].get_last_name());
		std::cout << "|";
		print_contact_value(arr_contact[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;

	if (count != 0)
	{
		while (true)
		{
			std::cout << "Select an index: ";
			getline(std::cin, s_index);
			if (s_index.empty())
				continue;
			index = std::atoi(s_index.c_str());
			if (std::cin.fail() || index < 1 || index > count)
			{
				std::cin.clear();
				std::cout << "Invalid index!" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "First Name" << " : " << arr_contact[index - 1].get_first_name() << std::endl;
		std::cout << "Last Name" << " : " << arr_contact[index - 1].get_last_name() << std::endl;
		std::cout << "Nickname" << " : " << arr_contact[index - 1].get_nickname() << std::endl;
		std::cout << "Phone Number" << " : " << arr_contact[index - 1].get_phone_number() << std::endl;
		std::cout << "Darkest Secret" << " : " << arr_contact[index - 1].get_darkest_secret() << std::endl;

	}

}