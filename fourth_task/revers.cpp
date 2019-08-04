#include <iostream>

int main()
{
  char arr[100] {};
  int array_len=0;
  std::cin >> arr;
  while(arr[array_len] != '\0') {
    ++array_len;
  }
  --array_len;
  while(array_len >= 0) {
    std::cout << arr[array_len--];
  }
}

