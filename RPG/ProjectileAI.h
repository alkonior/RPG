#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"
template<class T>
class ProjectileAI:public IBaseAI {
private:
	using imune_person = T;

	template <typename T>
	using EnableIfNothing =
		std::enable_if_t<(
			!((std::is_base_of_v<IProjectile, T>)||(std::is_base_of_v<IPerson, T>))
			||std::is_same_v<T, imune_person>
			||std::is_base_of_v<INotPerson, T>
			)
		, ComandList>;

	template <typename T>
	using EnableIfProjectile =
		std::enable_if_t<(std::is_base_of_v<IProjectile, T>), ComandList>;

	template <typename T>
	using EnableIfPerson =
		std::enable_if_t<(std::is_base_of_v<IPerson, T>&&!std::is_same_v<T, imune_person>), ComandList>;

	size_t step;
	IProjectile* projectile;
	Point lastSee;
	bool searching;

public:
	ProjectileAI(IProjectile* p):projectile(p) {};

	ComandList getActions(const void *, size_t) override;


	template <class T>
	EnableIfPerson<T> ColideWith(IProjectile* p, T* t)
	{
		return { make_shared<Attack_A_to_B>(p,t), make_shared<DeleteEntity>(p) };
	}

	template <class T>
	EnableIfNothing<T> ColideWith(IProjectile* f, T *)
	{
		return { make_shared<DeleteEntity>(f) };
	}

	template <class T>
	EnableIfProjectile<T> ColideWith(IProjectile* f, T *t)
	{
		return { make_shared<DeleteEntity>(f),
		make_shared<DeleteEntity>(t), };
	}

};

template<class T>
ComandList ProjectileAI<T>::getActions(const void *, size_t)
{
	if (step++>=projectile->getSpeed())
	{
		step = 0;
		return { make_shared<MoveMe>(projectile,projectile->getDir()) };
	}
	return ComandList();
}
