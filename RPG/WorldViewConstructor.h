#pragma once
#include "Model.h"

#define WWC WorldViewConstructor

namespace RPG{
namespace ENGINE{
using TEXTURES::Texture;
using TEXTURES::Point;
using std::vector;


class WorldViewConstructor
{
	const Model& Engine;
	Point worldShift;
public:
	WorldViewConstructor(Model&);
	vector<vector<const Texture*>> GetWorldInfo(size_t, size_t)const;
};



}//ENGINE
}//RPG

