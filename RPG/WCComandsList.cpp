#include "pch.h"
#include "WorldControler.h"//todo ������ ������
#include <typeinfo>
#include "WCComandslist.h"
using namespace RPG::ENGINE::BASECNTROLER;

void RPG::ENGINE::WCCOMANDS::CForward::accept(BaseControler& BC)
{
	(dynamic_cast<WorldControler&>(BC)).execute<CForward>();
}
