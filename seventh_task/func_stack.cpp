#include <iostream>

struct stackcell {
  long variable = 0;
  stackcell* PrevPtr = nullptr;
};

void push(long InputVar, stackcell** CurrentPtr) {
  if (nullptr == CurrentPtr) return;
  stackcell* NewCell = (stackcell*)malloc(sizeof(stackcell));
  NewCell->variable = InputVar;
  NewCell->PrevPtr = *CurrentPtr;
  *CurrentPtr = NewCell;
}

long pop(stackcell** CurrentPtr) {
  long Out = (*CurrentPtr)->variable;
  *CurrentPtr = (*CurrentPtr)->PrevPtr;
  return Out;
}

int main() {
  stackcell* CurrentCell = (stackcell*)calloc(1, sizeof(stackcell));
  CurrentCell->variable = 0;
  CurrentCell->PrevPtr = nullptr;
  
  push(12, &CurrentCell);
  std::cout << CurrentCell->variable << std::endl;
  push(14, &CurrentCell);
  std::cout << CurrentCell->variable << std::endl;
  push(45, &CurrentCell);
  std::cout << CurrentCell->variable << std::endl;
  push(67, &CurrentCell);
  std::cout << CurrentCell->variable << std::endl;

  std::cout << pop(&CurrentCell) << std::endl;
  std::cout << pop(&CurrentCell) << std::endl;
  std::cout << pop(&CurrentCell) << std::endl;
  std::cout << pop(&CurrentCell) << std::endl;
}