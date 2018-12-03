#pragma once
#include "Model.h"

//#define WVC WorldViewConstructor

namespace RPG{
namespace ENGINE{

using TEXTURES::Texture;
using TEXTURES::Point;
using std::vector;


class WorldViewConstructor
{
	const Model& Engine;
	Point worldShift;
    bool existPoint(const Point) const;
	public:
	WorldViewConstructor(Model&);
	vector<vector<const Texture*>> GetWorldInfo(size_t, size_t)const;
};

typedef WorldViewConstructor WVC;


}//ENGINE
}//RPG

