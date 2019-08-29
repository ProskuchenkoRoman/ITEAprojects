#include <iostream>

template<typename Type>
struct stackcell {
  Type variable = 0;
  stackcell* PrevPtr = nullptr; // Вопрос: почему так работает?) stackcell* Оно видит скоуп структуры и работает с названием структуры в скоупе?
};

template<typename Type>
class stack {
  public:
  unsigned long push(Type InputVar) {
    stackcell<Type>* NextPtr = (stackcell<Type>*)malloc(sizeof(stackcell<Type>));
    if (nullptr == NextPtr) {
      return 0;
    }
    (*NextPtr).variable = InputVar;
    (*NextPtr).PrevPtr = CurrentPtr;
    CurrentPtr = NextPtr;
    ++CurrentPosition;
    return CurrentPosition;
  }
  Type pop() {
    if (nullptr == CurrentPtr) {
      return 0;
    }
    Type Out = (*CurrentPtr).variable;
    stackcell<Type>* MemoryForFree = CurrentPtr;
    CurrentPtr = (*CurrentPtr).PrevPtr;
    free(MemoryForFree);
    --CurrentPosition;
    return Out;
  }
  Type HowManyElements () const {
    return CurrentPosition;
  }
  private:
  stackcell<Type>* CurrentPtr = nullptr;
  unsigned long CurrentPosition = 0;
};

int main() { 
  stack<float> stack;
  std::cout << "Stack:" << '\n';
  std::cout << stack.push(12.1) << '\n';
  std::cout << stack.push(13.1) << '\n';
  std::cout << stack.push(14.1) << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
  std::cout << stack.HowManyElements() << '\n';
  std::cout << stack.pop() << '\n';
}