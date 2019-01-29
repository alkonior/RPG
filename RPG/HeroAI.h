#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"
#include "pch.h"



class HeroAI : public IBaseAI {
  Hero &hero;
 public:
  HeroAI(Hero&);

  // Унаследовано через IBaseAI
  ComandList getActions(const void *, const void *, size_t) const override;
  // virtual vector<shared_ptr<IComand>> getActions(const void *, const void *,
  // size_t) override;
};

