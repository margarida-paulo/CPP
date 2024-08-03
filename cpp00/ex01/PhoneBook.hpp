#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#ifndef NCONTACTS
#define NCONTACTS 8
#endif

class PhoneBook {
	public:
	Contact contacts[NCONTACTS];
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(int position);
	void searchContacts(int position);
	Contact *findContactByIndex(int index, int position);
	void printNChars(std::string toPrint, long unsigned int n);
	void getValidInput(std::string prompt, std::string &toStore, bool isPhone);
	bool validatePhoneNumber(std::string phoneNumber, bool isPhone);

};

#endif
