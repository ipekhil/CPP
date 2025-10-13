#include <iostream>
#include <string>
#include "phonebook.hpp"

Contact get_input()
{
	Contact newcontact;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	while (true)
	{
		std::cout << "Enter First Name: ";
		getline(std::cin, first_name);
		if (first_name == "")
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		newcontact.set_first_name(first_name);
		break ;
	}
	while (true)
	{
		std::cout << "Enter Last Name: ";
		getline(std::cin, last_name);
		if (last_name == "")
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		newcontact.set_last_name(last_name);
		break ;
	}
	while (true)
	{
		std::cout << "Enter Nickname: ";
		getline(std::cin, nickname);
		if (nickname == "")
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		newcontact.set_nickname(nickname);
		break ;
	}
	while (true)
	{	
		std::cout << "Enter Phone Number:";
		getline(std::cin, phone_number);
		if (phone_number == "")
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		newcontact.set_phone_number(phone_number);
		break ;
	}
	while (true)
	{
		std::cout << "Enter Darkest Secret:";
		getline(std::cin, darkest_secret);
		if (darkest_secret == "")
		{
			std::cout << "Field cannot be empty!" << std::endl;
			continue;
		}
		newcontact.set_darkest_secret(darkest_secret);
		break ;
	}

	return newcontact;	
}

int main()
{

	Contact newcontact;
	PhoneBook phoneBook;
	while (true)
	{
		std::string input;
		
		std::cout << "Enter a command : " ;
		getline(std::cin, input);
		if (input == "ADD")
		{
			newcontact = get_input();

			phoneBook.add_contact(newcontact);
			//phoneBook.print_contacts();
		}
		else if (input == "SEARCH")
			phoneBook.search_contact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "invalid Command!" << std::endl;
	}

	// Contact contact1;
	// Contact contact2;
	// Contact contact3;
	// Contact contact4;
	// Contact contact5;
	// contact1.set_first_name("HİLAL");
	// contact1.set_last_name("ipek");
	// contact1.set_nickname("ipekhil");
	// contact1.set_phone_number("5345522270");
	// contact1.set_darkest_secret("secret");

	// phoneBook.add_contact(contact1);

	// contact2.set_first_name("TUĞBA");
	// contact2.set_last_name("ipek");
	// contact2.set_nickname("ipekhil");
	// contact2.set_phone_number("5345522270");
	// contact2.set_darkest_secret("secret");

	// phoneBook.add_contact(contact2);

	// contact3.set_first_name("ENGİN");
	// contact3.set_last_name("ipek");
	// contact3.set_nickname("ipekhil");
	// contact3.set_phone_number("5345522270");
	// contact3.set_darkest_secret("secret");

	// phoneBook.add_contact(contact3);


	// contact4.set_first_name("YUSUF");
	// contact4.set_last_name("ipek");
	// contact4.set_nickname("ipekhil");
	// contact4.set_phone_number("5345522270");
	// contact4.set_darkest_secret("secret");

	// phoneBook.add_contact(contact4);

	// contact5.set_first_name("ESMA");
	// contact5.set_last_name("ipek");
	// contact5.set_nickname("ipekhil");
	// contact5.set_phone_number("5345522270");
	// contact5.set_darkest_secret("secret");

	// phoneBook.add_contact(contact5);
}