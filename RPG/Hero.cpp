#include "pch.h"
#include "BaseObjects.h"
using namespace RPG;
using namespace TEXTURES;
using namespace Entities;

/*
class Hero:public IPerson
{
  //size_t _hp;
  //size_t _mana;
  //size_t _dmg;
  //size_t _speed;
  //size_t _armor;
  //Point _cord;
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
public:
	Hero(Point);
	/*
	void _colide(I_Entity* in) override;
	void _colide(Monster*) override;

	void _colide(Hero*) override {};

	void _colide(Princess*) override;

	void _colide(Wall*) override {};
	void _colide(FireBall*) override;
	void _colide(Arrow*) override;
	void _colide(Apteca*) override;
	/
	static void Init(json&);
};
*/
size_t Hero::_startArmor = 0;
size_t Hero::_startMana = 0;
size_t Hero::_startDmg = 0;
size_t Hero::_startSpeed = 0;
size_t Hero::_startHp = 0;

Hero::Hero(Point p):IPerson(p, TEXTURES_ARAAY::T_Hero)
{
}

void Hero::Init(json& description) {
	
	Hero::_startArmor = description["startArmor"];
	Hero::_startMana = description["startMana"];
	Hero::_startDmg = description["startDmg"];
	Hero::_startSpeed = description["startSpeed"];
	Hero::_startHp = description["startHp"];
}