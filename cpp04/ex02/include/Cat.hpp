#ifndef CAT
# define CAT

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &other);
		virtual ~Cat();
		Cat &operator=(const Cat &other);
		void makeSound() const;
		Brain *getBrain();
};

#endif
