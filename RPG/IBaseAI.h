#pragma once
#include "pch.h"
#include "BaseControler.h"
namespace RPG {
namespace ENGINE {
namespace AI {


using BASECNTROLER::IComand;
class IBaseAI
{
public:
	virtual vector<shared_ptr<IComand>> getActions(const void*, const void*, size_t) = 0;
};

}//AI
}//ENGINE
}//RPG