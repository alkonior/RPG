#pragma once
#include "Model.h"
#include "BaseControler.h"
#include "WCComandslist.h"
#include <iostream>


namespace RPG{
namespace ENGINE{
using TEXTURES::Texture;
using BASECNTROLER::BaseControler;
using TEXTURES::Point;
using std::vector;
using std::shared_ptr;

class WorldControler:public BaseControler
{
	Model& Engine;
	vector<shared_ptr<BASECNTROLER::IComand>> ComandList;
	void executeAll();
public:
	WorldControler(Model&);
	void GetComand(char);
	template<class T>
	void execute();
	void _execute()override
	{};
};
}//ENGINE
}//RPG
