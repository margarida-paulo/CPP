#ifndef CAT
# define CAT

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public WrongAnimal{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound() const;
};

#endif
