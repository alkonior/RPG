#include "pch.h"
#include "Map.h"

Map::Map(size_t w, size_t h):World(h,vector<shared_ptr<IEntity>>(w)), h(h), w(w), DrawWorld(h, vector<Texture>(w, Texture(' ', 1)))
{

}

void Map::Comand(int in)
{
}

vector<vector<Texture>>& Map::GetInfo()
{
	return DrawWorld;
}



Map::~Map()
{
}
