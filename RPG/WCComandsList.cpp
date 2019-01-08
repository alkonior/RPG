#include "pch.h"
#include "WorldControler.h"//todo Полный пиздец
#include <typeinfo>
#include "WCComandslist.h"
using namespace RPG::ENGINE::BASECNTROLER;
using namespace RPG::ENGINE::WCCOMANDS;
////Фабрика акцептов
#define defNewAccept(comandName)                               \
void comandName::accept(BaseControler& BC)                     \
{															   \
	(dynamic_cast<WorldControler&>(BC)).execute<comandName>(); \
}															   \

defNewAccept(CForward);
defNewAccept(MoveMeUp);
defNewAccept(MoveMeDown);
defNewAccept(MoveMeRight);
defNewAccept(MoveMeLeft);


