#include "queue.hpp"

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