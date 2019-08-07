#include <iostream>
#include <cmath>

int GetCorrectValueFromStream() {
  int number = 0;
  while(!(std::cin >> number)) {
    std::cout << "It isn't integer, please try again: ";
    std::cin.clear();
    while (std::cin.get() != '\n');
  }
  return number;
}

int main() {
  std::cout << "Your expression: ax^2 + bx + c = 0\n";
  std::cout << "Please, enter 'a' - first coefficient: ";
  int a = GetCorrectValueFromStream();
  std::cout << "Please, enter 'b' - second coefficient: ";
  int b = GetCorrectValueFromStream();
  std::cout << "Please, enter 'c' - third coefficient: ";
  int c = GetCorrectValueFromStream();
  const long long DISCRIMINANT = pow(b,2) - 4 * a * c;
  const float DIVIDER_OF_RESULT = 2.0 * a;
  if (DISCRIMINANT > 0) {
    double result1 = (-b + std::sqrt(DISCRIMINANT)) / DIVIDER_OF_RESULT;
    double result2 = (-b - std::sqrt(DISCRIMINANT)) / DIVIDER_OF_RESULT;
    std::cout << "Your result is two variables: x1 = "<< result1 << "\n";
    std::cout << "                              x2 = "<< result2 << "\n";
  } else if (0 == DISCRIMINANT) {
    double result1 = -b / DIVIDER_OF_RESULT;
    std::cout << "Your result is one variables: x = "<< result1 << "\n";
  } else {
    std::cout << "Unfortunately, this expression haven't got solution. Please try again";
  }
  return 0; 
}