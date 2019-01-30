#include "pch.h"
#include "WCComandslist.h"
#include <typeinfo>
#include "WorldControler.h"  


//Фабрика акцептов
#define defNewAccept(comandName)                       \
  void comandName::accept(BaseControler& BC) {         \
    (dynamic_cast<WorldControler&>(BC)).execute(this); \
  }

defNewAccept(CForward);
defNewAccept(MoveMe);
defNewAccept(Attack_A_to_B);
defNewAccept(CheckEntityHp);

Attack_A_to_B::Attack_A_to_B(IEntity* a, IEntity* b) {
	A = a;
	B = b;
}

CheckEntityHp::CheckEntityHp(Point p) : p(p) {}

