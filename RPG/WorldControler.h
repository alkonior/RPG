#pragma once
#include <exception>
#include <iostream>
#include "IBaseControler.h"
#include "Map.h"
#include "Model.h"
#include "WCComandslist.h"
#include "pch.h"

class WorldControler : public IBaseControler {
	/*
  template <typename T, bool def = false>
  using EnableIfIsNotRealized =
      std::enable_if_t<
	  ((std::is_same<T, MoveMe>::value )||
      (std::is_same<T, Shoot>::value) ||
      (std::is_same<T, IfCanMoveMe>::value) ||
      (std::is_same<T, CheckEntityHp>::value) ||
      (std::is_same<T, CForward>::value ))==def
	  , void>;

  template <typename T>
  using EnableIfIsRealized = EnableIfIsNotRealized<T, true>;
  */

  Map& World;
  vector<ComandList> _ComandList;
  void executeAll();

 public:
  WorldControler(Model&);
  void GetComand(size_t);


  /*
  template <class T>
  EnableIfIsNotRealized<T> execute(const T*);

  template <class T>
  EnableIfIsRealized<T> execute(const T*);
  */
 /* 
  template <class T>
  void execute(const T*) {};
  */
  //template <class A, class B>
  //void execute(const Attack_A_to_B<A, B>* comand) {
	 // //A* a = (comand->A);
	 // //B* b = (comand->B);
	 // //if (b->getDmg(a)) {
		// // _ComandList.push_back(ComandList({ make_shared<CheckEntityHp>(b->getCord()) }));
	 // //}
  //}
  void _execute() override{};
  


};


