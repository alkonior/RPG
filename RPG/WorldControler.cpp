#include "pch.h"
#include "WorldControler.h"


WorldControler::WorldControler(Model& E) : World(E.World) {}

void WorldControler::GetComand(size_t comand) {
  _ComandList.push_back(
      World.hero->getAI()->getActions(&World, comand));
  executeAll();
  for(auto enemy : World.Enemies ){
  _ComandList.push_back(
     enemy->getAI()->getActions(&World, comand));
    executeAll();
  }
}

void WorldControler::executeAll() {
  for (size_t i = 0; i < _ComandList.size(); i++) {
  for (size_t j = 0; j < _ComandList[i].size(); j++) {
      _ComandList[i][j]->accept(*this);
  }
  }
  _ComandList.clear();
}
