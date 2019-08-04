#include <iostream>

void print_reversed_utterance(char* arr);

int main()
{
  char arr[100] {};
  int array_len=0;
  std::cout << "This program reversing input string.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> arr;
  print_reversed_utterance(arr);
}

void print_reversed_utterance(char* arr) {
  int array_len = 0;
  while(arr[array_len] != '\0') {
    ++array_len;
  }
  --array_len;
  while(array_len >= 0) {
    std::cout << arr[array_len--];
  }
}