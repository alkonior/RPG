#include "pch.h"
#include "Model.h"


vector<std::string> getMap(json& map)
{
	vector<std::string> out;
	for (std::string i : map)
	{
		out.push_back(i);
	}
	return out;
}

Model::Model(json& config)
	:_World(shared_ptr<Map>(new Map(getMap(config["map"]), config))),_WC(_World),_WVC(_World)
{}

size_t Model::getComand(size_t c)
{
	size_t res = _WC.GetComand(c);
	if (res == 'n')
	return 0;
	if (res == 'w')
	return 1;
	if (res == 'l')
	return 2;
}

const WVC & Model::getData() const
{
	return _WVC;
}


Model::~Model()
{
}
