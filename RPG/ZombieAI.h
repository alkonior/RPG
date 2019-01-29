#pragma once
#include"pch.h"
#include "IBaseAI.h"
#include "WCComandslist.h"
#include "Entities.h"
#include "Map.h"


class ZombieAI:
	public IBaseAI
{
private: 
	mutable size_t step;
public:
	ZombieAI();
	// Унаследовано через IBaseAI
	ComandList getActions(const void *, const void *, size_t)const override;
};

