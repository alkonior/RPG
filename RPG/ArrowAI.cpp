#include "pch.h"
#include "ArrowAI.h"




ArrowAI::~ArrowAI()
{
}

ArrowAI::ArrowAI(Arrow & a):arrow(a)
{
}

ComandList ArrowAI::getActions(const void *, size_t)
{
	return ComandList();
}
