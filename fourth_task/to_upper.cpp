#include <iostream>

void to_upper_case(const char* arr) {
  if (arr != nullptr ){
  unsigned int i=0;
  while (*arr != '\0') {
    const char ch = *arr++;
    if ((ch >= 'a') && (ch <= 'z')) {
      std::cout << (char)(ch - 32);
    } else {
      std::cout << ch;
    }
  }
}
}

int main()
{
  char array[100];
  std::cout << "This program changing all lower case chars to upper case chars.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> array;
  to_upper_case(array);
}