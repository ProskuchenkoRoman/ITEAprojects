#include <iostream>

int main() {
  unsigned long int variable;
  unsigned char shift = 0;
  unsigned short int counter = 0;
  std::cout << "Please, enter variable in which I should count setted bits: ";
  std::cin >> variable;
  std::cout << "\n";
  while (variable>>shift) {
    if ((variable >> shift) & 1) {
      counter++;
    }
    shift++;
  }
  std::cout << "Number of setted bits: ";
  std::cout << counter;
}