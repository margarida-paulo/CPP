#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Phone Book was created" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phone Book was destroyed" << std::endl;
}

void PhoneBook::addContact(int position){

	Contact *currentContact;

	if (position >= 9)
	{
		for(int i = 0; i < 8; i++) {
			this->contacts[i] = this->contacts[i + 1];
			this->contacts[i].index--;
		}
		currentContact = &this->contacts[8];
	} else {
		currentContact = &this->contacts[position];
		currentContact->index = position;
	}

	std::cout << "Insert your first name:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, currentContact->firstName);
	std::cout << "Insert your last name:" << std::endl;
	std::getline(std::cin, currentContact->lastName);
	std::cout << "Insert your nickname:" << std::endl;
	std::getline(std::cin, currentContact->nickname);
	std::cout << "Insert your phone number:" << std::endl;
	std::getline(std::cin, currentContact->phoneNumber);
	std::cout << "Insert your darkest secret:" << std::endl;
	std::getline(std::cin, currentContact->darkestSecret);
	std::cout << "Contact added successfully :)" << std::endl << std::endl;
}

Contact *PhoneBook::findContactByIndex(int index, int position){
	for (int i = 0; i < position; i++) {
		if (this->contacts[i].index == index)
			return &(this->contacts[i]);
	}
	return &(this->contacts[0]);
}

void PhoneBook::searchContacts(int position){

	int	index;

	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	for(int i = 0; i < position; i++){
		std::cout << std::right << std::setw(10) << this->contacts[i].index << "|";
		if (this->contacts[i].firstName.length() > 10) {
			for(int a = 0; a < 9; a++) {
				std::cout << this->contacts[i].firstName[a];
			}
			std::cout << ".|";
		} else
			std::cout << std::right << std::setw(10) << this->contacts[i].firstName << "|";

		if (this->contacts[i].lastName.length() > 10) {
			for(int a = 0; a < 9; a++) {
				std::cout << this->contacts[i].lastName[a];
			}
			std::cout << ".|";
		} else
			std::cout << std::right << std::setw(10) << this->contacts[i].lastName << "|";

		if (this->contacts[i].nickname.length() > 10) {
			for(int a = 0; a < 9; a++) {
				std::cout << this->contacts[i].nickname[a];
			}
			std::cout << "." << std::endl;
		} else
		std::cout << std::right << std::setw(10) << this->contacts[i].nickname << std::endl;
	}
	std::cout << "Insert the index of the contact to check:" << std::endl;
	std::cin >> index;
	if (std::cin.fail() || index >= position || index >= 9) {
		std::cout << "There is no contact with this index." << std::endl;
		return ;
	} else {
		Contact *currentContact = findContactByIndex(index, position);
		std::cout << "Index: " << currentContact->index << std::endl;
		std::cout << "First Name: " << currentContact->firstName << std::endl;
		std::cout << "Last Name: " << currentContact->lastName << std::endl;
		std::cout << "Nickname: " << currentContact->nickname << std::endl;
		std::cout << "DARKEST SECRET: " << currentContact->darkestSecret << std::endl << std::endl;
	}

}
