#include <iostream>

int main() {
  unsigned long int variable;
  uint8_t shift = 0;
  unsigned short counter = 0;
  std::cout << "Please, enter variable in which I should count setted bits: ";
  std::cin >> variable;
  while (int value = variable >> shift) {
    counter += value & 1;
    ++shift;
  }
  std::cout << "Number of setted bits: " << counter;
}