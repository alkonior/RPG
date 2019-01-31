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
	vector<weak_ptr<Monster>> Enemies;
	vector<weak_ptr<IProjectile>> Projectiles;
	weak_ptr<Hero> hero;
	shared_ptr<IEntity>& operator[](const Point&);
	const shared_ptr<IEntity>& operator[](const Point&)const;
	void addEnemy(shared_ptr<Monster>);
	void addProjectile(shared_ptr<IProjectile>);
	void Delete(Point p);
	void Init();
	~Map();


};

