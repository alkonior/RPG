#pragma once
#include "BaseObjects.h"
#include <vector>
#include <stack>
#include <memory>

namespace RPG{
namespace ENGINE {

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::stack;
using std::pair;

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
};

}//ENGINE
}//RPG
