#include "pch.h"
#include "WCComandslist.h"
#include <typeinfo>
#include "WorldControler.h"  


//Фабрика акцептов
#define defNewAccept(comandName)                       \
  void comandName::accept(IBaseControler& BC) {         \
    (dynamic_cast<WorldControler&>(BC)).execute(this); \
  }

defNewAccept(CForward);
defNewAccept(MoveMe);
defNewAccept(IfCanMoveMe);
defNewAccept(Attack_A_to_B);
defNewAccept(Attack_Porjectile);
defNewAccept(DeleteEntity);
defNewAccept(Shoot);

Attack_A_to_B::Attack_A_to_B(IPerson* a, IPerson* b):A(a), B(b) {}

DeleteEntity::DeleteEntity(IEntity* p) : e(p) {}

IfCanMoveMe::IfCanMoveMe(IEntity * o, Point p) : p(p), object(o) {}

MoveMe::MoveMe(IEntity * o, Point p) : p(p), object(o) {}

Shoot::Shoot(Point p, Point dir, shared_ptr<std::function<shared_ptr<IProjectile>(Point,Point)>> g) :
	p(p), dir(dir), generator(g) {};

CForward::CForward(IEntity* o):object(o) {}

Attack_Porjectile::Attack_Porjectile(IPerson* t, IProjectile* p): projectile(p), target(t){}

Attack_Porjectile::Attack_Porjectile(IProjectile* p, IPerson* t) : projectile(p), target(t){}
