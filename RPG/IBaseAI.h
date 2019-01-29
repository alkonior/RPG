#pragma once
#include "IBaseControler.h"
#include "pch.h"


class IBaseAI {
 public:
  virtual ComandList getActions(const void*, const void*, size_t) const = 0;
};

