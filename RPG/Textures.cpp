#include "pch.h"
#include "Textures.h"

Texture::Texture(){}

Texture::Texture(char c, unsigned long index) :sym(c), colorset(index) {}

void Texture::Draw(Point in, WINDOW* W) const
{
	wattron(W,COLOR_PAIR(colorset));
	mvwaddch(W, in.x, in.y, sym);
	wattroff(W,COLOR_PAIR(colorset));
}



void initCS()
{
	init_pair(DEFAULT_CS, COLOR_RED, COLOR_RED);
	init_pair(FLOOR_CS, COLOR_WHITE, COLOR_WHITE);
	init_pair(WALL_CS, COLOR_BLACK||COLOR_WHITE, COLOR_BLACK||COLOR_WHITE);
	init_pair(HERO_CS, COLOR_RED, COLOR_WHITE);
	init_pair(ZOMBIE_CS, COLOR_GREEN, COLOR_WHITE);
	init_pair(SKELETON_CS, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(APTECA_CS, COLOR_RED, COLOR_WHITE);
	init_pair(ARROW_CS, COLOR_BLACK, COLOR_WHITE);
}
