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
	IHasDmg* A;
	IPerson* B;
	Attack_A_to_B(IHasDmg * a, IPerson * b);
	void accept(IBaseControler&BC) override;
};

class DeleteEntity: public IComand {
public:
	IEntity* e;
	DeleteEntity(IEntity* e);
	void accept(IBaseControler&) override;
};

class Shoot: public IComand {
public:
	using func_t = std::function<shared_ptr<IProjectile>(Point, Point)>;
	IHasMana* m;
	Point dir;
	IEntity* position;
	shared_ptr<func_t> generator;
	Shoot(IHasMana* m, Point dir, IEntity* e, shared_ptr<func_t> g);
	void accept(IBaseControler&) override;
};