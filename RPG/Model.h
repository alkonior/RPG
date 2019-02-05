#pragma once
#include <string>
#include "Entities.h"
#include "IBaseAI.h"
#include "WorldViewConstructor.h"
#include "WorldControler.h"
#include "Map.h"



class Model
{
	size_t i = 0;
	shared_ptr<Map> _World;
	WorldControler _WC;
	WVC _WVC;

public:
	Model(json&);
	size_t getComand(size_t );
	const WVC& getData()const;
	~Model();
};
