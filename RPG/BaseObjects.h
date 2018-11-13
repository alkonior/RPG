#pragma once
#include "Textures.h"


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
	explicit IEntity(Texture,Point);
	size_t hp;
	Texture t;
	Point cord;
	void virtual move() = 0;

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
	/*void colide(I_Entity* in)
	{
		if (in != nullptr)
			in->_colide(this);
	};*/
};

class IPerson : public IEntity
{
	IPerson(Texture,Point);
	//size_t hp;
	size_t mana;
	size_t dmg;
	size_t speed;
	size_t armor;
	//char sym;
	//Point cord;

};

class INotPerson :public IEntity
{
	//size_t hp;
	//char sym;
	//Point cord;
	size_t damage;
	size_t speed;
	size_t direction;
};


class Hero :public IPerson
{
	Hero(Point);
	/*
	void _colide(I_Entity* in) override;

	void _colide(Monster*) override;

	void _colide(Hero*) override {};

	void _colide(Princess*) override;

	void _colide(Wall*) override {};
	void _colide(FireBall*) override;
	void _colide(Arrow*) override;
	void _colide(Apteca*) override;*/

};

class Monster :public IEntity
{
	//void _colide(I_Entity* in) override;

	//void _colide(Monster*) override {};
};

class Zombie :public Monster
{
	//void _colide(I_Entity* in) override;

	//void _colide(Hero*) override {};

	//void _colide(Princess*) override {};

	//void _colide(Wall*) override {};
	//void _colide(FireBall*);
	//void _colide(Arrow*);
	//void _colide(Apteca*);
};

class Dragon :public Monster
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

class Princess :public IEntity
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Wall :public INotPerson
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

class FireBall :public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Arrow :public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

class Apteca :public INotPerson
{
	/*void _colide(I_Entity& in) override;
	void _colide(Hero&) override;
	void _colide(Monster&) override;
	void _colide(Zombie&) override;
	void _colide(Dragon&) override;
	void _colide(Princess&) override;
	void _colide(Wall&) override;*/
};

