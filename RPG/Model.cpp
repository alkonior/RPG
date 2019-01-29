#include "pch.h"
#include "Model.h"




Model::Model(json& config):World((size_t)config["seed"]) 
{
    Hero::Init(config["hero"]);
	Zombie::Init(config["zombie"]);
	World.Init();
}


Model::~Model()
{
}
