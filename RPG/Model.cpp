#include "pch.h"
#include "Model.h"

using namespace RPG;
using namespace ENGINE;
using namespace Entities;



Model::Model(json& config):World((size_t)config["seed"]) 
{

    Hero::Init(config["hero"]);
	World.Init();
}

void Model::Comand(int in)
{
}

Model::~Model()
{
}
