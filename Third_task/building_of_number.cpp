#include <iostream>

int main() {
  std::cout << "This program checking numbers which we can combine into one number.\n";
  std::cout << "If you will see response Yes it will meen that you can divide number, that was created from input numbers, by 3.\n";
  std::cout << "Please, enter amount of numbers: ";
  int amount;
  int result = 0;
  std::cin >> amount;
  std::cout << "Please, enter your numbers:\n";
  for (size_t i = 0; i < amount; ++i) {
    int variable;
    std::cin >> variable;
    int divider=10;
    while (!(variable < divider/10)) {
      result = result + (variable % divider) / (divider / 10);
      divider = divider * 10;
    }
  }
  std::cout << (!(result % 3) ? "Yes" : "No");
}