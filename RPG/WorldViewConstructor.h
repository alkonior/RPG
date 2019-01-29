#pragma once
#include "Model.h"
#include "Map.h"


class WorldViewConstructor
{
	const Map& World;
	Point worldShift;
    bool existPoint(const Point) const;
	public:
	WorldViewConstructor(Model&);
	vector<vector<const Texture*>> GetWorldInfo(size_t, size_t)const;
};

typedef WorldViewConstructor WVC;


