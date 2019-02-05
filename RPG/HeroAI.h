#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include <map>
#include <functional>
#include "WCComandslist.h"


class HeroAI: public IBaseAI {

	std::map<char, shared_ptr<IComand>> Comands;

	static shared_ptr<IProjectile> generator(Point p, Point dir);
	template <typename T>
	static inline constexpr bool is_special_v = 
		std::is_same_v<Princess, T>||
		std::is_same_v<Apteca, T>;

	template <typename T>
	using EnableIfNothing =
		std::enable_if_t<(!is_special_v<T> &&
						  std::is_base_of_v<INotPerson, T>||std::is_same_v<Hero,T>), ComandList>;

	template <typename T>
	using EnableIfProjectile =
		std::enable_if_t<(std::is_base_of_v<IProjectile, T>), ComandList>;


	template <typename T>
	using EnableIfMonster =
		std::enable_if_t<(std::is_base_of_v<IMonster, T>), ComandList>;

	template <typename T>
	using EnableIfSpecial =
		std::enable_if_t<(is_special_v<T>), ComandList>;

	Hero* hero;

public:
	HeroAI(Hero*);
	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfNothing<T> ColideWith(Hero*, T*) 
	{ return {}; };

	template <class T>
	EnableIfMonster<T> ColideWith(Hero* h, T* t)
	{ return { make_shared<Attack_A_to_B>(h, t) }; }

	template <class T>
	EnableIfProjectile<T> ColideWith(Hero* h, T* t)
	{ 
		Point cord = t->getCord();
		return { 
		make_shared<Attack_A_to_B>(t,h), 
		make_shared<DeleteEntity>(t),
		make_shared<MoveMe>(h,h->getCord().betsDir(cord))
	}; 
	}

	template <class T>
	EnableIfSpecial<T> ColideWith(Hero*, T* );


	~HeroAI() override {};
};


