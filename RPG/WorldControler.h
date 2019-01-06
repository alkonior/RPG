#pragma once
#include "pch.h"
#include "Model.h"
#include "Map.h"
#include "BaseControler.h"
#include "WCComandslist.h"
#include <iostream>


namespace RPG{
namespace ENGINE{
using BASECNTROLER::BaseControler;

class WorldControler:public BaseControler
{
	Map& World;
	vector<shared_ptr<BASECNTROLER::IComand>> ComandList;
	void executeAll();
public:
	WorldControler(Model&);
	void GetComand(size_t);
	template<class T>
	void execute();
	void _execute()override
	{};
};
}//ENGINE
}//RPG
