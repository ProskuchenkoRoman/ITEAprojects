#include <iostream>

void to_lower_case(const char* arr) {
  if (arr != nullptr ){
  unsigned int i=0;
  while (*(arr+i) != '\0') {
    if ((*(arr+i) >= 'A') && (*(arr+i) <= 'Z')) {
      std::cout << (char)(*(arr+i) + 32);
    } else {
      std::cout << *(arr+i);
    }
    ++i;
  }
}
}

int main()
{
  char array[100];
  std::cout << "This program changing all upper case chars to lower case chars.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> array;
  to_lower_case(array);
}

