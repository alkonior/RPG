#pragma once
#include<iostream>

class BaseControler
{
public:
	BaseControler() = default;
	virtual void _execute() = 0;
};

class IComand
{
public:
	IComand() = default;
	virtual void accept(BaseControler&) = 0;
};

typedef vector<shared_ptr<IComand>> ComandList;

