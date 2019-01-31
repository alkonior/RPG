#include "pch.h"
#include "WorldControler.h"


WorldControler::WorldControler(Model& E): World(E.World) {}

void WorldControler::GetComand(size_t comand) {
	if (!World.hero.expired()) {
		_ComandList.push_back(
			World.hero.lock()->getAI()->getActions(&World, comand));
		executeAll();
		for (size_t i = 0; i<World.Enemies.size(); i++) {
			if (!World.Enemies[i].expired())
				_ComandList.push_back(
					World.Enemies[i].lock()->getAI()->getActions(&World, comand));
			executeAll();
		}
	}
}

void WorldControler::executeAll() {
	for (size_t i = 0; i<_ComandList.size(); i++) {
		for (size_t j = 0; j<_ComandList[i].size(); j++) {
			_ComandList[i][j]->accept(*this);
		}
	}
	_ComandList.clear();
}
