#include "pch.h"
#include "Model.h"




Model::Model(json& config):_World(shared_ptr<Map>(new Map((size_t)config["seed"]))),_WC(_World),_WVC(_World)
{
    Hero::Init(config["hero"]);
	Zombie::Init(config["zombie"]);
	Dragon::Init(config["dragon"]);
	FireBall::Init(config["fireball"]);
	Arrow::Init(config["arrow"]);

	_World->Init();
}

size_t Model::getComand(size_t c)
{
	_WC.GetComand(c);
	return 0;
}

const WVC & Model::getData() const
{
	return _WVC;
}


Model::~Model()
{
}
