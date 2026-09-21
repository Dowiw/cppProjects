#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int next_time;
	int total_saved;
public:
	PhoneBook(void);
	void saveContact(const Contact &add);
	void printBook(void);
	void displayContact(int index) const;

	const int &getTotalSaved(void) const;

};

#endif
