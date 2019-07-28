#include <iostream>
#include <cstdlib>


int main() {
  signed long int variable;
  std::cout << "Please, enter value which you want revers(ex. 321 => 123): ";
  std::cin >> variable;
  std::cout << "\n";
  int divider=10;
  unsigned int result=0;
  int counter=0;
  bool negative = false;
  if (variable < 0) {
    variable = variable * (-1);
    negative = true;
  }
  while (true) {
    if (variable < divider/10) {
      break;
    }
    int tmp = (variable % divider) / (divider / 10);
    if (negative) {
      std::cout << "-";
      std::cout << tmp;
      negative = !negative;
    } else {
      std::cout << tmp;
    }
    counter++;
    divider = divider * 10;
  }
}