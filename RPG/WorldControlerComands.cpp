#include "pch.h"
#include "WorldControler.h"

using namespace RPG;
using namespace ENGINE;
using BASECNTROLER::IComand;
using namespace WCCOMANDS;


template<>
void WorldControler::execute<CForward>()
{
	std::cerr<<"WorldConteroler Forward yeee";
}

template<>
void WorldControler::execute<MoveMeLeft>()
{
	Point cp = curObject->getCord();
	if (World[cp+Point(-1, 0)]==nullptr)
	{
		World[cp] = nullptr;
		World[cp+Point(-1, 0)] = curObject;
		curObject->getCord() += Point(-1, 0);
	}
	else
	{
		World[cp]->colide(World[cp+Point(-1, 0)].get());
	}
}

template<>
void WorldControler::execute<MoveMeRight>()
{
	Point cp = curObject->getCord();
	if (World[cp+Point(1, 0)]==nullptr)
	{
		World[cp] = nullptr;
		World[cp+Point(1, 0)] = curObject;
		curObject->getCord() += Point(1, 0);
	}
	else
	{
		World[cp]->colide(World[cp+Point(1, 0)].get());
	}
}

template<>
void WorldControler::execute<MoveMeDown>()
{
	Point cp = curObject->getCord();
	if (World[cp+Point(0, 1)]==nullptr)
	{
		World[cp] = nullptr;
		World[cp+Point(0, 1)] = curObject;
		curObject->getCord() += Point(0, 1);
	}
	else
	{
		World[cp]->colide(World[cp+Point(0, 1)].get());
	}
}

template<>
void WorldControler::execute<MoveMeUp>()
{
	Point cp = curObject->getCord();
	if (World[cp+Point(0, -1)]==nullptr)
	{
		World[cp] = nullptr;
		World[cp+Point(0,-1)] = curObject;
		curObject->getCord() += Point(0, -1);
	}
	else
	{
		World[cp]->colide(World[cp+Point(0, -1)].get());
	}
}