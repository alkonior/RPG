#pragma once
#include "BaseControler.h"

namespace RPG {
namespace ENGINE {
namespace WCCOMANDS {
using BASECNTROLER::IComand;
using BASECNTROLER::BaseControler;

class CForward:public IComand
{
public:
	CForward() = default;
	void accept(BaseControler&) override;
};

class MoveMeUp:public IComand
{
public:
	MoveMeUp() = default;
	void accept(BaseControler&) override;
};

}
}
}