#pragma once
#include "pch.h"
#include "BaseObjects.h"
#include "IBaseAI.h"
#include "Map.h"

namespace RPG {
namespace ENGINE {

//Sub Classes
class WorldViewConstructor;
class WorldControler;

using AI::IBaseAI;

class Model
{
	size_t i = 0;
	Map World;
public:
	Model(json&);
	~Model();
	friend WorldViewConstructor;
	friend WorldControler;
};

}//ENGINE
}//RPG
