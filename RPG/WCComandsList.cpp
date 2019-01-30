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
defNewAccept(CheckEntityHp);
defNewAccept(Shoot);

Attack_A_to_B::Attack_A_to_B(IPerson* a, IPerson* b) {
	A = a;
	B = b;
}

CheckEntityHp::CheckEntityHp(Point p) : p(p) {}

