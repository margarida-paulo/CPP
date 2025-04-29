#include "../include/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat was created with the default constructor." << std::endl;
	type = std::string("Cat");
}

Cat::Cat(const Cat &other){
	std::cout << "Cat was created with a copy constructor." << std::endl;
	type = other.type;
}

Cat::~Cat(){
	std::cout << "Cat was destroyed!" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat was initialized with attributes of another cat." << std::endl;
	type = other.type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "*Meow Meow*" << std::endl;
}
