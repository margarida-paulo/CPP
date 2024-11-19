#include "../include/WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat was created with the default constructor." << std::endl;
	type = std::string("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other){
	std::cout << "WrongCat was created with a copy constructor." << std::endl;
	type = other.type;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat was destroyed!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "WrongCat was initialized with attributes of another WrongCat." << std::endl;
	type = other.type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "*Meow Meow*" << std::endl;
}
