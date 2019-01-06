#include "pch.h"
#include "WorldControler.h"//todo Полный пиздец
#include <typeinfo>
#include "WCComandslist.h"
using namespace RPG::ENGINE::BASECNTROLER;
using namespace RPG::ENGINE::WCCOMANDS;
void CForward::accept(BaseControler& BC)
{
	(dynamic_cast<WorldControler&>(BC)).execute<CForward>();
}

void MoveMeUp::accept(BaseControler& BC)
{
	(dynamic_cast<WorldControler&>(BC)).execute<MoveMeUp>();
}
