#include <iostream>

int main() {
  unsigned long int variable;
  int divider = 10;
  short int left_sum = 0;
  short int right_sum = 0;
  std::cout << "Please, enter number of your ticket: ";
  std::cin >> variable;
  std::cout << "\n";
  for (int counter=0;counter < 6; ++counter) {
    int tmp = (variable % divider) / (divider / 10);
    if (counter < 3) {
      left_sum = left_sum + tmp;
    } else {
      right_sum = right_sum + tmp;
    }
    divider = divider * 10;
  }
  if (left_sum == right_sum) {
    std::cout << "Congratulations!!! This is LUCKY ticket!!!";
  } else {
    std::cout << "Unfortunately... it isn't lucky ticket...";
  }
}