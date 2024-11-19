#ifndef DOG
# define DOG

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal{
	private:
		Brain *brain;

	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);
		void makeSound() const;
};

#endif
