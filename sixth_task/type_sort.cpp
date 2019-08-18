#include <iostream>

void bubblesort (unsigned* array, uint16_t LengthOfArray, auto lambda) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (uint32_t i = 0; i < (LengthOfArray - 1); ++i) {
      if (lambda(array[i], array[i + 1])) {
        std::swap(array[i],array[i + 1]);
        flag = true;
      }
    }
  }
}

void bubblesort (double* array, uint16_t LengthOfArray, auto lambda) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (uint32_t i = 0; i < (LengthOfArray - 1); ++i) {
      if (lambda(array[i], array[i + 1])) {
        std::swap(array[i],array[i + 1]);
        flag = true;
      }
    }
  }
}

void bubblesort (char* array, uint16_t LengthOfArray, auto lambda) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (uint32_t i = 0; i < (LengthOfArray - 1); ++i) {
      if (lambda(array[i], array[i + 1])) {
        std::swap(array[i],array[i + 1]);
        flag = true;
      }
    }
  }
}

int main () {
  unsigned array_int[] {12,321,1,14,52,25,46,35,57,234,76,342,2,56,6};
  double array_db[] {12.1,321.1,1.1,14.1,52.12,25.534,46.23,35.09,57.123,234.234,76.456,342.567,2.68,56.234,6.234};
  char array_char[] {'a','D','s','B','5','q','g','A','1','3','e','z','y','C','w','x','b','n','f'};
  uint16_t LengthOfArrayInt = sizeof(array_int)/sizeof(array_int[0]);
  uint16_t LengthOfArrayDb = sizeof(array_db)/sizeof(array_db[0]);
  uint16_t LengthOfArrayChar = sizeof(array_char)/sizeof(array_char[0]);
  bubblesort (array_int, LengthOfArrayInt, [](auto a, auto b) {return a > b;});
  bubblesort (array_db, LengthOfArrayDb, [](auto a, auto b) {return a > b;});
  bubblesort (array_char, LengthOfArrayChar, [](auto a, auto b) {return ((a < 'A') && (b < 'A') && (a > b)) ||  \
                                                                        ((a >= 'A') && (b >= 'A') && (a > b)) ||  \
                                                                        ((a < 'A') && (b >= 'A') && (!(a > b))); });
  for (auto val : array_int) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
  for (auto val : array_db) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
  for (auto val : array_char) {
    std::cout << val << ' ';
  }
}