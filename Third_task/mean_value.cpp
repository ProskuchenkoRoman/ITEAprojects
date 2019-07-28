#include <iostream>
#include <cstdlib>


int main() {
  unsigned long int variable;
  std::cout << "Please, enter string of digits for computation of mean value: ";
  std::cin >> variable;
  std::cout << "\n";
  int divider=10;
  unsigned int result=0;
  int counter=0;
  while (true) {
    if (variable < divider/10) {
      break;
    }
    
    int tmp = (variable % divider) / (divider / 10);
    std::cout << tmp << "\n";
    result = result + tmp;
    counter++;
    divider = divider * 10;
  }
  std::cout << "Mean value of digits: ";
  std::cout << ((result + 0.) / counter);
}