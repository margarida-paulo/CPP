#ifndef CAT
# define CAT

#include "WrongAnimal.hpp"
#include <iostream>

class Cat : public WrongAnimal{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound() const;
};

#endif
