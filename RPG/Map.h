#pragma once
#include <string>
#include "Entities.h"



class Map {
private:


		vector<vector<shared_ptr<IEntity>>> World;
public:
	size_t height;
	size_t width;
	Map(vector<std::string>,json&);

	vector<weak_ptr<IMonster>> Enemies;
	vector<weak_ptr<IProjectile>> Projectiles;
	weak_ptr<Hero> hero;
	shared_ptr<IEntity>& operator[](const Point&);
	const shared_ptr<IEntity>& operator[](const Point&)const;
	void addEnemy(shared_ptr<IMonster>);
	void addProjectile(shared_ptr<IProjectile>);
	void Delete(Point p);
	~Map();


};

