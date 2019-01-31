#pragma once
#include"Point.h"



#define DEFAULT_CS 1
#define FLOOR_CS 2
#define WALL_CS 3
#define HERO_CS 4
#define ZOMBIE_CS 5


class Texture
{
	char sym;
	chtype colorset;
public:
	Texture();
	Texture(char, unsigned long);
	void Draw(Point,WINDOW*) const;
	Texture(Texture&) = default;
};

namespace TEXTURES_ARAAY
{
const Texture T_Zero(' ', DEFAULT_CS);
const Texture T_Wall('W', WALL_CS);
const Texture T_Floor(' ', FLOOR_CS);
const Texture T_Hero('H', HERO_CS);
const Texture T_Zombie('Z', ZOMBIE_CS);
const Texture T_Dragon('G', HERO_CS);
const Texture T_FireBall('F', DEFAULT_CS);
}
void initCS();

