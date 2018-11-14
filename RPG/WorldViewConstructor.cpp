#include "pch.h"
#include "WorldViewConstructor.h"
using namespace RPG;
using TEXTURES::Texture;
using TEXTURES::Point;
using std::vector;

RPG::ENGINE::WorldViewConstructor::WorldViewConstructor(Model& E):Engine(E){}

vector<vector<const Texture*>> RPG::ENGINE::WorldViewConstructor::GetInfo(Point, Point) const
{
	return vector<vector<const Texture*>>();
}
