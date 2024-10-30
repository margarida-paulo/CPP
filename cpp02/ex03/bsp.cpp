#include "Fixed.hpp"
#include "Point.hpp"

//|x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|

Fixed area(const Point &a, const Point &b, const Point &c){
	Fixed triangle = (a.getX()*(b.getY()-c.getY())) + (b.getX()*(c.getY() - a.getY())) + (c.getX()*(a.getY() - b.getY()));
	triangle = Fixed::absFixed(triangle);
	Fixed two(2);
	triangle = triangle / two;
	return triangle;
}


bool bsp( Point &a, Point &b, Point &c, Point &point){
	if (area(a,b,point) + area(b, c, point) + area(a,c,point) == area(a,b,c))
		return true;
	return false;
}
