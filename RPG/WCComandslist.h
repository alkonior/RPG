#pragma once
#include "IBaseControler.h"
#include "Entities.h"
#include <functional>
#include "WorldControler.h"  

class CForward: public IComand {
public:                                 
		IEntity* object;                       
		CForward(IEntity* p) { object = p; }
		void accept(IBaseControler&) override;  
};

class MoveMe : public IComand {
 public:
  IEntity* object;
  Point p;
  MoveMe(IEntity* o, Point p):p(p) { object =o; }
  void accept(IBaseControler&) override;
};

class IfCanMoveMe : public IComand {
 public:
  IEntity* object;
  Point p;
  IfCanMoveMe(IEntity* o, Point p):p(p) { object =o; }
  void accept(IBaseControler&) override;
};

template<class A_, class B_>
class Attack_A_to_B : public IComand {
 public:
  A_* A;
  B_* B;
  Attack_A_to_B(A_*, B_*) {}
  void accept(IBaseControler&BC) override {
	  (dynamic_cast<WorldControler&>(BC)).execute(this);
};

//
//template<class A_, class B_>
//Attack_A_to_B<A_, B_>::Attack_A_to_B(A_* a, B_* b):A(a), B(b) {
//}
//
//template<class A_, class B_>
//void Attack_A_to_B<A_, B_>::accept(IBaseControler& BC)
//{
//	(dynamic_cast<WorldControler&>(BC)).execute(this);
//}

class CheckEntityHp : public IComand {
 public:
  Point p;
  CheckEntityHp(Point p);
  void accept(IBaseControler&) override;
};

class Shoot : public IComand {
 public:
  Point p;
  Point dir;
  shared_ptr<std::function<shared_ptr<IEntity>(Point)>> generator;
  Shoot(Point p, Point dir, shared_ptr<std::function<shared_ptr<IEntity>(Point)>> g):
	  p(p), dir(dir), generator(g) {};
  void accept(IBaseControler&) override;
};