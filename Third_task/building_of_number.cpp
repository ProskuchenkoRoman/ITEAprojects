#include <iostream>

int main() {
  std::cout << "Please, enter amount of numbers: ";
  int amount;
  int result = 0;
  int variable = 0;
  std::cin >> amount;
  for (;amount > 0;--amount) {
    std::cin >> variable;
    int divider=10;
    while (true) {
      if (variable < divider/10) {
        break;
      }
      result = result + (variable % divider) / (divider / 10);
      divider = divider * 10;
    }
  }
  !(result % 3) ? std::cout << "Yes" : std::cout << "No";
}