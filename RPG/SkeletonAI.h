#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"


class SkeletonAI:public IBaseAI
{
	static shared_ptr<IProjectile> generator(Point p, Point dir);

	static shared_ptr<Shoot::func_t> func;


	template <typename T>
	using EnableIfNothing =
		std::enable_if_t<(std::is_base_of_v<IPerson, T>||std::is_base_of_v<INotPerson, T>), ComandList>;

	template <typename T>
	using EnableIfProjectile =
		std::enable_if_t<(std::is_base_of_v<IProjectile, T>&&!std::is_same_v<Skeleton::ShotType, T>), ComandList>;

	template <typename T>
	using EnableIfImuneProjectile =
		std::enable_if_t<(std::is_same_v<Skeleton::ShotType, T>), ComandList>;

	size_t step;
	Skeleton* skeleton;

public:
	SkeletonAI(Skeleton*);
	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfNothing<T> ColideWith(Skeleton *, T *)
	{
		return {};
	}

	template <class T>
	EnableIfImuneProjectile<T> ColideWith(Skeleton*, T* t)
	{
		return { make_shared<DeleteEntity>(t) };
	}

	template <class T>
	EnableIfProjectile<T> ColideWith(Skeleton* s, T*  t)
	{
		return { make_shared<Attack_A_to_B>(t,s),make_shared<DeleteEntity>(t) };
	}


	~SkeletonAI()override {};
};

