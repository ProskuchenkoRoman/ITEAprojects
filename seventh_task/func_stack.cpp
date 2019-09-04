#include <iostream>

//g++ -std=c++14 -Wall -Werror -pedantic -O2  func_stack.cpp

struct stackcell {
  long variable = 0;
  stackcell* PrevPtr = nullptr;
};

void push(const long INPUT_VAR, stackcell*& CurrentPtr) {
  if (nullptr == CurrentPtr) {
    CurrentPtr = (stackcell*)malloc(sizeof(stackcell));
    CurrentPtr->variable = INPUT_VAR;
    CurrentPtr->PrevPtr = nullptr;
    return;
  }
  stackcell* NewCell = (stackcell*)malloc(sizeof(stackcell));
  NewCell->variable = INPUT_VAR;
  NewCell->PrevPtr = CurrentPtr;
  CurrentPtr = NewCell;
}

long pop(stackcell*& CurrentPtr) {
  if (nullptr == CurrentPtr) {
    std::cout << "Stack is empty. Try to push something.\n";
    return false;
  }
  long Out = CurrentPtr->variable;
  stackcell* MemoryForFree = CurrentPtr;
  CurrentPtr = CurrentPtr->PrevPtr;
  free(MemoryForFree);
  return Out;
}

long top(stackcell*& CurrentPtr) {
  if (nullptr == CurrentPtr) return false;
  return CurrentPtr->variable;
}

int main() {
  stackcell* CurrentCell = nullptr;
  pop(CurrentCell);
  push(12, CurrentCell);
  std::cout << top(CurrentCell) << std::endl;
  push(14, CurrentCell);
  std::cout << top(CurrentCell) << std::endl;
  push(45, CurrentCell);
  std::cout << top(CurrentCell) << std::endl;
  push(67, CurrentCell);
  std::cout << top(CurrentCell) << std::endl;

  std::cout << pop(CurrentCell) << std::endl;
  std::cout << pop(CurrentCell) << std::endl;
  std::cout << pop(CurrentCell) << std::endl;
  std::cout << pop(CurrentCell) << std::endl;
}