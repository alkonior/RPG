#pragma once
#include "Model.h"
#include "InfoPanel.h"
#include "MainInfoPanel.h"
#include "BarPanel.h"
#include "WorldPanel.h"
#include "WorldViewConstructor.h"



#ifndef BaseLeftShiftX
#define BaseLeftShiftX 2
#endif // !BaseLeftShiftX

#ifndef BaseUpShiftY
#define BaseUpShiftY 1
#endif // !BaseUpShiftY

#ifndef BaseRightShiftX 
#define BaseRightShiftX  15
#endif // !BaseRightShiftX 

#ifndef BaseDownShiftY
#define BaseDownShiftY 7
#endif // !BaseDownShiftY

namespace RPG{
namespace GUINSP{
using ENGINE::Model;
using std::vector;
using std::shared_ptr;
using TEXTURES::Texture;
using TEXTURES::Point;

class GUI
{
	Point _lu_shift;
	Point _rd_shift;
	size_t _w;
	size_t _h;
	WVC DataSource;
	vector<shared_ptr<InfoPanel>> PanelsStack;
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