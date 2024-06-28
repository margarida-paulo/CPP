#ifndef CONTACT
#define CONTACT

#include <string>
#include <iostream>

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
