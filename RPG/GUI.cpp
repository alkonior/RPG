#include "pch.h"
#include "GUI.h"



GUI::GUI(size_t w, size_t h):_w(w),_h(h), _Scenes(){};

void GUI::init(json& config)
{
	initCS();
	curScene = 0;
	_Scenes.push_back(make_shared<GameScene>(config,_w,_h));
}

size_t GUI::getComand(size_t c)
{
	return _Scenes[curScene]->getComand(c);
}

void GUI::setScene(size_t s)
{
	curScene = s;
}

void GUI::Draw()
{
	_Scenes[curScene]->Draw();
}

GUI::~GUI()
{
}
