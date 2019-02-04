#pragma once
#include "IBaseScene.h"
#include "Model.h"
#include "WorldPanel.h"
#include "InfoPanel.h"

class GameScene:
	public IBaseScene
{
	Model _Engine;
	WorldPanel _WP;
	InfoPanel _MIP;
	//BarPanel BP;
public:
	GameScene(json& description, size_t, size_t);
	size_t getComand(size_t) override;
	void Draw() override;
	~GameScene();
};

