#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed area(const Point &a, const Point &b, const Point &c);

bool bsp( Point &a, Point &b, Point &c, Point &point);


int main( void ) {
	Point a(1,10);
	Point b(1,20);
	Point c(10,15);

	Point toCheck1(0,15);
	Point toCheck2(1,15);
	Point toCheck3(2,15);

	Fixed area1 = area(a,b,c);
	if (bsp(a,b,c,toCheck1))
		std::cout << "Inside triangle" << std::endl;
	else
		std::cout << "Outside triangle" << std::endl;

	if (bsp(a,b,c,toCheck2))
		std::cout << "Inside triangle" << std::endl;
	else
		std::cout << "Outside triangle" << std::endl;

	if (bsp(a,b,c,toCheck3))
		std::cout << "Inside triangle" << std::endl;
	else
		std::cout << "Outside triangle" << std::endl;
}
