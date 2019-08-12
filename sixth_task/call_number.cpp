#include <iostream>
#include <cstring>
#include <cmath>


void Crypt (char* InputArray, const unsigned NUMBER_OF_PARTS,const unsigned ARRAY_COLUMN, const unsigned ARRAY_LINE) {
if (InputArray == nullptr) return;
  const unsigned BUF_SIZE = ARRAY_COLUMN * ARRAY_LINE;
  char buffer[BUF_SIZE] {'0'};
  for (unsigned offset = 0; offset < NUMBER_OF_PARTS * BUF_SIZE + 1; offset += BUF_SIZE) {
    for (unsigned i = 0; i < ARRAY_COLUMN; ++i) {
      for (unsigned j = 0; j < ARRAY_LINE; ++j) {
        buffer[i * ARRAY_COLUMN + j] = InputArray[j * ARRAY_COLUMN + i + offset];
      }
    }
    for (unsigned i = 0; i < ARRAY_COLUMN; ++i) {
      for (unsigned j = 0; j < ARRAY_LINE; ++j) {
        InputArray[i * ARRAY_COLUMN + j + offset] = buffer[i * ARRAY_COLUMN + j];
      }
    }
  }
}

int main() {
  const unsigned ARRAY_COLUMN = 4;
  const unsigned ARRAY_LINE = 4;
  std::string s;
  std::getline ( std::cin, s );
  unsigned NumberOfChar = 0;
  while (s[NumberOfChar] != '\0') {
    s[NumberOfChar++];
  }
  unsigned NumberOfParts = ceil(NumberOfChar / (ARRAY_COLUMN * ARRAY_LINE + .0f));
  char* ptr = (char *)malloc(NumberOfParts * ARRAY_COLUMN * ARRAY_LINE * sizeof(char));
  for(uint32_t i = 0; i < NumberOfChar;++i){
    ptr[i] = s[i];
  }
  Crypt (ptr, NumberOfParts, ARRAY_COLUMN, ARRAY_LINE);
  for (uint32_t i = 0; i < NumberOfParts * ARRAY_COLUMN * ARRAY_LINE; ++i) {
    std::cout << ptr[i];
  }
  std::cout << '\n';
  Crypt (ptr, NumberOfParts, ARRAY_COLUMN, ARRAY_LINE);
  for (uint32_t i = 0; i < NumberOfParts * ARRAY_COLUMN * ARRAY_LINE; ++i) {
    std::cout << ptr[i];
  }
}

