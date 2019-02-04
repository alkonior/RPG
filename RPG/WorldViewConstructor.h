#pragma once
#include "Map.h"


class WorldViewConstructor
{
	const  shared_ptr<Map> World;
	mutable Point worldShift;
    bool existPoint(const Point) const;
	public:
		struct HeroInfo {
			HeroInfo() {};
			size_t Hp;
			size_t Mp;
		};
		HeroInfo getHeroInfo();

	vector<vector<const Texture*>> GetMapInfo(size_t, size_t)const;

	WorldViewConstructor(const shared_ptr<Map>);
};

typedef WorldViewConstructor WVC;


