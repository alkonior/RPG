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
    auto result = World[cp]->colide(World[cp + p].get());
    if (!result.empty()) _ComandList.push_back(result);
  }
}

template <>
void WorldControler::execute(const Attack_A_to_B* comand) {
  IPerson* a = dynamic_cast<IPerson*>(comand->A);
  IPerson* b = dynamic_cast<IPerson*>(comand->B);
  if (b->getDmg(a)) {
    _ComandList.push_back(ComandList({make_shared<CheckEntityHp>(b->getCord())}));
  }
}

template <>
void WorldControler::execute(const CheckEntityHp* comand) {
  Point p = comand->p;
  World[p] = shared_ptr<IEntity>();
}