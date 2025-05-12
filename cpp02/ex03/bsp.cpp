#include "Fixed.hpp"
#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c){
    Fixed area = a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY());

    area = area / Fixed(2);
    return area.abs();
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed area_abc = area(a, b, c);

    Fixed area_pab = area(point, a, b);
    Fixed area_pbc = area(point, b, c);
    Fixed area_pca = area(point, c, a);

    Fixed result = area_abc - (area_pab + area_pbc + area_pca);
    return (result.abs().toFloat() < 1e-6f);
}