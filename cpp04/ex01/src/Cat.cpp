#include "../include/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat was created with the default constructor." << std::endl;
	type = std::string("Cat");
	brain = new Brain();
}

Cat::Cat(const Cat &other){
	std::cout << "Cat was created with a copy constructor." << std::endl;
	type = other.type;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(other.brain->getIdea(i), i);
}

Cat::~Cat(){
	std::cout << "Cat was destroyed!" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat was initialized with attributes of another cat." << std::endl;
	type = other.type;
	if (this != &other){
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(other.brain->getIdea(i), i);
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "*Meow Meow*" << std::endl;
}

Brain *Cat::getBrain(){
	return brain;
}
