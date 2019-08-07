#include <iostream>
#include <cmath>

int main() {
  long variable;
  std::cout << "Please, enter value which you want revers(ex. 321 => 123): ";
  std::cin >> variable;
  unsigned long divider=10;
  int counter=0;
  long rev_val = 0;
  bool negative = false;
  if (variable < 0) {
    variable *=-1;
    negative = true;
  }
  while ((int)(variable/pow(10,counter))) {
  ++counter;
  }
  divider = 10;
  while (counter>=0) {
    rev_val +=((variable % divider) / (divider / 10)) * pow(10,counter);
    --counter;
    divider *= 10;
  }
  rev_val = (rev_val + 1)/10;
  rev_val = negative ? -rev_val : rev_val;
  std::cout << "\n" << rev_val;
}