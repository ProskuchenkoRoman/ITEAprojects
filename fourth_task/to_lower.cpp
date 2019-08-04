#include <iostream>

void to_lower_case(char* arr);

int main()
{
  char array[100];
  std::cout << "This program changing all upper case chars to lower case chars.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> array;
  to_lower_case(array);
}

void to_lower_case(char* arr) {
  int i=0;
  while (*(arr+i) != '\0') {
    if ((*(arr+i) >= 65) && (*(arr+i) <= 90)) {
      std::cout << (char)(*(arr+i) + 32);
    } else {
      std::cout << *(arr+i);
    }
    ++i;
  }
}