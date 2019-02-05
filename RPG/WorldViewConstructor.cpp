#include "pch.h"
#include "WorldViewConstructor.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))

bool WorldViewConstructor::existPoint(const Point in) const
{
	return in.x < World->width && in.y < World->height;;
}

WorldViewConstructor::HeroInfo WorldViewConstructor::getHeroInfo() const
{
	return {World->hero.lock()->getHp(),
		World->hero.lock()->getMp(),
		World->hero.lock()->getMaxHp(),
		World->hero.lock()->getMaxMp() };
}

WorldViewConstructor::WorldViewConstructor(const shared_ptr<Map> w):World(w),worldShift(0,0){}

vector<vector<const Texture*>> WorldViewConstructor::GetMapInfo(size_t w, size_t h) const
{
	vector<vector<const Texture*>> out(h, vector<const Texture*>(w));
	worldShift = World->hero.lock()->getCord()-Point(w/2, h/2);
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			auto curP = worldShift+Point(j, i);
			if (existPoint(curP))
			{
				out[i][j] =//≈сли не nullptr то вернуть текстуру иначе пол
					(*World)[curP]
					? &(*World)[curP]->getTexture()
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

WorldViewConstructor::HeroInfo::HeroInfo(size_t h, size_t m, size_t mh, size_t mm):Hp(h),Mp(m),
MaxHp(mh),MaxMp(mm)
{
}
