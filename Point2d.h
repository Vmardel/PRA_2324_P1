#ifndef POINT2D_H
#define POINT2D_H
#include <ostream>
#include <cmath>


class Point2d{
    public:
        double x;
        double y;
        Point2d( double x = 0, double y = 0 );
        static double distance( const Point2d &a, const Point2d &b );
        friend bool operator==( const Point2d &a, const Point2d &b );
        friend bool operator!=( const Point2d &a, const Point2d &b );
        friend std::ostream& operator << (std::ostream &out, const Point2d &p);
};

#endif //POINT2D_H
