#pragma once


class Point {
 public:
  size_t x;
  size_t y;
  Point();
  Point(size_t, size_t);
  Point(const Point&) = default;
  Point operator-() const;
  Point operator+(const Point&);
  void operator+=(const Point&);
  friend Point operator+(const Point&, Point);
  Point operator-(const Point&);
};

