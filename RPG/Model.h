#pragma once
#include "pch.h"
#include "BaseObjects.h"
#include "Map.h"

namespace RPG {
namespace ENGINE {

//Sub Classes
class WorldViewConstructor;
class WorldControler;


class Model
{
	size_t i = 0;
	Map World;

public:
	Model(json&);
	void Comand(int);
	~Model();
	friend WorldViewConstructor;
	friend WorldControler;
};

}//ENGINE
}//RPG
