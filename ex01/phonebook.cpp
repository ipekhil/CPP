#include <iostream>
#include <string>
#include "contact.cpp"

class PhoneBook
{
private:
	int		count;
public:
	Contact arr_contact[8];

	void add_contact(Contact contact)
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

	void print_contact_value(std::string string)
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

	void search_contact()
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
};


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

int main(int argc, char **argv)
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
			std::cout << "invalid command" << std::endl;
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