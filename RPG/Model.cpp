#include "pch.h"
#include "Model.h"

using namespace RPG;
using namespace ENGINE;
using namespace Entities;


Model::Model(size_t seed)
{
	switch (seed)
	{
	case 1:
	{ 
		/// Тут типа нужно замутить генератор карты
		w = 20;
		h = 20;
		World.resize(h, vector<shared_ptr<IEntity>>(w, shared_ptr<IEntity>()));
		hero = make_shared<Hero>(Point(1,1));
		World[1][1] = hero;

	}
	default:
		break;
	}
}

void Model::Comand(int in)
{
}

Model::~Model()
{
}
