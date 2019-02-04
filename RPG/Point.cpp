#include "pch.h"
#include "Point.h"


Point::Point() {}

Point::Point(size_t x, size_t y) : x(x), y(y) {}

Point Point::operator-() const { return Point(UINT_MAX - x, UINT_MAX - y); }

Point Point::operator+(const Point& in) { return Point(x + in.x, y + in.y); }

Point Point::betsDir(const Point& in)const {
  int x1 = x;
  int y1 = y;
  int x2 = in.x;
  int y2 = in.y;
  int d1 = x1 - x2;
  int d2 = y1 - y2;

  if (abs(d1) > abs(d2)) {
    return Point(-d1 / abs(d1), 0);
  } else
    return Point(0, -d2 / abs(d2));
}

void Point::operator+=(const Point& in) {
  this->y += in.y;
  this->x += in.x;
}

void Point::operator=(const Point& in) {
  x = in.x;
  y = in.y;
}

bool Point::operator==(const Point & in) const
{
	return (x==in.x)&&(y==in.y);
}

Point Point::operator-(const Point& in)const { return Point(*this + (-(in))); }

size_t Point::distance(const Point& in) const {
	return std::max(std::max<size_t>(x, in.x)-std::min<size_t>(x, in.x),
		   std::max<size_t>(y, in.y)-std::min<size_t>(y, in.y));
}

Point operator+(const Point& l_in, Point r_in) {
  return Point(l_in.x + r_in.x, l_in.y + r_in.y);
}
