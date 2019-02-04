#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"


class SkeletonAI:
	public IBaseAI
{
public:
	SkeletonAI(Skeleton*);
	~SkeletonAI();

	// Унаследовано через IBaseAI
	virtual ComandList getActions(const void *, size_t) override;
};

