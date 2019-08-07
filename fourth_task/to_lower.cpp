#include <iostream>

void to_lower_case(const char* arr) {
  if (arr != nullptr ){
  const char diff_between_upper_and_lower = 'a' - 'A';
  while (*arr != '\0') {
    const char ch = *arr++;
    bool is_upper = (ch >='A') && (ch <='Z');
    std::cout << (char)(is_upper ? ch + diff_between_upper_and_lower : ch);
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

