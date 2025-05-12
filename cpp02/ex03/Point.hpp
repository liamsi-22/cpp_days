#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(Point const &other);
		Point(const float x, const float y);

		const Point&	operator=(const Point &other);

		Fixed const &getX(void) const;
		Fixed const &getY(void) const;

		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area(Point const a, Point const b, Point const c);

#endif