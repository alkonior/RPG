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

vector<vector<const Texture*>>  Model::GetWorld(Point lu, Point rd)
{
	size_t w = rd.x - lu.x;
	size_t h = rd.y - lu.y;
	vector<vector<const Texture*>> out(World.size(), vector<const Texture*>(20));
	for (size_t i = 0; i + lu.y < World.size(); i++)
	{
		for (size_t j = 0; j + lu.x < World[i].size(); j++)
		{
			if (i + lu.y < h && j + lu.x < w)
				out[i][j] = (World[i + lu.y][j + lu.x] ? World[i + lu.y][j + lu.x]->getTexture() : &Textures::T_Zero);
		}
	}
	return out;
}


Model::~Model()
{
}
