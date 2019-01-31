#include "pch.h"
#include "FireBallAI.h"



FireBallAI::~FireBallAI()
{
}

FireBallAI::FireBallAI(FireBall & f):fireball(f)
{
}

ComandList FireBallAI::getActions(const void *, size_t)
{
	return ComandList();
}

template <>
ComandList FireBallAI::ColideWith<>(FireBall* f1, FireBall* f2) {
	return { make_shared<DeleteEntity>(f1),
	 make_shared<DeleteEntity>(f2) };
}
template <>
ComandList FireBallAI::ColideWith<>(FireBall* f1,Arrow* f2) {
	return { make_shared<DeleteEntity>(f1),
	 make_shared<DeleteEntity>(f2) };
}

template <>
ComandList FireBallAI::ColideWith<>(FireBall* f, Dragon* d) {
	return { make_shared<DeleteEntity>(f) };
}

template <>
ComandList FireBallAI::ColideWith<>(FireBall* f, Hero* h) {
	return { make_shared<Attack_Porjectile>(f,h) };
}

template <>
ComandList FireBallAI::ColideWith<>(FireBall* f, Zombie* z) {
	return { make_shared<Attack_Porjectile>(f,z) };
}


