#pragma once
#include "Entities.h"
#include "IBaseAI.h"
#include "Map.h"
#include "WCComandslist.h"

class FireBallAI:public IBaseAI {
private:
	template <typename T, bool def = false>
	using EnableIfIsNotRealized =
		std::enable_if_t<(((std::is_base_of_v<IProjectile, T>)||
        (std::is_base_of_v<IPerson, T>))
						  ==def)
		, ComandList>;
	template <typename T>
	using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;

	size_t step;
	FireBall& fireball;
	Point lastSee;
	bool searching;

public:
	FireBallAI(FireBall&);

	ComandList getActions(const void *, size_t) override;

	template <class T>
	EnableIfIsNotRealized<T> ColideWith(FireBall *, T *);
	template <class T>
	EnableIfIsRealized<T> ColideWith(FireBall *, T *);
	~FireBallAI();
};

template <class T>
FireBallAI::EnableIfIsNotRealized<T> FireBallAI::ColideWith(FireBall* f, T* t) {
	return { make_shared<DeleteEntity>(f) };
}
