#include "pch.h"
#include "HeroAI.h"


HeroAI::HeroAI(Hero &h) : hero(h) {}

ComandList HeroAI::getActions(const void * w, const void *, size_t comand) const {
  const Map *world = static_cast<const Map *>(w);
  vector<shared_ptr<IComand>> out;
  switch (comand) {
    case 'w': {
      out.push_back(make_shared<MoveMe>(&hero,Point(0,-1)));
      break;
    }
    case 's': {
      out.push_back(make_shared<MoveMe>(&hero,Point(0,1)));
      break;
    }
    case 'd': {
      out.push_back(make_shared<MoveMe>(&hero, Point(1,0)));
      break;
    }
    case 'a': {
      out.push_back(make_shared<MoveMe>(&hero,Point(-1,0)));
      break;
    }
    default:
      break;
  }
  return out;
}

/**/
