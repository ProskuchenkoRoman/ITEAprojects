#include <iostream>

int main() {
  unsigned long int variable;
  
  short int left_sum = 0;
  short int right_sum = 0;
  std::cout << "Please, enter number of your ticket: ";
  std::cin >> variable;
  while (!((variable / 100000) < 10 && ((int)(variable/100000)) >= 1 )) {
    std::cout << "Please, enter valid number of ticket: ";
    std::cin >> variable;
  }
  unsigned int divider = 10;
  for (unsigned int counter=0;counter < 3; ++counter) {
    unsigned int tmp = (variable % divider) / (divider / 10);
    left_sum = left_sum + tmp;
    divider = divider * 10;
  }
  for (unsigned int counter = 3;counter < 6; ++counter) {
    unsigned int tmp = (variable % divider) / (divider / 10);
    right_sum = right_sum + tmp;
    divider = divider * 10;
  }
std::cout << ((left_sum == right_sum) ?
                    "Congratulations!!! This is LUCKY ticket!!! \n" :
                    "Unfortunately... it isn't lucky ticket... \n");
}