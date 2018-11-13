#pragma once
#include "BaseObjects.h"
#include <vector>
#include <stack>
#include <memory>

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
	vector<vector<shared_ptr<IEntity>>> World;
	shared_ptr <Hero> hero;
public:
	Model(size_t);
	void Comand(int);
	vector<vector<const Texture*>> GetWorld(Point,Point);
	~Model();
};

