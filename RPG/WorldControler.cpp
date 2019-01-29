#include "pch.h"
#include "WorldControler.h"


WorldControler::WorldControler(Model& E) : World(E.World) {}

void WorldControler::GetComand(size_t comand) {
  _ComandList.push_back(
      World.hero->getAI()->getActions(&World, World.hero.get(), comand));
  executeAll();
}

void WorldControler::executeAll() {
  for (auto i : _ComandList) {
    for (auto j : i) {
      (j)->accept(*this);
    }
  }
  _ComandList.clear();
}
