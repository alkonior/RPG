#pragma once
#include "Entities.h"



class Map {
private:

	size_t _seed;

public:
	size_t h;
	size_t w;
	Map(size_t);
	vector<vector<shared_ptr<IEntity>>> World;
	vector<weak_ptr<IEntity>> Enemies;
	shared_ptr<Hero> hero;
	shared_ptr<IEntity>& operator[](const Point&);
	void Delete(Point p);
	void Init();
	~Map();


};

