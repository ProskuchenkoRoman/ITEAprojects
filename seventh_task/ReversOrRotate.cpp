#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

//g++ -std=c++14 -Wall -Werror -pedantic -O2 ReversOrRotate.cpp

using string = std::string;

// что то я не уверен правильно ли я вообще понял задание) отсюда непонятки с кодом)

string revrot(const string& str,const unsigned SZ) {
  if ((SZ > str.length()) || (0 == str.length())) return "Fault";
  string rezult;
  // rezult.resize(str.size());
  uint32_t sum1 = 0;
  uint32_t sum2 = 0;
  const uint32_t STR_LEN = str.length();
  for(size_t i = 0; i < SZ; ++i) { // range-for незнаю как тут использовать, мне ж нужна только часть строки
    sum1 += pow((int)(str[i] - '0'), 2);
  }
  for(size_t i = SZ; i < STR_LEN; ++i) {
    sum2 += pow((int)(str[i] - '0'), 2);
  }
  if (sum1 % 2) { // я ж правильно понял, условием ротейта и реверса является четность - нечетность?
    rezult = str.substr(1, SZ - 1);
    rezult += str[0];
  } else {
    rezult = str.substr(0 ,SZ);
    std::reverse(rezult.begin(), rezult.begin() + SZ); //тут я юзаю str->begin() + SZ тк я обрабатую не всю строку а только до SZ
  }
  if (sum2 % 2) { // ну мы же вторую половину тоже проверяем на реверс или ротейт
    rezult += str.substr(SZ + 1, STR_LEN);
    rezult += str[SZ];
  } else {
    rezult += str.substr(SZ, STR_LEN);
    std::reverse(rezult.begin() + SZ, rezult.end());
  }
  return rezult;
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
  std::cout << "Your result: \n" << revrot(str, sz);
}