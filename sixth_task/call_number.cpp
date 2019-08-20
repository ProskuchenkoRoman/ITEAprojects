#include <iostream>
#include <cstring>
#include <cmath>

void Crypt (std::string* InputArrayPtr, const unsigned ARRAY_COLUMN, const unsigned ARRAY_LINE) {
  if (nullptr == InputArrayPtr) return;
  const unsigned BUF_SIZE = ARRAY_COLUMN * ARRAY_LINE;
  const unsigned NUMBER_OF_PARTS = ceil((*InputArrayPtr).length() / (ARRAY_COLUMN * ARRAY_LINE + .0f));
  (*InputArrayPtr).resize(NUMBER_OF_PARTS * BUF_SIZE);
  char* buffer = static_cast<char*>(calloc(BUF_SIZE, sizeof(char)));
  if (nullptr == buffer) {
    std::cout << "Not enought memory.";
    return;
  }
  for (uint64_t offset = 0; offset < NUMBER_OF_PARTS * BUF_SIZE; offset += BUF_SIZE - 1) {
    for (unsigned i = 0; i < ARRAY_COLUMN; ++i) {
      for (unsigned j = 0; j < ARRAY_LINE; ++j) {
        buffer[i * ARRAY_COLUMN + j] = (*InputArrayPtr)[j * ARRAY_COLUMN + i + offset];
      }
    }
    for (unsigned i = 0; i < ARRAY_COLUMN; ++i) {
      for (unsigned j = 0; j < ARRAY_LINE; ++j) {
        (*InputArrayPtr)[i * ARRAY_COLUMN + j + offset] = buffer[i * ARRAY_COLUMN + j];
      }
    }
  }
  free(buffer);
}

int main() {
  const unsigned ARRAY_COLUMN = 3;
  const unsigned ARRAY_LINE = 3;
  std::cout << "Hello! Please enter string which you want to encrypt and decrypt: ";
  std::string str;
  std::getline ( std::cin, str );
  Crypt (&str, ARRAY_COLUMN, ARRAY_LINE);
  std::cout << str;
  std::cout << '\n';
  Crypt (&str, ARRAY_COLUMN, ARRAY_LINE);
  std::cout << str;
}

