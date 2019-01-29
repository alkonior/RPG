#include "pch.h"
#include "WorldControler.h"


template <>
void WorldControler::execute(const CForward*) {
  std::cerr << "WorldConteroler Forward yeee";
}

template <>
void WorldControler::execute(const MoveMe* comand) {
  auto cp = comand->object->getCord();
  auto curObject = World[cp];
  Point p = comand->p;
  if (World[cp + p] == nullptr) {
    World[cp] = nullptr;
    World[cp + p] = curObject;
    curObject->setCord(curObject->getCord() + p);
  } else {
    World[cp]->colide(World[cp + p].get());
  }
}