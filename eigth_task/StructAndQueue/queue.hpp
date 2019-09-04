#pragma once
#include "data.hpp"

class queue {
public:
  bool push(long a);
  long pop();
private:
  static const unsigned short ARRAY_SIZE = 255;
  long array[ARRAY_SIZE] {};
  short CurrentPositionInput = -1;
  short CurrentPositionOutput = -1;
};