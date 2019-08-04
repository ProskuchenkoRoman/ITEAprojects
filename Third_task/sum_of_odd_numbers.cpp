#include <iostream>

int main()
{
  int count_elements,element;
  int result = 0;
  std::cout << "Please, enter number of all elements:";
  std::cin >> count_elements;
  while (count_elements < 1 || count_elements > 50) {
    std::cout << "Please, try again. You should enter again number of all elements(1 <= x <= 50): ";
    std::cin >> count_elements;
  } 
  std::cout << "Please, enter all elements: \n";
  while (count_elements>0) {
    std::cin >> element;
    --count_elements;
    if (element < -60 || element > 90) {
      std::cout << "It is wrong element. Please, enter number which -60 <= x <= 90 : ";
      ++count_elements;
      continue;
    }
    if (element % 2 == 1) {
      result += element;
    }
  }
  std::cout << "Your result: " << result << std::endl;
}
