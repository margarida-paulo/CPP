#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << ("Default constructor called") << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &number){
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

/*For integers, we can directly shift the bits to get the fixed
point values*/
Fixed::Fixed(int const intValue){
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue  << _fracBits;
}

/*In the fixed point numbers, we move the dot all the way to the right
and leave only the integer part.
For example, in decimals, if we want 15.436 to turn into an integer, we
multiply by 10^3, getting 15436, with 3 fractional bits. In binary, we
multiply by 2^fractional_bits, to also get rid of the decimal part of
the number.

We cannot do it like with integers cause, for floats, bit shifting
doesn't work.
*/
Fixed::Fixed(float const floatValue){
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int> (roundf(floatValue * (1 << _fracBits)));
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed& Fixed::operator=(Fixed const &otherNumber){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherNumber)
		return *this;
	this->_value = otherNumber._value;
	return *this;
}


Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void)const{
	return (float)this->_value / (1 << _fracBits);
}

int Fixed::toInt(void) const{
	return this->_value >> _fracBits;
}

std::ostream& operator<<(std::ostream& osb, const Fixed& number){
	osb << number.toFloat();
	return (osb);
}

bool Fixed::operator>(Fixed const otherNumber) const{
	return this->_value > otherNumber._value;
}

bool Fixed::operator<(Fixed const otherNumber)const{
	return this->_value < otherNumber._value;
}

bool Fixed::operator>=(Fixed const otherNumber)const{
	return this->_value >= otherNumber._value;
}

bool Fixed::operator<=(Fixed const otherNumber)const{
	return this->_value <= otherNumber._value;
}

bool Fixed::operator==(Fixed const otherNumber)const{
	return this->_value == otherNumber._value;
}

bool Fixed::operator!=(Fixed const otherNumber)const{
	return this->_value != otherNumber._value;
}



Fixed Fixed::operator+(const Fixed otherNumber) const{
	Fixed newNumber;
	newNumber._value = this->_value + otherNumber._value;
	return newNumber;
}

Fixed Fixed::operator-(const Fixed otherNumber) const{
	Fixed newNumber;
	newNumber._value = this->_value - otherNumber._value;
	return newNumber;
}


Fixed Fixed::operator*(const Fixed otherNumber) const{
	Fixed newNumber;
	newNumber._value = ((this->_value * otherNumber._value) >> _fracBits);
	return newNumber;
}

Fixed Fixed::operator/(const Fixed otherNumber) const{
	Fixed newNumber;
	newNumber._value = ((this->_value <<_fracBits) / otherNumber._value);
	return newNumber;
}

//pre-incremento
Fixed& Fixed::operator++(void){
	this->_value++;
	return *this;
}

//pos-incremento
Fixed Fixed::operator++(int){
	Fixed incrementedNumber;
	incrementedNumber._value = this->_value;
	this->_value++;
	return incrementedNumber;
}

//pre-decremento
Fixed& Fixed::operator--(void){
	this->_value--;
	return *this;
}

//pos-decremento
Fixed Fixed::operator--(int){
	Fixed incrementedNumber;
	incrementedNumber._value = this->_value;
	this->_value--;
	return incrementedNumber;
}



Fixed & Fixed::min(Fixed &number1, Fixed &number2){
	return (number1._value < number2._value) ? number1 : number2;
}

Fixed &Fixed::min(Fixed const &number1, Fixed const &number2){
	return (number1._value < number2._value) ? const_cast<Fixed &>(number1) : const_cast<Fixed &>(number2);
}

Fixed &Fixed::max(Fixed &number1, Fixed &number2){
	return (number1._value > number2._value) ? number1 : number2;
}

Fixed &Fixed::max(Fixed const &number1, Fixed const &number2){
	return (number1._value > number2._value) ? const_cast<Fixed &>(number1) : const_cast<Fixed &>(number2);
}
