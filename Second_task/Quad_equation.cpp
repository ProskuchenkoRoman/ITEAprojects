#include <iostream>
#include <cstdlib>
#include <cmath>



int isitdigit() {
  int n = 0;
  while(true)
  {
  	std::cin >> n;
  	if(!std::cin) 
  	{
  	  std::cout << "It isn't integer, please try again: ";
	  std::cin.clear();
	  while (std::cin.get() != '\n');
	} else {
	  break;
	} 
  }
  return n;
}

int main() {
  int a,b,c;
  int discriminant;
  std::cout << "Your expression: ax^2 + bx + c = 0\n";
  std::cout << "Please, enter 'a' - first coefficient: ";
  a = isitdigit();
  std::cout << "Please, enter 'b' - second coefficient: ";
  b = isitdigit();
  std::cout << "Please, enter 'c' - third coefficient: ";
  c = isitdigit();
  discriminant = pow(b,2) - 4 * a * c;
  if (discriminant > 0) {
  	double result1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
  	double result2 = (-b - std::sqrt(discriminant)) / (2.0 * a);
  	std::cout << "Your result is two variables: x1 = "<< result1 << "\n";
  	std::cout << "                              x2 = "<< result2 << "\n";
  } else if (0 == discriminant) {
  	double result1 = -b / (2.0 * a);
    std::cout << "Your result is one variables: x = "<< result1 << "\n";
  } else {
  	std::cout << "Unfortunately, this expression haven't got solution. Please try again";
  }
  return 0; 
}