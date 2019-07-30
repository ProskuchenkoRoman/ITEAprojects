#include <iostream>

int main()
{
  char array[100];
  std::cin >> array;
  int i=0;
  std::cout << "Digits: ";
    while (array[i] != '\0') {
      if ((array[i] >= 48) && (array[i] <= 57)) {
        std::cout << array[i] << " ";
      }
      ++i;
    }
}
