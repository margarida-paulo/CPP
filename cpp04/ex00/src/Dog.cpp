#include "../include/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog was created with the default constructor." << std::endl;
	type = std::string("Dog");
}

Dog::Dog(const Dog &other){
	std::cout << "Dog was created with a copy constructor." << std::endl;
	type = other.type;
}

Dog::~Dog(){
	std::cout << "Dog was destroyed!" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog was initialized with attributes of another dog." << std::endl;
	type = other.type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "*Woof Woof*" << std::endl;
}
