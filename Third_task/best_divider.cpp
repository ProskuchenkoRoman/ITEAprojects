#include <iostream>

int it_is_even_num (int var) {
  if (var % 2) {
    return 0;
  } else {
    return 1;
  }
}

int sum_of_digits(unsigned long int variable) {
  unsigned int divider=10;
  unsigned int result=0;
  while (true) {
    if (variable < divider/10) {
      break;
    }
    result = result + (variable % divider) / (divider / 10);
    divider = divider * 10;
  }
  return result;
}

int main() {
  int number,counter;
  std::cout << "Please, enter your number: ";
  std::cin >> number;
  int max_sum_of_digits = sum_of_digits (number);
  it_is_even_num(number) ? counter = number / 2 : counter = (number - 1) / 2;
  for (;counter>=1;--counter) {
    if (!(number % counter))
    sum_of_digits(counter) > max_sum_of_digits ? max_sum_of_digits = sum_of_digits(counter) : 0;
  }
  std::cout << "Result:";
  std::cout << max_sum_of_digits;
}
