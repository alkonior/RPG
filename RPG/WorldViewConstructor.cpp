#include "pch.h"
#include "WorldViewConstructor.h"
using namespace RPG;
using namespace TEXTURES;
using std::vector;

bool RPG::ENGINE::WorldViewConstructor::existPoint(const Point in) const
{
	return in.x < World.w && in.y <World.h;;
}

RPG::ENGINE::WorldViewConstructor::WorldViewConstructor(Model& E):World(E.World)
{

}

vector<vector<const Texture*>> RPG::ENGINE::WorldViewConstructor::GetWorldInfo(size_t w, size_t h) const
{
	vector<vector<const Texture*>> out(h, vector<const Texture*>(w));
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			if (existPoint(worldShift + Point(j, i)))
			{
				out[i][j] =//≈сли не nullptr то вернуть текстуру иначе пол
					World.World[i + worldShift.y][j + worldShift.x]
					? &World.World[i + worldShift.y][j + worldShift.x]->getTexture()
					: &TEXTURES_ARAAY::T_Floor;
			}
			else
			{
				out[i][j] = &TEXTURES_ARAAY::T_Zero;
			}
		}
	}
	return out;
}
