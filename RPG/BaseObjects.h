#pragma once
#include "Textures.h"
#include "IBaseAI.h"
#include <exception>

namespace RPG {

namespace ENTITIES {


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

using ENGINE::AI::IBaseAI;


class IEntity
{
protected:
	shared_ptr<IBaseAI> AI;
	
	const Texture& _t;
	Point _cord;
	//void virtual move() = 0;
public:
	bool virtual _colide(IEntity*) = 0;
	bool virtual _colide(Hero*) = 0;
	bool virtual _colide(Wall*) = 0;

	bool virtual _colide(Zombie*) = 0;
	/*
	void virtual _colide(Dragon*) = 0;

	void virtual _colide(Princess*) = 0;

	
	void virtual _colide(FireBall*) = 0;
	void virtual _colide(Arrow*) = 0;
	void virtual _colide(Apteca*) = 0;
	*/
	
public:
	IEntity(Point, const Texture&, shared_ptr<IBaseAI>);
	const Texture& getTexture();
	bool colide(IEntity* in)
	{
		if (in != nullptr)
			return in->_colide(this);
		return false;
	}
	static void Init(json&)
	{
		throw new std::exception("Not inited class");
	}

	shared_ptr<IBaseAI>& getAI()
	{
		return AI;
	}

	Point& getCord()
	{
		return _cord;
	}

};

class IPerson: public IEntity
{
protected:
	size_t _hp;
	size_t _mana;
	size_t _dmg;
	size_t _speed;
	size_t _armor;
public:
	IPerson(Point, const Texture&, shared_ptr<IBaseAI>);
	bool getDmg(size_t);
};

class INotPerson:public IEntity
{
	size_t damage;
	size_t speed;
public:
	INotPerson(Point, const Texture&);
};


class Hero:public IPerson
{
private:
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
public:
	Hero(Point);
	static void Init(json&);
	// Унаследовано через IPerson
	virtual bool _colide(IEntity *) override;
	virtual bool _colide(Hero *) override;
	virtual bool _colide(Wall *) override;
	virtual bool _colide(Zombie *) override;
};

class Monster:public IPerson
{
public:
	Monster(Point, const Texture&, shared_ptr<IBaseAI>);
};

class Zombie:public Monster
{
private:
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
public:
	Zombie(Point);
	static void Init(json&);

	virtual bool _colide(IEntity*) override;
	virtual bool _colide(Hero*) override;
	virtual bool _colide(Wall*) override;
	virtual bool _colide(Zombie*) override;
};

class Dragon:public Monster
{};

class Princess: public IPerson
{};

class Wall:public INotPerson
{
public:
	virtual bool _colide(IEntity*) override;
	virtual bool _colide(Hero*) override;
	virtual bool _colide(Wall*) override;
	virtual bool _colide(Zombie*) override;

	Wall(Point);

};

class FireBall:public INotPerson
{
	size_t direction;
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
	size_t direction;
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