#ifndef CONTACT
# define CONTACT

#include <string>
#include <iostream>
#include <algorithm> // For std::all_of
#include <cctype>    // For std::isdigit

class Contact {
	public:
		Contact(void);
		~Contact(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		void 		setFirstName(std::string firstName);
		void 		setLastName(std::string lastName);
		void 		setNickname(std::string nickname);
		void 		setPhoneNumber(std::string phoneNumber);
		void 		setDarkestSecret(std::string darkestSecret);
		int			getIndex(void);
		void		increaseIndex(int i);
		void		setIndex(int i);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int			_index;
};

#endif
