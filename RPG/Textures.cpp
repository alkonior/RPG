#include "pch.h"

using namespace RPG;
using namespace TEXTURES;

Point::Point(){}

Point::Point(size_t x, size_t y):x(x),y(y){}


Point Point::operator-() const
{
	return Point(UINT_MAX - x, UINT_MAX - y);
}

Point Point::operator+(const Point& in)
{
	return Point(x+in.x, y+in.y);
}

Point Point::operator-(const Point& in)
{
	return Point(*this+(-(in)));
}

Texture::Texture(){}

Texture::Texture(char c, unsigned long index) :sym(c), colorset(index) {}

void Texture::Draw(Point in, WINDOW* W) const
{
	wattron(W,COLOR_PAIR(colorset));
	mvwaddch(W, in.x, in.y, sym);
	wattroff(W,COLOR_PAIR(colorset));
}

Point RPG::TEXTURES::operator+(const Point& l_in, Point r_in)
{
	return Point(l_in.x + r_in.x, l_in.y + r_in.y);
}

void RPG::TEXTURES::initCS()
{
	init_pair(DEFAULT_CS, COLOR_RED, COLOR_RED);
	init_pair(FLOOR_CS, COLOR_WHITE, COLOR_WHITE);
	init_pair(WALL_CS, COLOR_BLACK, COLOR_BLACK);
	init_pair(HERO_CS, COLOR_RED, COLOR_WHITE);
}
