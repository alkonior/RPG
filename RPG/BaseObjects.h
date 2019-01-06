#pragma once
#include "Textures.h"
#include <exception>

namespace RPG {

namespace Entities {


class IEntity;
class IPerson;
class INotPerson;


class Hero;

class Monster;
class Zombie;
class Skeleton;
class Dragon;


class Princess;


class Wall;
class FireBall;
class Arrow;
class Apteca;




class IEntity
{
	size_t _hp;
	const Texture& _t;
	Point _cord;
	//void virtual move() = 0;

	/*
	void virtual _colide(I_Entity*) = 0;

	void virtual _colide(Hero*) = 0;

	void virtual _colide(Monster*) = 0;
	void virtual _colide(Zombie*) = 0;
	void virtual _colide(Dragon*) = 0;

	void virtual _colide(Princess*) = 0;

	void virtual _colide(Wall*) = 0;
	void virtual _colide(FireBall*) = 0;
	void virtual _colide(Arrow*) = 0;
	void virtual _colide(Apteca*) = 0;
	*/
public:
	IEntity(Point, const Texture&);
	const Texture& getTexture();
	/*void colide(I_Entity* in)
	{
		if (in != nullptr)
			in->_colide(this);
	};*/
	static void Init(json&)
	{
		throw new std::exception("Not inited class");
	};
};

class IPerson: public IEntity
{
	//size_t _hp;
	size_t _mana;
	size_t _dmg;
	size_t _speed;
	size_t _armor;
	//Point _cord;
public:
	IPerson(Point, const Texture&);
};

class INotPerson:public IEntity
{
	//size_t _hp;
	//Point _cord;
	size_t damage;
	size_t speed;
	size_t direction;
public:
	INotPerson(Point, const Texture&);
};


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
	void _colide(Apteca*) override;
	*/
	static void Init(json&);
};

class Monster:public IEntity
{
	//void _colide(I_Entity* in) override;

	//void _colide(Monster*) override {};
};

class Zombie:public Monster
{
	//void _colide(I_Entity* in) override;

	//void _colide(Hero*) override {};

	//void _colide(Princess*) override {};

	//void _colide(Wall*) override {};
	//void _colide(FireBall*);
	//void _colide(Arrow*);
	//void _colide(Apteca*);
};

class Dragon:public Monster
{
	//void _colide(I_Entity* in) override;

	//void _colide(Monster*) override;

	//void _colide(Dragon*) override;
	//void _colide(Skeleton*) override;
	//void _colide(Zombie*) override;

	//void _colide(Hero*) override {};

	//void _colide(Princess*) override;

	//void _colide(Wall*) override;
	//void _colide(FireBall*);
	//void _colide(Arrow*);
	//void _colide(Apteca*);
};

class Princess: public IPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Wall:public INotPerson
{
	Wall(Point);
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class FireBall:public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Arrow:public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Apteca:public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};
}//namespase Entities
}//namespace RPG