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


bool queue::push(const long VAR) {
  if (CurrentPositionInput == ARRAY_SIZE) {
    return 0;
  }
  array[++CurrentPositionInput] = VAR;
  return 1;
}
  
long queue::pop() {
  if (CurrentPositionInput < 0) {
    return 0; 
  }
  long Out = array[0];
  for (unsigned i = 0; i < (ARRAY_SIZE - 1); ++i) {
    array[i] = array[i + 1];
  }
  --CurrentPositionInput;
  return Out;
}