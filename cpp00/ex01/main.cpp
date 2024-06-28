#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>

int main(void)
{
	PhoneBook 	contactList;
	std::string command;
	int		positionOfContact = 0;
	do {
		std::cout << "Insert a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> command;
		if(!command.compare("ADD")) {
			contactList.addContact(positionOfContact);
			if (positionOfContact <= 8)
				positionOfContact++;
		} else if (!command.compare("SEARCH")) {
			contactList.searchContacts(positionOfContact);
		} else if(command.compare("EXIT")) {
			std::cout << "COMMAND NOT FOUND" << std::endl;
		}
	} while (command.compare("EXIT"));
	return 0;
}
