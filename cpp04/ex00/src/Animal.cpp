#include "../include/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal was created with the default constructor." << std::endl;
	type = std::string("Animal");
}

Animal::Animal(const Animal &other){
	std::cout << "Animal was created with a copy constructor." << std::endl;
	type = other.type;
}

Animal::~Animal(){
	std::cout << "Animal was destroyed!" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal was initialized with attributes of another Animal." << std::endl;
	type = other.type;
	return *this;
}

std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << "*I am having an existencial crisis, I don't know what animal I am, so I don't know what sound to make...*" << std::endl;
}
