#pragma once
#include <algorithm>

class Point {
 public:
  size_t x;
  size_t y;
  Point();
  Point(size_t, size_t);
  Point(const Point&) = default;
  Point operator-() const;
  Point operator+(const Point&);
  Point betsDir(const Point&) const;
  void operator+=(const Point&);
  void operator=(const Point&);
  bool operator==(const Point & in) const;
  friend Point operator+(const Point&, Point);
  Point operator-(const Point&)const;
  size_t distance(const Point&) const;
};

