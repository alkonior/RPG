#pragma once
#include<iostream>

class IBaseControler
{
public:
	IBaseControler() = default;
	virtual void _execute() = 0;
};

class IComand
{
public:
	IComand() = default;
	virtual void accept(IBaseControler&) = 0;
};

typedef vector<shared_ptr<IComand>> ComandList;

