#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"

class ArrowAI: public IBaseAI {
private:
	template <typename T, bool def = false>
	using EnableIfIsNotRealized =
		std::enable_if_t<(((std::is_same_v<T, Skeleton>)||
		(std::is_base_of_v<IProjectile, T>))==def), ComandList>;
	template <typename T>
	using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;



	size_t step;
	Arrow& arrow;
	Point lastSee;
	bool searching;

public:
	ArrowAI(Arrow &);
	// Унаследовано через IBaseAI
	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfIsNotRealized<T> ColideWith(Zombie *, T *);
	template <class T>
	EnableIfIsRealized<T> ColideWith(Zombie *, T *);
	~ArrowAI();
};

template <class T>
ArrowAI::EnableIfIsNotRealized<T> ArrowAI::ColideWith(Zombie *, T *) {
	return EnableIfIsNotRealized<T>();
}
