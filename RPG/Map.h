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
	size_t i = 0;
	vector<vector<shared_ptr<IEntity>>> World;
	vector<vector<Texture>> DrawWorld;

//	Hero hero;
public:
	Map(size_t, size_t);
	void Comand(int);
	vector<vector<Texture>>& GetInfo() ;
	~Map();
};

