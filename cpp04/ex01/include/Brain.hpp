#ifndef BRAIN
# define BRAIN

#include <iostream>

class Brain{
	private:
		std::string *ideas;

	public:
		Brain();
		Brain(Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
};

#endif
