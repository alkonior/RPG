#include "pch.h"
#include "Model.h"

using namespace RPG;
using namespace ENGINE;
using namespace ENTITIES;
using namespace AI;



Model::Model(json& config):World((size_t)config["seed"]) 
{
    Hero::Init(config["hero"]);
	Zombie::Init(config["zombie"]);
	World.Init();
}


Model::~Model()
{
}
