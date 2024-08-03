#ifndef CONTACT
#define CONTACT

#include <string>
#include <iostream>
#include <algorithm> // For std::all_of
#include <cctype>    // For std::isdigit

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		int			index;
		Contact(void);
		~Contact(void);
};

#endif
