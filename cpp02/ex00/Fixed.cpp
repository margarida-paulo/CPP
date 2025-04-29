#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << ("Default constructor called") << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &number){
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed& Fixed::operator=(Fixed const &otherNumber){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherNumber)
		return *this;
	this->_value = otherNumber.getRawBits();
	return *this;
}


Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
