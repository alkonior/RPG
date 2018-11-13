#include "pch.h"
#include "Model.h"

Model::Model(size_t seed)
{
	switch (seed)
	{
	case 1:
	{ 
		/// Тут типа нужно замутить генератор карты
		w = 20;
		h = 20;
		World.resize(h, vector < shared_ptr<IEntity>>(w, shared_ptr<IEntity>()));
		Hero= make_shared()

	}
	default:
		break;
	}
}

void Model::Comand(int in)
{
}

vector<vector<Texture>>  Model::GetWorld(Point lu, Point rd)
{
	size_t w = rd.x - lu.x;
	size_t h = rd.y - lu.y;
	vector<vector<Texture>> out()
	// TODO: вставьте здесь оператор return
}


Model::~Model()
{
}
