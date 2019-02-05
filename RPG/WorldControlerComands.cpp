#include "pch.h"
#include "WorldControler.h"


template <>
void WorldControler::execute(const CForward*) {
	std::cerr<<"WorldConteroler Forward yeee";
}

template <>
void WorldControler::execute(const MoveMe* comand) {
	auto cp = comand->object->getCord();
	auto curObject = (*World)[cp];
	Point p = comand->p;
	if ((*World)[cp+p]==nullptr) {
		(*World)[cp] = nullptr;
		(*World)[cp+p] = curObject;
		curObject->setCord(curObject->getCord()+p);
	}
	else {
		auto result = (*World)[cp]->colide((*World)[cp+p].get());
		if (!result.empty()) _ComandList.push_back(result);
	}
}

template <>
void WorldControler::execute(const PushMe* comand) {
	auto cp = comand->object->getCord();
	auto curObject = (*World)[cp];
	Point p = comand->p;
	if ((*World)[cp+p]==nullptr) {
		(*World)[cp] = nullptr;
		(*World)[cp+p] = curObject;
		curObject->setCord(curObject->getCord()+p);
	}
}

template <>
void WorldControler::execute(const Attack_A_to_B* comand) {
	if (comand->B->attack(comand->A)) {
		_ComandList.push_back(ComandList{make_shared<DeleteEntity>(comand->B)});
	}
}

template <>
void WorldControler::execute(const DeleteEntity* comand) {
	World->Delete(comand->e->getCord());
}

template <>
void WorldControler::execute(const Shoot* comand) {
	if ((*World)[comand->position->getCord()+comand->dir]==nullptr)
	{
		auto projectile = (*(comand->generator))(comand->position->getCord()+comand->dir, comand->dir);
		if (comand->m->canShoot(projectile.get()))
		World->addProjectile(projectile);
	}
}
