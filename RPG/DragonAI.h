#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"




class DragonAI:public IBaseAI
{
	template <typename T, bool def = false>
	using EnableIfIsNotRealized =
		std::enable_if_t<((std::is_same<T, Hero>::value)==def), ComandList>;

	template <typename T>
	using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;
	size_t step;
	Point lastSee;
	Dragon &dragon;
	bool searching;
public:
	DragonAI(Dragon& );
	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfIsNotRealized<T> ColideWith(Dragon *, T *);
	template <class T>
	EnableIfIsRealized<T> ColideWith(Dragon *, T *);

	~DragonAI()override {};
};

template<class T>
DragonAI::EnableIfIsNotRealized<T> DragonAI::ColideWith(Dragon *, T *)
{
	return EnableIfIsNotRealized<T>();
}
