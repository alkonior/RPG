#pragma once


class IBaseScene
{
public:
	IBaseScene();
	virtual size_t getComand(size_t) = 0;
	virtual void Draw() = 0;
	virtual ~IBaseScene();
};

