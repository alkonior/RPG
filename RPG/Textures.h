#pragma once
#include"Point.h"



#define DEFAULT_CS 1
#define FLOOR_CS 2
#define WALL_CS 3
#define HERO_CS 4
#define ZOMBIE_CS 5
#define SKELETON_CS 6
#define APTECA_CS 7
#define ARROW_CS 8
#define PRINCESS_CS 9


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
const Texture T_Dragon('D', HERO_CS);
const Texture T_Skeleton('S', SKELETON_CS);
const Texture T_FireBall('*', APTECA_CS);
const Texture T_Apteca('+', APTECA_CS);
const Texture T_Arrow('*', ARROW_CS);
const Texture T_Pincess('P', PRINCESS_CS);
}
void initCS();

