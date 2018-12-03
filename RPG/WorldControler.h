#pragma once
#include "Model.h"
#include <iostream>


namespace RPG{
namespace ENGINE{
using TEXTURES::Texture;
using TEXTURES::Point;
using std::vector;
using std::shared_ptr;

	namespace WCCOMANDS{
	class IComand
	{
	public:
		IComand() = default;
		virtual void accept(WorldControler&) = 0;
	};
	class CForward:public IComand
	{
	public:
		CForward() = default;
		void accept(WorldControler&)override;
	};
	}//WCCOMANDS

class WorldControler
{
	Model& Engine;
	vector<shared_ptr<WCCOMANDS::IComand>> ComandList;
	void executeAll();
public:
	WorldControler(Model&);
	void GetComand(char);
	template<class T>
	void execute();
};
}//ENGINE
}//RPG
