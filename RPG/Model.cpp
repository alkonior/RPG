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
	_WC.GetComand(c);
	return 0;
}

const WVC & Model::getData() const
{
	return _WVC;
}


Model::~Model()
{
}
