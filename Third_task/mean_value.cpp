#include <iostream>

int main() {
  unsigned long int variable;
  std::cout << "Please, enter string of digits for computation of mean value: ";
  std::cin >> variable;
  unsigned int divider=10;
  unsigned int result=0;
  unsigned int counter=0;
  while (!(variable < divider/10)) {
    result += (variable % divider) / (divider / 10);
    ++counter;
    divider *= 10;
  }
  std::cout << "Mean value of digits: " << ((result + 0.) / counter);
}