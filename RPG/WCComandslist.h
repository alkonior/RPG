#pragma once
#include "IBaseControler.h"
#include "Entities.h"

///Фабрика команд
#define defNewComad(comandName)            \
  class comandName : public IComand {      \
   public:                                 \
    IEntity* object;                       \
    comandName(IEntity* p) { object = p; } \
    void accept(BaseControler&) override;  \
  }

defNewComad(CForward);

class MoveMe : public IComand {
 public:
  IEntity* object;
  Point p;
  MoveMe(IEntity* o, Point p):p(p) { object =o; }
  void accept(BaseControler&) override;
};