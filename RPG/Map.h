#pragma once
#include "BaseObjects.h"
namespace RPG {
namespace ENGINE {


class Map {
private:

	size_t _seed;

public:
	size_t h;
	size_t w;
	Map(size_t);
	vector<vector<shared_ptr<RPG::ENTITIES::IEntity>>> World;
	shared_ptr<RPG::ENTITIES::Hero> hero;

	void Init();
	~Map();


};


}  //ENGINE
}  //RPG