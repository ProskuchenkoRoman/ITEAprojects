#include "stack.hpp"

long stack::push(const long INPUT_VAR) {
  stackcell* NextPtr = (stackcell *)malloc(sizeof(stackcell));
  if (nullptr == NextPtr) return 0;
  (*NextPtr).variable = INPUT_VAR;
  (*NextPtr).PrevPtr = CurrentPtr;
  CurrentPtr = NextPtr;
  ++CurrentPosition;
  return CurrentPosition;
}

long stack::pop() {
  if (nullptr == CurrentPtr) return 0;
  long Out = (*CurrentPtr).variable;
  stackcell* MemoryForFree = CurrentPtr;
  CurrentPtr = (*CurrentPtr).PrevPtr;
  free(MemoryForFree);
  --CurrentPosition;
  return Out;
}

long stack::HowManyElements () const {
  return CurrentPosition;
}

long stack::top() const {
  if ((nullptr == CurrentPtr) || (0 == CurrentPosition)) return 0;
  return CurrentPtr->variable;
}