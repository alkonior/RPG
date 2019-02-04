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

class PushMe: public IComand {
public:
	IEntity* object;
	Point p;
	PushMe(IEntity* o, Point p);
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
	IEntity* e;
	DeleteEntity(IEntity* e);
	void accept(IBaseControler&) override;
};

class Attack_Porjectile: public IComand {
public:
	IPerson* target;
	IProjectile* projectile;
	Attack_Porjectile(IPerson*,	IProjectile*);
	Attack_Porjectile(IProjectile*,	IPerson*);
	void accept(IBaseControler&) override;
};

class Shoot: public IComand {
public:
	using finc_t = std::function<shared_ptr<IProjectile>(Point, Point)>;
	IEntity* e;
	Point dir;
	shared_ptr<finc_t> generator;
	Shoot(IEntity* e, Point dir, shared_ptr<finc_t> g);
	void accept(IBaseControler&) override;
};