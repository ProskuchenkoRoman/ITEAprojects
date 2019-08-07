#include <iostream>

int it_is_even_num (int var) {
  if (var % 2) {
    return 0;
  } else {
    return 1;
  }
}

int sum_of_digits(unsigned long int variable){
  unsigned int divider=10;
  unsigned int result=0;
  while (!(variable < divider/10)) {
    result = result + (variable % divider) / (divider / 10);
    divider = divider * 10;
  }
  return result;
}

int main() {
  int number,counter,result;
  std::cout << "Please, enter your number: ";
  std::cin >> number;
  int max_sum_of_digits = sum_of_digits (number);
  counter = it_is_even_num(number) ? number / 2 : (number - 1) / 2;
  for (;counter>=1;--counter) {
    if (!(number % counter)) {
      if (sum_of_digits(counter) > max_sum_of_digits) {
        max_sum_of_digits = sum_of_digits(counter);
        result = counter;
      }else{
        max_sum_of_digits = max_sum_of_digits;
      }
    }
  }
  std::cout << "Result:";
  std::cout << result;
}

