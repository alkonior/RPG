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

class IEntity:public IColiders {
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

class IHasManaCost {

public:
	virtual size_t getManaCost()const = 0;
};

class IHasMana {
protected:
	size_t _mana;
public:
	IHasMana(size_t);

	size_t getMana();
	bool canShoot(IHasManaCost*);
	virtual size_t getMaxMana()const = 0;
	virtual void updateMana() = 0;
};



class IHasDmg {
public:
	virtual size_t getDmg()const = 0;
};

class IHasHp {
protected:
	size_t _hp;
public:
	IHasHp(size_t);
	size_t getHp()const;
	virtual size_t getMaxHp()const = 0;
	virtual size_t getArmor()const = 0;
	bool attack(IHasDmg*);
};



class IPerson: public IEntity, public IHasDmg, public IHasHp {
protected:
	size_t _speed;
public:
	IPerson(Point p, const Texture& t, size_t hp);
};

class INotPerson: public IEntity {
	size_t damage;
	size_t speed;

public:
	INotPerson(Point, const Texture&);
};

class Hero: public IPerson, public IHasMana {
private:
	using ShotType = Arrow;

	static size_t _startHp;
	static size_t _startMaxMana;
	static size_t _startManaRegenSpeed;
	static size_t _startManaRegenStrong;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startArmor;

	shared_ptr<HeroAI> _AI;
public:
	Hero(Point);
	static void Init(json&);

	size_t getHp();
	size_t getMp();
	size_t getMaxMp();
	size_t getMaxHp();

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

	// Унаследовано через IPerson

	virtual size_t getMaxMana()const override;
	virtual void updateMana() override;

	// Унаследовано через IPerson
	virtual size_t getDmg() const override;
	virtual size_t getMaxHp() const override;
	virtual size_t getArmor() const override;
};

class IMonster: public IPerson {
public:
	IMonster(Point, const Texture&,	 size_t hp);
};

class Zombie: public IMonster {
private:

	static size_t _startHp;
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

	// Унаследовано через IMonster
	virtual size_t getDmg() const override;
	virtual size_t getMaxHp() const override;
	virtual size_t getArmor() const override;
};

class Dragon: public IMonster, public IHasMana {
private:
	using ShotType = FireBall;

	static size_t _startHp;
	static size_t _startMaxMana;
	static size_t _startManaRegenSpeed;
	static size_t _startManaRegenStrong;
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

	size_t getMaxHp()const override;
	size_t getMaxMana()const override;
	void updateMana() override;
	size_t getDmg() const override;
	size_t getArmor() const override;

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

class IProjectile:public IEntity,public IHasManaCost,public IHasDmg
{
protected:
	Point _direction;
	size_t _speed;
public:
	IProjectile(Point, const Texture&);
	Point getDir() const;
	size_t getSpeed()const;
	friend IPerson;
};

class FireBall: public IProjectile {

	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startManaCost;
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

	// Унаследовано через IProjectile
	virtual size_t getManaCost() const override;
	virtual size_t getDmg() const override;
};

class Arrow: public IProjectile {
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startManaCost;

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


	// Унаследовано через IProjectile
	virtual size_t getManaCost() const override;

	virtual size_t getDmg() const override;

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

class Skeleton: public IMonster, public IHasMana {
private:
	using ShotType = Arrow;
	static size_t _startHp;
	static size_t _startMaxMana;
	static size_t _startDmg;
	static size_t _startSpeed;
	static size_t _startManaRegenSpeed;
	static size_t _startManaRegenStrong;
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

	friend SkeletonAI;

	// Унаследовано через IMonster
	virtual size_t getDmg() const override;
	virtual size_t getMaxHp() const override;
	virtual size_t getArmor() const override;

	// Унаследовано через IHasMana
	virtual size_t getMaxMana() const override;
	virtual void updateMana() override;
};
