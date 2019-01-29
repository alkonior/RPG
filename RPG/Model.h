#pragma once
#include "pch.h"
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"



//Sub Classes
class WorldViewConstructor;
class WorldControler;


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
