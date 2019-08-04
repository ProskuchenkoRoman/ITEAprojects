#include <iostream>

int main()
{
  int i=0;
  char array[100];
  std::cin >> array;
  while (array[i] != '\0') {
    if ((array[i] >= 65) && (array[i] <= 90)) {
      std::cout << (char)(array[i] + 32);
    } else {
      std::cout << array[i];
    }
    ++i;
  }
}
