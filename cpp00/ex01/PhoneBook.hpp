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
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(int position);
	void searchContacts(int position);

	private:
	Contact contacts[NCONTACTS];
	Contact *findContactByIndex(int index, int position);
	void printNChars(std::string toPrint, long unsigned int n);
	std::string getValidInput(std::string prompt, bool isPhone);
	bool validatePhoneNumber(std::string phoneNumber, bool isPhone);

};

#endif
