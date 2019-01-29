#include "pch.h"
#include "WorldControler.h"//todo Полный пиздец
#include <typeinfo>
#include "WCComandslist.h"

//Фабрика акцептов
#define defNewAccept(comandName)                                        \
void comandName::accept(BaseControler& BC)                           \
{															            \
	(dynamic_cast<WorldControler&>(BC)).execute(this);   \
}															            \

													            


defNewAccept(CForward);

void MoveMe::accept(BaseControler& BC) {
  (dynamic_cast<WorldControler&>(BC)).execute(this);
}
