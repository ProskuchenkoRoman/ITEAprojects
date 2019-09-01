#pragma once


struct stackcell {
  long variable = 0;
  stackcell* PrevPtr = nullptr;
};

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