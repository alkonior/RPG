#include "pch.h"
#include "WorldControler.h"


WorldControler::WorldControler(shared_ptr<Map> m): World(m),flag(false) {}

size_t WorldControler::GetComand(size_t comand) {
	if (!World->hero.expired()) {
		for (size_t i = 0; i<World->Projectiles.size(); i++) {
			if (!World->Projectiles[i].expired())
			{
				auto test = World->Projectiles[i].lock()->getAI();
				_ComandList.push_back(
					World->Projectiles[i].lock()->getAI()->getActions(World.get(), comand));
			}
			executeAll();
			
		}
		
		for (size_t i = 0; i<World->Enemies.size(); i++) {
			if (!World->Enemies[i].expired())
			{
				_ComandList.push_back(
					World->Enemies[i].lock()->getAI()->getActions(World.get(), comand));
			}
			else
			{
				World->Enemies.erase(World->Enemies.cbegin()+i);
				i--;
			}
			executeAll();
		}
		_ComandList.push_back(
			World->hero.lock()->getAI()->getActions(World.get(), comand));
		executeAll();
		return 'n';
	}
	else
	{
		if (flag)
		{
			return 'w';
		}
		else
		{
			return 'l';
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
