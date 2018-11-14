#pragma once
#include "Model.h"
#include "vector"

#define WWC WorldViewConstructor

namespace RPG{
namespace ENGINE{
using TEXTURES::Texture;
using TEXTURES::Point;
using std::vector;


class WorldViewConstructor
{
	const Model& Engine;
public:
	WorldViewConstructor(Model&);
	vector<vector<const Texture*>> GetInfo(Point, Point) const;
};



}//ENGINE
}//RPG

