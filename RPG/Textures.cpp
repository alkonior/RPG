#include "pch.h"
#include "Textures.h"
#include "curses.h"

Point::Point(size_t x, size_t y):x(x),y(y){}


Point Point::operator-() const
{
	return Point(-x,-y);
}

Point Point::operator+(const Point& in)
{
	return Point(x+in.x, y+in.y);
}

Point Point::operator-(const Point& in)
{
	return Point(*this+(-(in)));
}

Texture::Texture(const T_Hero& in)
{
	sym = in.sym;
	colorset = in.colorset;
}

Texture::Texture(char c, unsigned long index) :sym(c), colorset(index) {}

void Texture::Draw(Point in)
{
	attron(COLOR_PAIR(colorset));
	mvaddch(in.x, in.y, sym);
	attroff(COLOR_PAIR(colorset));
}

void initCS()
{
	init_pair(FLOOR_CS, COLOR_WHITE, COLOR_WHITE);
	init_pair(WALL_CS, COLOR_BLACK, COLOR_BLACK);
	init_pair(HERO_CS, COLOR_RED, COLOR_WHITE);
}

Texture Textures::T_Wall()
{
	return Texture('W', WALL_CS);
}
Texture Textures::T_Floor()
{
	return Texture(' ', FLOOR_CS);
}
Texture Textures::T_Hero()
{
	return Texture('H', HERO_CS);
}
