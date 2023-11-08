#include "Point2d.h"

Point2d::Point2d( double x, double y ): x{x}, y{y}{
/*
	this-> x = x;
	this-> y = y;
*/
}

double Point2d::distance( const Point2d &a, const Point2d &b ){
    return sqrt( pow( a.x - b.x, 2 ) + pow( a.y - b.y, 2 ) );

}

bool operator == ( const Point2d &a, const Point2d &b ){
    return a.x == b.x && a.y == b.y;

}

bool operator != ( const Point2d &a, const Point2d &b ){
    return a.x != b.x || a.y != b.y;

}

std::ostream& operator << ( std::ostream &out, const Point2d &p ){
    out << "Point (" << p.x << "," << p.y << ")";
    return out;
}
