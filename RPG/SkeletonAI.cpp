#include "pch.h"
#include "SkeletonAI.h"


SkeletonAI::SkeletonAI(Skeleton* s):skeleton(s)
{
}

ComandList SkeletonAI::getActions(const void *, size_t)
{
	return ComandList();
}

