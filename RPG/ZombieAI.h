#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"


class ZombieAI: public IBaseAI {
private:
	template <typename T>
	using EnableIfNothing =
		std::enable_if_t<(std::is_base_of_v<IMonster, T>||std::is_base_of_v<INotPerson, T>), ComandList>;

	template <typename T>
	using EnableIfProjectile =
		std::enable_if_t<(std::is_base_of_v<IProjectile, T>), ComandList>;

	template <typename T>
	using EnableIfHero =
		std::enable_if_t<(std::is_same_v<Hero, T>), ComandList>;



	size_t step;
	Zombie &zombie;
	Point lastSee;
	bool searching;

public:
	ZombieAI(Zombie &);
	// Унаследовано через IBaseAI
	ComandList getActions(const void *, size_t) override;


	template <class T>
	EnableIfNothing<T> ColideWith(Zombie *, T *)
	{
		return {};
	}

	template <class T>
	EnableIfProjectile<T> ColideWith(Zombie *z, T * t)
	{
		return { make_shared<Attack_A_to_B>(t,z), make_shared<DeleteEntity>(t) };
	}

	template <class T>
	EnableIfHero<T> ColideWith(Zombie *, T *);
};
