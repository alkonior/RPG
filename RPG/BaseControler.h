#pragma once
#include<iostream>

namespace RPG {
namespace ENGINE {
namespace BASECNTROLER {


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

}
}
}