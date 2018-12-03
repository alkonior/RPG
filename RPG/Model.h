#pragma once
#include "BaseObjects.h"
#include <stack>
#include <memory>

namespace RPG{
namespace ENGINE{
using TEXTURES::Point;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::stack;
using std::pair;

//Sub Classes
class WorldViewConstructor;
class WorldControler;
//

class Model
{
	size_t h;
	size_t w;
	size_t i = 0;
	vector<vector<shared_ptr<RPG::Entities::IEntity>>> World;
	shared_ptr <RPG::Entities::Hero> hero;
public:
	Model(size_t);
	void Comand(int);
	~Model();
	friend WorldViewConstructor;
	friend WorldControler;
};

}//ENGINE
}//RPG
