#include <iostream>

void print_all_digits(const char* arr) {
  if (arr != nullptr ){
    while (*arr != '\0') {
      const char ch = *arr++;
      if ((ch >= '0') && (ch <= '9')) {
          std::cout << ch << " ";
      }
    }
  }
}

int main()
{
  char array[100];
  std::cout << "Please, enter your strging, and you will see what digit do you have: ";
  std::cin >> array;
  std::cout << "Digits: ";
  print_all_digits(array);
}

