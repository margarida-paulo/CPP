#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Phone Book was created" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phone Book was destroyed" << std::endl;
}

void PhoneBook::printNChars(std::string toPrint, long unsigned int n){
	if (toPrint.length() > n) {
		std::cout << toPrint.substr(0, n - 1) << ".";
	} else
		std::cout << std::right << std::setw(10) << toPrint;
}

bool PhoneBook::validatePhoneNumber(std::string phoneNumber, bool isPhone){
	if (!isPhone)
		return true;
	int i = phoneNumber[0] && phoneNumber[0] == '+' ? 1 : 0;
	if (!phoneNumber[i])
	{
		std::cout << "Invalid phone number! Insert again:" << std::endl;
		return false;
	}
	while (phoneNumber[i]) {
		if (!std::isdigit(phoneNumber[i++])){
			std::cout << "Invalid phone number! Insert again:" << std::endl;
			return false;
		}
	}
	return true;
}

std::string PhoneBook::getValidInput(std::string prompt, bool isPhone){
	std::string input;
	std::cout << prompt << std::endl;
	do{
		std::getline(std::cin, input);
	}
	while(!std::cin.eof() && (!validatePhoneNumber(input, isPhone) || input.length() == 0));
	if (std::cin.eof()){
		std::cout << std::endl << "End of file was reached! Exiting program" << std::endl;
		exit(1);
	}
	return (input);
}

void PhoneBook::addContact(int position){

	Contact *currentContact;

	if (position >= NCONTACTS)
	{
		for(int i = 0; i < NCONTACTS - 1; i++) {
			this->contacts[i] = this->contacts[i + 1];
			this->contacts[i].increaseIndex(-1);
		}
		currentContact = &this->contacts[NCONTACTS - 1];
	} else {
		currentContact = &this->contacts[position];
		currentContact->setIndex(position);
	}

	currentContact->setFirstName(getValidInput("Insert your first name:", false));
	currentContact->setLastName(getValidInput("Insert your last name:", false));
	currentContact->setNickname(getValidInput("Insert your nickname:", false));
	currentContact->setPhoneNumber(getValidInput("Insert your phone number:", true));
	currentContact->setDarkestSecret(getValidInput("Insert your darkest secret:", false));
	std::cout << "Contact added successfully :)" << std::endl << std::endl;
}

Contact *PhoneBook::findContactByIndex(int index, int position){
	for (int i = 0; i < position; i++) {
		if (this->contacts[i].getIndex() == index)
			return &(this->contacts[i]);
	}
	return &(this->contacts[0]);
}


void PhoneBook::searchContacts(int position){

	int index;

	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	for(int i = 0; i < position; i++){
		std::cout << std::right << std::setw(10) << this->contacts[i].getIndex() << "|";
		printNChars(this->contacts[i].getFirstName(), 10);
		std::cout << "|";
		printNChars(this->contacts[i].getLastName(), 10);
		std::cout << "|";
		printNChars(this->contacts[i].getNickname(), 10);
		std::cout << std::endl;
	}
	std::cout << "Insert the index of the contact to check:" << std::endl;

	if (!(std::cin >> index) || index < 0 || index >= position || index >= NCONTACTS) {
		std::cout << "There is no contact with this index." << std::endl;
		if (std::cin.eof()){
			std::cout << std::endl << "End of file was reached! Exiting program" << std::endl;
			exit(1);
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return;
	} else {
		if (std::cin.eof()){
			std::cout << std::endl << "End of file was reached! Exiting program" << std::endl;
			exit(1);
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		Contact *currentContact = findContactByIndex(index, position);
		std::cout << "Index: " << currentContact->getIndex() << std::endl;
		std::cout << "First Name: " << currentContact->getFirstName() << std::endl;
		std::cout << "Last Name: " << currentContact->getLastName() << std::endl;
		std::cout << "Nickname: " << currentContact->getNickname() << std::endl;
		std::cout << "Phone Number: " << currentContact->getPhoneNumber() << std::endl;
		std::cout << "DARKEST SECRET: " << currentContact->getDarkestSecret() << std::endl << std::endl;
	}
}
