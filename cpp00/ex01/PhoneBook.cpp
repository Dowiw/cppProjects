#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook(void)
{
	next_time = 0;
	total_saved = 0;
}

void	PhoneBook::saveContact(const Contact &add)
{
	contacts[next_time] = add;
	next_time = (next_time + 1) % 8;
	if (total_saved < 8)
		total_saved++;
}

void	PhoneBook::printBook(void)
{
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|index     |first_name|last_name |nickname  |\n";
	std::cout << "+----------+----------+----------+----------+\n";
	if (total_saved == 0)
		std::cout << "| Nothing to show...                        |\n";
	else
	{
		for (int i = 0; i < total_saved; i++)
		{
			std::cout << "|" << std::setw(10) << i << "|";
			if (contacts[i].getFirstName().length() > 10)
				std::cout << contacts[i].getFirstName().substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
			if (contacts[i].getLastName().length() > 10)
				std::cout << contacts[i].getLastName().substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << contacts[i].getLastName() << "|";
			if (contacts[i].getNickName().length() > 10)
				std::cout << contacts[i].getNickName().substr(0, 9) << ".|\n";
			else
				std::cout << std::setw(10) << contacts[i].getNickName() << "|\n";
		}
	}
	std::cout << "+----------+----------+----------+----------+\n\n";
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= this->total_saved)
	{
		std::cout << "No contact found at index " << index << ".\n";
		return ;
	}
	std::cout << "\nFirst Name: " << contacts[index].getFirstName() << "\n";
	std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[index].getNickName() << "\n";
	std::cout << "Phone Number: " << contacts[index].getPhoneNum() << "\n";
	std::cout << "Darkest Secret: " << contacts[index].getDarkSecret() << "\n"
	<< "\n";
}

const int &PhoneBook::getTotalSaved(void) const
{
	return (this->total_saved);
}

