#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"


class HeroAI : public IBaseAI {
  template <typename T, bool def = false>
  using EnableIfIsNotRealized =
      std::enable_if_t<
	  ((std::is_same<T, Zombie>::value)||
	  (std::is_same<T, Dragon>::value)||
	  (std::is_base_of_v<IProjectile, T>))
	  == def
	  , ComandList>;

  template <typename T>
  using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;

  Hero &hero;

 public:
  HeroAI(Hero &);
  ComandList getActions(const void *, size_t) override;

  template <class T>
  EnableIfIsNotRealized<T> ColideWith(Hero *, T *);
  template <class T>
  EnableIfIsRealized<T> ColideWith(Hero *, T *);
  ~HeroAI() override {};
};

template <class T>
HeroAI::EnableIfIsNotRealized<T> HeroAI::ColideWith(Hero *, T *) {
  return EnableIfIsNotRealized<T>();
}
