#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(Point const &other): _x(other.getX()), _y(other.getY()){}

const Point&	Point::operator=(const Point  &other){
    if (this != &other){}
    return (*this);
}

Fixed const& Point::getX(void) const{
    return (_x);
}

Fixed const& Point::getY(void) const{
    return (_y);
}

Point::~Point(){}