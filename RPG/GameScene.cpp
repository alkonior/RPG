#include "pch.h"
#include "GameScene.h"




GameScene::GameScene(json& description, size_t h, size_t w):_Engine(description),_WP()
{
	_WP.init(Point(0, 0), Point(w-21, h-9));
	_MIP.init(Point(w-20, 0), Point(w-1, h-9));
}

size_t GameScene::getComand(size_t comand)
{
	return _Engine.getComand(comand);
}

void GameScene::Draw()
{
	_WP.Draw(_Engine.getData());
	_MIP.Draw(_Engine.getData());
}

GameScene::~GameScene()
{
}

