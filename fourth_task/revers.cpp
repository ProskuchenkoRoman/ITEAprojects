#include <iostream>

void print_reversed_utterance(char* arr) {
  if (arr != nullptr ) {
    unsigned int i = 0;
    unsigned int count = 0;
    uint16_t count_symbol_in_array = 0;

    for (count_symbol_in_array = 0; arr[count_symbol_in_array] != '\0'; ++count_symbol_in_array) {
      ;
    }
    for (char *begin = arr, *end = arr + (count_symbol_in_array  - 1);
       begin <= end; ++begin, --end) {
    std::swap(*begin, *end);
  }
    std::cout << arr << std::endl;
  }
}

int main()
{
  const unsigned int array_len = 100;
  char arr[array_len] {};
  std::cout << "This program reversing input string.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> arr;
  print_reversed_utterance(arr);
}

