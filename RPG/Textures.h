#pragma once

namespace RPG{
namespace TEXTURES{

#define DEFAULT_CS 1
#define FLOOR_CS 2
#define WALL_CS 3
#define HERO_CS 4
#define ZOMBIE_CS 5

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
	void operator+=(const Point&);
	friend Point operator+(const Point&, Point);
	Point operator-(const Point&);
};

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
}
void initCS();


}//TEXTURES
}//RPG