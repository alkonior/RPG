#pragma once
#include "curses.h"

#define DEFAULT_CS 0
#define FLOOR_CS 1
#define WALL_CS 2
#define HERO_CS 3

class Point 
{
public:
	size_t x;
	size_t y;
	Point();
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
	Texture();
	Texture(char, unsigned long);
	void Draw(Point) const;
	Texture(Texture&) = default;
};

namespace Textures {
	const Texture T_Zero(' ', DEFAULT_CS);
	const Texture T_Wall('W', WALL_CS);
	const Texture T_Floor(' ', FLOOR_CS);
	const Texture T_Hero('H', HERO_CS);
};

void initCS();
