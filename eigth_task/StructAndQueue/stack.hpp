#pragma once
#include "data.hpp"

class stack {
  public:
  long push(long InputVar);
  long pop();
  long HowManyElements () const;
  long top() const;
  private:
  stackcell* CurrentPtr = nullptr;
  unsigned long CurrentPosition = 0;
};