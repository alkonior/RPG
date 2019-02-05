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
defNewAccept(PushMe);
defNewAccept(Attack_A_to_B);
defNewAccept(DeleteEntity);
defNewAccept(Shoot);

Attack_A_to_B::Attack_A_to_B(IHasDmg* a, IPerson* b):A(a), B(b) {}

DeleteEntity::DeleteEntity(IEntity* p) : e(p) {}

PushMe::PushMe(IEntity * o, Point p) : p(p), object(o) {}

MoveMe::MoveMe(IEntity * o, Point p) : p(p), object(o) {}

Shoot::Shoot(IHasMana* m, Point dir, IEntity* e, shared_ptr<Shoot::func_t> g) :
	m(m), dir(dir),position(e), generator(g) {};

CForward::CForward(IEntity* o):object(o) {}
