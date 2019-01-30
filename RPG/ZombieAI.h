#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"
#include "pch.h"



class ZombieAI : public IBaseAI {
 private: 
  template <typename T, bool def = false>
  using EnableIfIsNotRealized =
      std::enable_if_t<(std::is_same<T, Hero>::value == def), ComandList>;
  template <typename T>
  using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;



  size_t step;
  Zombie &zombie;
  Point lastSee;
	

 public:
  ZombieAI(Zombie &);
  // Унаследовано через IBaseAI
  ComandList getActions(const void *, size_t) override;

  template <class T>
  EnableIfIsNotRealized<T> ColideWith(Zombie *, T *);
  template <class T>
  EnableIfIsRealized<T> ColideWith(Zombie *, T *);
};

template <class T>
ZombieAI::EnableIfIsNotRealized<T> ZombieAI::ColideWith(Zombie *, T *) {
  return EnableIfIsNotRealized<T>();
}