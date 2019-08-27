#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using string = std::string;

string revrot(string* str,const int SZ) {
  if ((SZ <= 0) || (SZ > str->length()) || (0 == str->length()) || (nullptr == str)) return "Fault";
  uint32_t sum1 = 0;
  uint32_t sum2 = 0;
  for(size_t i = 0; i < SZ; ++i) {
    sum1 += pow((int)(str->at(i)-'0'), 2);
  }
  for(size_t i = SZ; i < str->length(); ++i) {
    sum2 += pow((int)(str->at(i)-'0'), 2);
  }
  if (!(sum1 % 2)) {
    std::reverse(str->begin(), str->begin() + SZ - 1);
  } else {
    str->insert(str->cbegin() + SZ, str->at(0));
    str->erase(0, 1);
  }
  if (!(sum2 % 2)) {
    std::reverse((str->end() - (str->length() - SZ)), str->end());
  } else {
    str->insert(str->end(), str->at(SZ));
    str->erase(SZ, 1);
  }
  return *str;
}

int main() {
  string str;
  std::cout << "Please, enter string of digits: \n";
  std::cin >> str;
  for (auto chr : str) {
    if (!((chr >= '0') && (chr <= '9'))) {
      std::cout << "Invalid symbol in input string.\n";
      std::cout << "Try again. \n";
      return 0;
    }
  }
  int sz = 0;
  std::cout << "Please enter length of SZ = ";
  std::cin >> sz;
  std::cout << "Your result: \n" << revrot(&str, sz);
}