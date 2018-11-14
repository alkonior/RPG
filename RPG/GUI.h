#pragma once
#include "Model.h"
#include "InfoPanel.h"
#include "MainInfoPanel.h"
#include "BarPanel.h"
#include "WorldPanel.h"
#include <stack>
#include "WorldViewConstructor.h"

namespace RPG{
namespace GUINSP{
using ENGINE::Model;
using std::stack;
using std::shared_ptr;
using TEXTURES::Texture;
using TEXTURES::Point;

#define BaseShiftX 0
#define BaseShiftY 0

class GUI
{
	Point shift;
	size_t _w;
	size_t _h;
	WWC DataSource;
	stack<shared_ptr<InfoPanel>> PanelsStack;
	WorldPanel WP;
	MainInfoPanel MIP;
	BarPanel BP;


public:
	GUI(Model&);
	void init(size_t, size_t);
	bool Comand(size_t);
	void Draw();
	~GUI();
};

}//GUINSP
}//RPG