#include "../include/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog was created with the default constructor." << std::endl;
	type = std::string("Dog");
	brain = new Brain();
}

Dog::Dog(const Dog &other){
	std::cout << "Dog was created with a copy constructor." << std::endl;
	type = other.type;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(other.brain->getIdea(i), i);
}

Dog::~Dog(){
	std::cout << "Dog was destroyed!" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog was initialized with attributes of another dog." << std::endl;
	type = other.type;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i), i);
	return *this;
}

void Dog::makeSound() const{
	std::cout << "*Woof Woof*" << std::endl;
}

Brain *Dog::getBrain(){
	return brain;
}
