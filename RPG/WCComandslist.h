#pragma once
#include "IBaseControler.h"
#include "Entities.h"
#include <functional>
#include "WorldControler.h"  

class CForward: public IComand {
public:
	IEntity* object;
	CForward(IEntity* p);
	void accept(IBaseControler&) override;
};

class MoveMe: public IComand {
public:
	IEntity* object;
	Point p;
	MoveMe(IEntity* o, Point p);
	void accept(IBaseControler&) override;
};

class IfCanMoveMe: public IComand {
public:
	IEntity* object;
	Point p;
	IfCanMoveMe(IEntity* o, Point p);
	void accept(IBaseControler&) override;
};

class Attack_A_to_B: public IComand {
public:
	IPerson* A;
	IPerson* B;
	Attack_A_to_B(IPerson*, IPerson*);
	void accept(IBaseControler&BC) override;
};

class DeleteEntity: public IComand {
public:
	Point p;
	DeleteEntity(Point p);
	void accept(IBaseControler&) override;
};

class Shoot: public IComand {
public:
	Point p;
	Point dir;
	shared_ptr<std::function<shared_ptr<IEntity>(Point)>> generator;
	Shoot(Point p, Point dir, shared_ptr<std::function<shared_ptr<IEntity>(Point)>> g);
	void accept(IBaseControler&) override;
};