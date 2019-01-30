#pragma once
#include "IBaseControler.h"
#include "pch.h"

class IBaseAI {


 public:
  virtual ComandList getActions(const void*, size_t) = 0;
  virtual ~IBaseAI() {};
};
