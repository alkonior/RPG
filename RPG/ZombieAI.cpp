#include "pch.h"
#include "ZombieAI.h"


ZombieAI::ZombieAI(Zombie& z) : zombie(z) {}

ComandList ZombieAI::getActions(const void* w, size_t) {
  step++;
  ComandList out;
  if (step >= zombie._speed) {
    step = 0;
    const Map& world = *static_cast<const Map*>(w);
    if (zombie._cord.distance(world.hero->getCord()) <= 5) {
      lastSee = world.hero->getCord();
    }
    if (zombie._cord.distance(lastSee) > 0) {
      out.push_back(make_shared<MoveMe>(&zombie, zombie._cord.betsDir(lastSee)));
    } else {
      vector<Point> dir{Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)};
      out.push_back(make_shared<MoveMe>(&zombie,zombie._cord.betsDir(dir[rand() % 4])));
    }
  }

  return out;
}

template <>
ComandList ZombieAI::ColideWith<>(Zombie* Z, Hero* H) {
  ComandList out;
  out.push_back(make_shared<Attack_A_to_B>(Z, H));
  return out;
}
