#include "pch.h" 
#include "Point.h"



Point::Point() {}

Point::Point(size_t x, size_t y) : x(x), y(y) {}

Point Point::operator-() const { return Point(UINT_MAX - x, UINT_MAX - y); }

Point Point::operator+(const Point& in) { return Point(x + in.x, y + in.y); }

void Point::operator+=(const Point& in) {
  this->y += in.y;
  this->x += in.x;
}

Point Point::operator-(const Point& in) { return Point(*this + (-(in))); }

Point operator+(const Point& l_in, Point r_in) {
  return Point(l_in.x + r_in.x, l_in.y + r_in.y);
}
