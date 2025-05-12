#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(Point const &other): _x(other.getX()), _y(other.getY()){}

const Point&	Point::operator=(const Point  &other){
    if (this != &other){}
    return (*this);
}

Fixed Point::area(Point const a, Point const b, Point const c){
    Fixed area = a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY());

    area = area / Fixed(2);
    return area.abs();
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed area_abc = area(a, b, c);

    Fixed area_pab = area(point, a, b);
    Fixed area_pbc = area(point, b, c);
    Fixed area_pca = area(point, c, a);

    Fixed result = area_abc - (area_pab + area_pbc + area_pca);
    return (result.abs().toFloat() < 1e-6f);
}

Fixed const& Point::getX(void) const{
    return (_x);
}

Fixed const& Point::getY(void) const{
    return (_y);
}

Point::~Point(){}