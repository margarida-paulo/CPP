#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(float x, float y);
		Point(Point &point);
		Point &operator=(Point &point);
};
