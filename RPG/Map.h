#pragma once
#include "BaseObjects.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::pair;

class Map
{
	size_t h;
	size_t w;

	vector<vector<shared_ptr<IEntity>>> World;
	vector<vector<Texture>> DrawWorld;

//	Hero hero;
public:
	Map(size_t, size_t);
	vector<vector<Texture>>& GetInfo() ;
	~Map();
};

