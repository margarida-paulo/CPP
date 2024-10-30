#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()){
	//std::cout << "The default constructor was called" << std::endl;
}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)){
	//std::cout << "The floats constructor was called" << std::endl;
}

Point::Point(Point &point) : _x(point._x), _y(point._y){
	//std::cout << "The copy constructor was called" << std::endl;
}


Point& Point::operator=(Point &point){
	// The subject makes it mandatory, but since there are only const
	// attributes, there is nothing this operator can do.
	(void)point;
	return *this;
}

Point::~Point(){
	//std::cout << "The destructor was called" << std::endl;
}

const Fixed Point::getX() const{
	return _x;
}
const Fixed Point::getY() const{
	return _y;
}
