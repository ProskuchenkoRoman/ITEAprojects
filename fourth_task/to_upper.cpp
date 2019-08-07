#include <iostream>

void to_upper_case(const char* arr) {
  if (arr != nullptr ){
  const char diff_between_upper_and_lower = 'a' - 'A';
  while (*arr != '\0') {
    const char ch = *arr++;
    bool is_lower = (ch >='a') && (ch <='z');
    std::cout << (char)(is_lower ? ch - diff_between_upper_and_lower : ch);
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