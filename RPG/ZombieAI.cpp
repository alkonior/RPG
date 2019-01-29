#include "pch.h"
#include "ZombieAI.h"




ZombieAI::ZombieAI() {}

vector<shared_ptr<IComand>> ZombieAI::getActions(const void* w, const void* z,
                                                 size_t)const {
	step++;
	const Zombie* zombie = static_cast<const Zombie*>(z);
	const Map* world = static_cast<const Map*>(w);

	if (zombie)
	return vector<shared_ptr<IComand>>();
}

