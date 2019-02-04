#pragma once
#include "IBaseScene.h"
#include "ScenesList.h"




class GUI
{
	size_t _w;
	size_t _h;
	vector<shared_ptr<IBaseScene>> _Scenes;
	size_t curScene;
public:
	GUI(size_t, size_t);
	void init(json&);
	size_t getComand(size_t);
	void setScene(size_t);
	void Draw();
	~GUI();
};

