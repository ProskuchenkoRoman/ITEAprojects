#include <iostream>
#include "stack.hpp"
#include "stack.cpp"
#include "queue.hpp"
#include "queue.cpp"

//g++ -std=c++14 -Wall -Werror -pedantic -O2  main.cpp

int main() { 
  stack stack;
  queue queue;
  std::cout << stack.push(12) << '\n';
  std::cout << stack.top() << '\n';
  std::cout << stack.push(13) << '\n';
  std::cout << stack.top() << '\n';
  std::cout << stack.push(14) << '\n';
  std::cout << stack.top() << '\n';
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