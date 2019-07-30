#include <iostream>

int main() {
  unsigned long int variable;
  int shift = 0; // Почему то с char не работает.
  std::cout << "Please, enter variable and possition of bit which you want know: ";
  std::cin >> variable;
  std::cin >> shift;
  std::cout << "\n";
  if ((variable >> (shift - 1)) & 1) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}