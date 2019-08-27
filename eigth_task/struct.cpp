#include <iostream>

struct stackcell {
  long variable = 0;
  stackcell* PrevPtr = nullptr;
};

class stack {
  public:
  long push(long InputVar) {
    stackcell* NextPtr = (stackcell *)malloc(sizeof(stackcell));
    if (nullptr == NextPtr) {
      return 0;
    }
    (*NextPtr).variable = InputVar;
    (*NextPtr).PrevPtr = CurrentPtr;
    CurrentPtr = NextPtr;
    ++CurrentPosition;
    return CurrentPosition;
  }
  long pop() {
    if (nullptr == CurrentPtr) {
      return 0;
    }
    long Out = (*CurrentPtr).variable;
    stackcell* MemoryForFree = CurrentPtr;
    CurrentPtr = (*CurrentPtr).PrevPtr;
    free(MemoryForFree);
    --CurrentPosition;
    return Out;
  }
  long HowManyElements () const {
    return CurrentPosition;
  }
  private:
  stackcell* CurrentPtr = nullptr;
  unsigned long CurrentPosition = 0;
};

class queue {
public:
  bool push(long a) {
    if (CurrentPositionInput == ARRAY_SIZE) {
      return 0;
    }
    array[++CurrentPositionInput] = a;
    return 1;
  }
  
  long pop() {
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
private:
  static const unsigned short ARRAY_SIZE = 255;
  long array[ARRAY_SIZE] {};
  short CurrentPositionInput = -1;
  short CurrentPositionOutput = -1;
};

int main() { 
  stack stack;
  queue queue;
  std::cout << stack.push(12) << '\n';
  std::cout << stack.push(13) << '\n';
  std::cout << stack.push(14) << '\n';

  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << "Queue\n";
  std::cout << queue.push(12) << '\n';
  std::cout << queue.push(14)  << '\n';
  std::cout << queue.push(15) << '\n';
  std::cout << queue.pop() << '\n';
  std::cout << queue.pop() << '\n';
  std::cout << queue.pop() << '\n';
  std::cout << queue.pop() << '\n';
}