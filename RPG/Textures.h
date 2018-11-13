#pragma once
#include "curses.h"

#define FLOOR_CS 1
#define WALL_CS 2
#define HERO_CS 3

class Point 
{
public:
	size_t x;
	size_t y;
	Point(size_t, size_t);
	Point(const Point&) = default;
	Point operator-() const;
	Point operator+(const Point&);
	Point operator-(const Point&);
};

class Texture 
{
	char sym;
	chtype colorset;
public:
	Texture(const T_Hero&);
	Texture(char, unsigned long);
	void Draw(Point);
	Texture(Texture&) = default;
};

namespace Textures {
	Texture T_Wall();
	Texture T_Floor();
	Texture T_Hero();
};

void initCS();
