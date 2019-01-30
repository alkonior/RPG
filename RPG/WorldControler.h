#pragma once
#include <exception>
#include <iostream>
#include "IBaseControler.h"
#include "Map.h"
#include "Model.h"
#include "WCComandslist.h"
#include "pch.h"

class WorldControler : public BaseControler {
  template <typename T, bool def = false>
  using EnableIfIsNotRealized =
      std::enable_if_t<
	  ((std::is_same<T, MoveMe>::value )||
      (std::is_same<T, Attack_A_to_B>::value) ||
      (std::is_same<T, CheckEntityHp>::value) ||
      (std::is_same<T, CForward>::value ))==def
	  , void>;

  template <typename T>
  using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;

  Map& World;
  vector<ComandList> _ComandList;
  void executeAll();

 public:
  WorldControler(Model&);
  void GetComand(size_t);



  template <class T>
  EnableIfIsNotRealized<T> execute(const T*);

  template <class T>
  EnableIfIsRealized<T> execute(const T*);

  void _execute() override{};
  
};

template <class T>
WorldControler::EnableIfIsNotRealized<T> WorldControler::execute(const T*) {
  throw new std::exception("Not Implemented Comand");
}