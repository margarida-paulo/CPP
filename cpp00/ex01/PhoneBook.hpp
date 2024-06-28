#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
	public:
	Contact contacts[8];
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(int position);
	void searchContacts(int position);
	Contact *findContactByIndex(int index, int position);
};

#endif
