#include "../include/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog was created with the default constructor." << std::endl;
	type = std::string("Dog");
	brain = new Brain();
}

Dog::Dog(const Dog &other){
	std::cout << "Dog was created with a copy constructor." << std::endl;
	type = other.type;
	brain = other.brain;
}

Dog::~Dog(){
	std::cout << "Dog was destroyed!" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog was initialized with attributes of another dog." << std::endl;
	type = other.type;
	brain = other.brain;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "*Woof Woof*" << std::endl;
}
