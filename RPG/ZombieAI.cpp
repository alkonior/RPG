#include "pch.h"
#include "ZombieAI.h"

using namespace RPG::ENGINE::AI;
using namespace RPG::ENGINE;
using namespace RPG::ENGINE::WCCOMANDS;

ZombieAI::ZombieAI():step(0) {}


vector<shared_ptr<IComand>> RPG::ENGINE::AI::ZombieAI::getActions(const void * w, const void * z, size_t)
{
	step++;
	const ENTITIES::Zombie* zombie = static_cast<const ENTITIES::Zombie*>(z);
	const Map* world = static_cast<const Map*>(w);

	if (zombie)
	return vector<shared_ptr<IComand>>();
}

