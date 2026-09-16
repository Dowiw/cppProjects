#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

class Contact {
private:
	string darkest_secret;
	time_t creation_time;
public:
	string first_name;
	string last_name;
	string nickname;
	string phone_num;

	Contact(void)
	{
		darkest_secret = "";
		first_name = "";
		last_name = "";
		nickname = "";
		phone_num = "";
		creation_time = 0;
	}

	Contact(string first, string last, string nick, string phone, string secret)
	{
		first_name = first;
		last_name = last;
		nickname = nick;
		phone_num = phone;
		darkest_secret = secret;
		creation_time = time(NULL);
	}

	time_t get_time(void)
	{
		return (creation_time);
	}
};

class PhoneBook {
private:
	Contact contacts[8];
	int used;
public:
	PhoneBook(void)
	{
		used = 0;
	}

	/**
	 * 
	 */
	void	save_contact(Contact add)
	{
		int oldest_i = 0;
		time_t oldest_time = add.get_time();

		if (used == 8)
		{
			for (int i = 0; i < used; i++)
			{
				time_t curr = contacts[i].get_time();
				if (curr < oldest_time)
				{
					oldest_i = i;
					oldest_time = curr;
				}
			}
			contacts[oldest_i] = add;
		}
		else
		{
			contacts[used] = add;
			used++;
		}
	}

	void	print_book(void)
	{
		cout << "|index     |first_name|last_name |nickname  |\n";
		cout << "+----------+----------+----------+----------+\n";
		
		if (used == 0)
			cout << "| Nothing to show...                        |\n";
		else
		{
			for (int i = 0; i < used; i++)
			{
				cout << "|" << to_string(i) << setw(10) << "|";

				if (contacts[i].first_name.length() > 10)
					cout << contacts[i].first_name.substr(0, 9) << ".|";
				else
					cout << setw(10) << contacts[i].first_name << "|";

				if (contacts[i].last_name.length() > 10)
					cout << contacts[i].last_name.substr(0, 9) << ".|";
				else
					cout << setw(10) << contacts[i].last_name << "|";

				if (contacts[i].nickname.length() > 10)
					cout << contacts[i].nickname.substr(0, 9) << ".|\n";
				else
					cout << setw(10) << contacts[i].nickname << "|\n";
			}
		}
		cout << "+----------+----------+----------+----------+\n\n";
	}
};

int	main(void)
{
	PhoneBook phonebook;
	Contact c = Contact("John", "Doe", "Johnny Dfdffsdfoe", "3438094803243", "No Secret");

	phonebook.print_book();
	phonebook.save_contact(c);
	phonebook.print_book();
	return (0);
}