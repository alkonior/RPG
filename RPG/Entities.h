#pragma once
#include <exception>
#include "IBaseAI.h"
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

class IEntity {
 protected:
  shared_ptr<IBaseAI> AI;

  const Texture& _t;
  Point _cord;

 public:
  virtual ComandList _colide(IEntity*) = 0;
  virtual ComandList _colide(Hero*) = 0;
  virtual ComandList _colide(Wall*) = 0;
  virtual ComandList _colide(Zombie*) = 0;

 public:
  IEntity(Point, const Texture&, shared_ptr<IBaseAI>);
  const Texture& getTexture();
  ComandList colide(IEntity* in) {
    if (in != nullptr) return in->_colide(this);
    return ComandList();
  }
  static void Init(json&) { throw new std::exception("Not inited class"); }

  shared_ptr<IBaseAI>& getAI() { return AI; }

  const Point getCord() { return _cord; }
  void setCord(Point p) { _cord = p; }
};

class IPerson : public IEntity {
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

class INotPerson : public IEntity {
  size_t damage;
  size_t speed;

 public:
  INotPerson(Point, const Texture&);
};

class Hero : public IPerson {
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
  ComandList _colide(IEntity*) override;
  ComandList _colide(Hero*) override;
  ComandList _colide(Wall*) override;
  ComandList _colide(Zombie*) override;
};

class Monster : public IPerson {
 public:
  Monster(Point, const Texture&, shared_ptr<IBaseAI>);
};

class Zombie : public Monster {
 private:
  static size_t _startHp;
  static size_t _startMana;
  static size_t _startDmg;
  static size_t _startSpeed;
  static size_t _startArmor;

 public:
  Zombie(Point);
  static void Init(json&);

  ComandList _colide(IEntity*) override;
  ComandList _colide(Hero*) override;
  ComandList _colide(Wall*) override;
  ComandList _colide(Zombie*) override;
};

class Dragon : public Monster {};

class Princess : public IPerson {};

class Wall : public INotPerson {
 public:
  ComandList _colide(IEntity*) override;
  ComandList _colide(Hero*) override;
  ComandList _colide(Wall*) override;
  ComandList _colide(Zombie*) override;

  Wall(Point);
};

class FireBall : public INotPerson {
  size_t direction;
  /*void _colide(I_Entity& in) override;
  void _colide(Hero&) override;
  void _colide(Monster&) override;
  void _colide(Zombie&) override;
  void _colide(Dragon&) override;
  void _colide(Princess&) override;
  void _colide(Wall&) override;*/
};

class Arrow : public INotPerson {
  size_t direction;
  /*void _colide(I_Entity& in) override;
  void _colide(Hero&) override;
  void _colide(Monster&) override;
  void _colide(Zombie&) override;
  void _colide(Dragon&) override;
  void _colide(Princess&) override;
  void _colide(Wall&) override;*/
};

class Apteca : public INotPerson {
  /*void _colide(I_Entity& in) override;
  void _colide(Hero&) override;
  void _colide(Monster&) override;
  void _colide(Zombie&) override;
  void _colide(Dragon&) override;
  void _colide(Princess&) override;
  void _colide(Wall&) override;*/
};
