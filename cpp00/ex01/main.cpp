#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

/**
 * @brief Checks if the string is all digits.
 * Phone numbers are usually structurized as all numbers,
 * or ones with the plus on front to define country.
 */
bool check_nums(const std::string &str)
{
	std::string::size_type i = 0;

	if (str[i] == '+')
		i++;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Checks if the string is all spaces.
 */
bool check_space(const std::string &str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if the string is a valid input.
 */
std::string get_valid_input(const std::string &prompt, bool is_numeric)
{
	std::string input;

	while (1)
	{
		std::cout << prompt;

		// EOF
		if (!std::getline(std::cin, input))
			return ("");

		// just null
		if (input.empty())
			continue ;

		// all spaces
		if (check_space(input))
		{
			std::cout << "String cannot be all spaces.\n";
			continue ;
		}

		if (is_numeric)
		{
			if (!check_nums(input))
			{
				std::cout << "Phone number cannot use the alphabet.\n";
				continue ;
			}
		}
		return (input);
	}
}

void add_contact(PhoneBook &phonebook)
{
	Contact new_contact;
	std::string input;

	input = get_valid_input("Enter first name: ", false);
	if (input.empty()) return ;
	new_contact.setFirstName(input);

	input = get_valid_input("Enter last name: ", false);
	if (input.empty()) return ;
	new_contact.setLastName(input);

	input = get_valid_input("Enter nickname: ", false);
	if (input.empty()) return ;
	new_contact.setNickName(input);

	input = get_valid_input("Enter phone number: ", true);
	if (input.empty()) return ;
	new_contact.setPhoneNum(input);

	input = get_valid_input("Enter darkest secret: ", false);
	if (input.empty()) return ;
	new_contact.setDarkestSecret(input);

	phonebook.saveContact(new_contact);
	std::cout << "Contact saved successfully!\n";
}

void search_contact(PhoneBook &phonebook)
{
	std::string input;
	int index;

	if (phonebook.getTotalSaved() <= 0)
	{
		std::cout << "There are no saved contacts.\n";
		return ;
	}
	while (1)
	{
		std::cout << "Enter the index of the contact to display: ";
		if (!std::getline(std::cin, input))
			return ;
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			index = input[0] - '0';
			phonebook.displayContact(index);
			return ;
		}
		else
			std::cout << "Invalid index. Only between 0 and 7.\n";
	}
}

int	main(void)
{
	PhoneBook phonebook;
	std::string option;

	std::cout << "Welcome to your phonebook!\n";
	while (1)
	{
		phonebook.printBook();
		std::cout << "Actions. please enter the keyowrds exactly.\n"
		<< "ADD: to add a contact.\n"
		<< "SEARCH: to find and display contact information.\n"
		<< "EXIT: to exit.\n"
		<< "What would you like to do? ";
		if (!std::getline(std::cin, option) || std::cin.eof())
		{
			std::cout << "\nExiting with EOF.\n";
			break ;
		}
		if (option == "EXIT")
		{
			std::cout << "Exiting.\n\n";
			break ;
		}
		else if (option == "ADD")
			add_contact(phonebook);
		else if (option == "SEARCH")
			search_contact(phonebook);
		else
			std::cout << "Invalid input.\n\n";
	}
	return (0);
}
