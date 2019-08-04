#include <iostream>

void to_upper_case(char* arr);

int main()
{
  char array[100];
  std::cout << "This program changing all lower case chars to upper case chars.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> array;
  to_upper_case(array);
}

void to_upper_case(char* arr) {
  int i=0;
  while (*(arr + i) != '\0') {
    if ((*(arr + i) >= 97) && (*(arr + i) <= 122)) {
      std::cout << (char)(*(arr + i) - 32);
    } else {
      std::cout << *(arr + i);
    }
  ++i;
  }
}