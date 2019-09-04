#include <iostream>
#include <cstring>
#include <cmath>

// g++ -std=c++14 -Wall -Werror -pedantic -O2  call_number.cpp

void Crypt (std::string& InputArray, const uint32_t ARRAY_COLUMN, const uint32_t ARRAY_LINE) {
  if ((0 == ARRAY_COLUMN) || (0 == ARRAY_LINE) || (0 == InputArray.length())) return;
  const uint32_t BUF_SIZE = ARRAY_COLUMN * ARRAY_LINE;
  const uint32_t NUMBER_OF_PARTS = ceil(InputArray.length() / (BUF_SIZE + .0f));
  InputArray.resize(NUMBER_OF_PARTS * BUF_SIZE);
  std::string buffer;
  for (uint64_t offset = 0; offset < NUMBER_OF_PARTS * BUF_SIZE; offset += BUF_SIZE) {
    buffer.clear();
    buffer = InputArray.substr(offset,BUF_SIZE);
    for (uint32_t i = 0; i < ARRAY_COLUMN; ++i) {
      for (uint32_t j = 0; j < ARRAY_LINE; ++j) {
        InputArray[i * ARRAY_COLUMN + j + offset] = buffer[j * ARRAY_LINE + i];
      }
    }
  }
}

int main() {
  const uint32_t ARRAY_COLUMN = 7;
  const uint32_t ARRAY_LINE = 7;
  std::cout << "Hello! Please enter string which you want to encrypt and decrypt:\n";
  std::string str;
  std::getline ( std::cin, str );
  Crypt (str, ARRAY_COLUMN, ARRAY_LINE);
  std::cout << str;
  std::cout << '\n';
  Crypt (str, ARRAY_LINE, ARRAY_COLUMN);
  std::cout << str;
}

