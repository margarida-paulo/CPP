#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()){
	std::cout << "The default constructor was called" << std::endl;
}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)){
	std::cout << "The floats constructor was called" << std::endl;
}

Point::Point(Point &point) : _x(point._x), _y(point._y){
	std::cout << "The copy constructor was called" << std::endl;
}

Point& Point::operator=(Point &point){
	this = Point(point);
	return this;
}
