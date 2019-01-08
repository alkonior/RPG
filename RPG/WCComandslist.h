#pragma once
#include "BaseControler.h"
///Фабрика команд
#define defNewComad(comandName)           \
class comandName:public IComand           \
{                                         \
public:                                   \
	comandName() = default;               \
	void accept(BaseControler&) override; \
}                                         \

namespace RPG {
namespace ENGINE {
namespace WCCOMANDS {
using BASECNTROLER::IComand;
using BASECNTROLER::BaseControler;

defNewComad(CForward);
defNewComad(MoveMeUp);
defNewComad(MoveMeDown);
defNewComad(MoveMeRight);
defNewComad(MoveMeLeft);

}
}
}