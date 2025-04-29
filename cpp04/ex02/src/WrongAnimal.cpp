#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal was created with the default constructor." << std::endl;
	type = std::string("WrongAnimal");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "WrongAnimal was created with a copy constructor." << std::endl;
	type = other.type;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal was destroyed!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "WrongAnimal was initialized with attributes of another WrongAnimal." << std::endl;
	type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound() const{
	std::cout << "I am having an existencial crisis, I don't know what WrongAnimal I am, so I don't know what sound to make..." << std::endl;
}
