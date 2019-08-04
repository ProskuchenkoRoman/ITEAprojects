#include <iostream>

void print_all_digits(char* arr);

int main()
{
  char array[100];
  std::cin >> array;
  int i=0;
  std::cout << "Digits: ";
  print_all_digits(array);
}

void print_all_digits(char* arr) {
  while (*(arr+i) != '\0') {
    if ((*(arr+i) >= 48) && (*(arr+i) <= 57)) {
      std::cout << *(arr+i) << " ";
    }
    ++i;
  }
}