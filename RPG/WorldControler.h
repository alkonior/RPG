#pragma once
#include <exception>
#include <iostream>
#include "IBaseControler.h"
#include "Map.h"
#include "Model.h"
#include "WCComandslist.h"
#include "pch.h"

class WorldControler : public IBaseControler {

  Map& World;
  vector<ComandList> _ComandList;
  void executeAll();

 public:
  WorldControler(Model&);
  void GetComand(size_t);

  template <class T>
  void execute(const T*);

  void _execute() override{};
  
};


