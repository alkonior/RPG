#pragma once
#include <exception>
#include <iostream>
#include "IBaseControler.h"
#include "Map.h"
#include "WCComandslist.h"
#include "pch.h"

class WorldControler : public IBaseControler {

  shared_ptr<Map> World;
  vector<ComandList> _ComandList;
  void executeAll();

 public:
  WorldControler(shared_ptr<Map>);
  void GetComand(size_t);

  template <class T>
  void execute(const T*);

  void _execute() override{};
  
};


