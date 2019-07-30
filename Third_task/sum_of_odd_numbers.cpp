#include <iostream>

int main()
{
  int count_elements,element;
  int result = 0;
  bool repeat = false;
  std::cout << "Please, enter number of all elements:";
  do {
    if (repeat) {
      std::cout << "Please, try again. You should enter again number of all elements(1 <= x <= 50): ";
    }
  std::cin >> count_elements;
  repeat = true;
  } while (count_elements < 1 || count_elements > 50);
  std::cout << "Please, enter all elements: \n";
  for (;count_elements>0;--count_elements) {
    std::cin >> element;
    if (element < -60 || element > 90) {
      std::cout << "It is wrong element. Please, enter number which -60 <= x <= 90 : ";
      ++count_elements;
      continue;
    }
    if (element%2) {
      result = result + element;
    }
  }
  std::cout << "Your result: " << result << std::endl;
}
