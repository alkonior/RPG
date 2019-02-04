#pragma once
#include <exception>
#include "IBaseAI.h"
#include "IBaseControler.h"
#include "Textures.h"

class IEntity;
class IPerson;
class INotPerson;
class IProjectile;
class IMonster;

class Hero;

class Zombie;
class Skeleton;
class Dragon;

class Princess;

class Wall;
class FireBall;
class Arrow;
class Apteca;

class ZombieAI;
class SkeletonAI;
class HeroAI;
class DragonAI;

template<class T>
class ProjectileAI;

class IColiders {
public:
	virtual ComandList _colide(IEntity*) = 0;
	virtual ComandList _colide(Hero*) = 0;
	virtual ComandList _colide(Wall*) = 0;
	virtual ComandList _colide(Zombie*) = 0;
	virtual ComandList _colide(Dragon*) = 0;
	virtual ComandList _colide(FireBall*) = 0;
	virtual ComandList _colide(Skeleton*) = 0;
	virtual ComandList _colide(Apteca*) = 0;
	virtual ComandList _colide(Arrow*) = 0;
	virtual ComandList _colide(Princess*) = 0;
};

class IEntity:public IColiders{
protected:

	const Texture& _t;
	Point _cord;

public:
	IEntity(Point, const Texture&);
	const Texture& getTexture();
	ComandList colide(IEntity* in);
	static void Init(json&) { throw new std::exception("Not inited class"); }
	virtual shared_ptr<IBaseAI> getAI() = 0;
	const Point getCord() const { return _cord; }
	virtual ~IEntity();
	void setCord(Point p) { _cord = p; }
};

class IPerson: public IEntity {
protected:
	size_t _hp;
	size_t _mana;
	size_t _dmg;
	size_t _speed;
	size_t _armor;

public:
	IPerson(Point, const Texture&);
	bool getDmg(IPerson*);
	bool getDmg(IProjectile*);
};

class INotPerson: public IEntity {
	size_t damage;
	size_t speed;

public:
	INotPerson(Point, const Texture&);
};

class Hero: public IPerson {
private:
	using ShotType = Arrow;
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
	shared_ptr<HeroAI> _AI;
public:
	Hero(Point);
	static void Init(json&);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	friend HeroAI;

	// Унаследовано через IPerson
	shared_ptr<IBaseAI> getAI() override;
};

class IMonster: public IPerson {
public:
	IMonster(Point, const Texture&);
};

class Zombie: public IMonster {
private:
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
	shared_ptr<ZombieAI> _AI;
public:
	Zombie(Point);
	static void Init(json&);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	shared_ptr<IBaseAI> getAI() override;
	friend ZombieAI;
};

class Dragon: public IMonster {
private:
	using ShotType = FireBall;
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
	shared_ptr<DragonAI> _AI;
public:
	Dragon(Point);
	static void Init(json&);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	shared_ptr<IBaseAI> getAI() override;
	friend DragonAI;

};

class Princess: public INotPerson {
};

class Wall: public INotPerson {
public:

	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	shared_ptr<IBaseAI> getAI() override;
	Wall(Point);
};

class IProjectile:public IEntity
{
protected:
	Point _direction;
	size_t _speed;
	size_t _dmg;
public:
	IProjectile(Point, const Texture&);
	Point getDir() const;
	size_t getSpeed()const ;
	friend IPerson;
};

class FireBall: public IProjectile {
	
	static size_t _startDmg;
	static size_t _startSpeed;
	shared_ptr<ProjectileAI<Dragon>> _AI;
public:
	static void Init(json&);
	FireBall(Point p, Point dir);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Princess*) override;
	ComandList _colide(Apteca*) override;

	shared_ptr<IBaseAI> getAI() override;

	friend ProjectileAI<Dragon>;
};

class Arrow: public IProjectile {
	static size_t _startDmg;
	static size_t _startSpeed;
	shared_ptr<ProjectileAI<Skeleton>> _AI;
public:
	static void Init(json&);
	Arrow(Point p, Point dir);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	

	// Унаследовано через IProjectile
	virtual shared_ptr<IBaseAI> getAI() override;

};

class Apteca: public INotPerson {
  /*void _colide(I_Entity& in) override;
  void _colide(Hero&) override;
  void _colide(Monster&) override;
  void _colide(Zombie&) override;
  void _colide(Dragon&) override;
  void _colide(Princess&) override;
  void _colide(Wall&) override;*/
};

class Skeleton: public IMonster {
private:
	using ShotType = Arrow;
	static size_t _startHp;
	static size_t _startMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;
	shared_ptr<SkeletonAI> _AI;
public:
	Skeleton(Point);
	static void Init(json&);


	ComandList _colide(IEntity*) override;
	ComandList _colide(Hero*) override;
	ComandList _colide(Wall*) override;
	ComandList _colide(Zombie*) override;
	ComandList _colide(Dragon*) override;
	ComandList _colide(FireBall*) override;
	ComandList _colide(Arrow*) override;
	ComandList _colide(Skeleton*) override;
	ComandList _colide(Apteca*) override;
	ComandList _colide(Princess*) override;

	shared_ptr<IBaseAI> getAI() override;
	friend DragonAI;
};
