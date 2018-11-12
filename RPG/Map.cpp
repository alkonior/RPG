#include "pch.h"
#include "Map.h"

Map::Map(size_t w, size_t h):World(h,vector<shared_ptr<IEntity>>(w)), h(h), w(w), DrawWorld(h, vector<Texture>(w, Texture('A', 0, A_PROTECT)))
{

}

vector<vector<Texture>>& Map::GetInfo()
{
	return DrawWorld;
}



Map::~Map()
{
}
