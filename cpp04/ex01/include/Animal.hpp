#ifndef ANIMAL
# define ANIMAL

#include <string>
#include <iostream>

class Animal{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		virtual Animal &operator=(const Animal &other);
		virtual void makeSound() const;
		std::string getType() const;
};


#endif
