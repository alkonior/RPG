#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"




class DragonAI:public IBaseAI
{
	static shared_ptr<IProjectile> generator(Point p, Point dir);

	template <typename T>
	using EnableIfNothing =
		std::enable_if_t<(std::is_base_of_v<IMonster,T>||std::is_base_of_v<INotPerson, T>), ComandList>;

	template <typename T>
	using EnableIfProjectile =
		std::enable_if_t<(std::is_base_of_v<IProjectile,T>&&!std::is_same_v<Dragon::ShotType,T>), ComandList>;	
	
	template <typename T>
	using EnableIfImuneProjectile =
		std::enable_if_t<(std::is_same_v<Dragon::ShotType,T>), ComandList>;	
	
	template <typename T>
	using EnableIfHero =
		std::enable_if_t<(std::is_same_v<Hero, T>), ComandList>;

	size_t step;
	Point lastSee;
	Dragon* dragon;
	bool searching;

public:
	DragonAI(Dragon*);
	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfNothing<T> ColideWith(Dragon *, T *) { return ComandList(); }
	
	template <class T>
	EnableIfImuneProjectile<T> ColideWith(Dragon *, T * t) { return { make_shared<DeleteEntity>(t) }; }

	template <class T>
	EnableIfProjectile<T> ColideWith(Dragon *d, T * t) { return { make_shared<Attack_Porjectile>(d,t) }; }

	template <class T>
	EnableIfHero<T> ColideWith(Dragon *, T *);

	~DragonAI()override{};
};

