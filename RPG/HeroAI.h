#pragma once
#include"pch.h"
#include "IBaseAI.h"
#include "WCComandslist.h"
#include "BaseObjects.h"
#include "Map.h"

namespace RPG {
namespace ENGINE {
namespace AI {

class HeroAI:
	public IBaseAI
{
public:
	HeroAI();
	~HeroAI();

	// Унаследовано через IBaseAI
	virtual vector<shared_ptr<IComand>> getActions(const void *, const void *, size_t) override;
};

}//AI
}//ENGINE
}//RPG