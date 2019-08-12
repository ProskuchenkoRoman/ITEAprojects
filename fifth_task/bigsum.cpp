#include <iostream>
#include <cmath>

unsigned int CmpLengthArray (char* arr1,char* arr2) {
    uint16_t count_symbol_in_array1 = 0;
    for (count_symbol_in_array1 = 0; arr1[count_symbol_in_array1] != '\0'; ++count_symbol_in_array1) {
      ;
    }
    uint16_t count_symbol_in_array2 = 0;
    for (count_symbol_in_array2 = 0; arr2[count_symbol_in_array2] != '\0'; ++count_symbol_in_array2) {
      ;
    }
    unsigned int LengthOfBiggestArray = (count_symbol_in_array1 >= count_symbol_in_array2) ? count_symbol_in_array1 : count_symbol_in_array2;
    return LengthOfBiggestArray;
}

void revers_array(char* arr) {
  if (arr != nullptr ) {
    unsigned int i = 0;
    unsigned int count = 0;
    uint16_t count_symbol_in_array = 0;
    for (count_symbol_in_array = 0; arr[count_symbol_in_array] != '\0'; ++count_symbol_in_array) {
      ;
    }
    for (char *begin = arr, *end = arr + (count_symbol_in_array  - 1);
       begin <= end; ++begin, --end) {
       std::swap(*begin, *end);
    }
  }
}

void SumOfArray(char* arr1,char* arr2,const unsigned int ARRAY_SIZE, unsigned int* LengthOfBiggestArray) {
  if ((arr1 != nullptr) && (arr2 != nullptr) && (arr1 != arr2) && (LengthOfBiggestArray != nullptr)) {
    revers_array(arr1);
    revers_array(arr2);
    *LengthOfBiggestArray = CmpLengthArray (arr1,arr2);
    for(unsigned i = 0; i <= *LengthOfBiggestArray; ++i) {
      if (!((arr1[i]>= '0') && (arr1[i] <= '9'))) arr1[i] = '0';
      if (!((arr2[i]>= '0') && (arr2[i] <= '9'))) arr2[i] = '0';
    }
    for (unsigned i = 0; i < ARRAY_SIZE;++i) {
      if ((((int)arr1[i]) == 0) && (((int)arr1[i]) == 0)) continue;
      if (arr1[i] != 0) arr1[i] -='0';
      if (arr2[i] != 0) arr2[i] -='0';
      unsigned tmp = arr1[i]+arr2[i];
      if ((tmp > 9) && (tmp < 20)) {
        tmp -=10;
        arr1[i] = tmp + '0';
        ++arr1[i+1];
      } else if ((tmp >= 0) && (tmp < 10)) {
        arr1[i] = tmp + '0';
      } else {
        std::cout << "Error.\n";
        break;
      }
    }
    revers_array(arr1);
  }
}

int main() {
  const unsigned ARRAY_SIZE = 100;
  std::cout << "Please, enter string of digits for sum:\n";
  char arr1[ARRAY_SIZE] {};
  char arr2[ARRAY_SIZE] {};
  std::cin >> arr1;
  std::cout << "+\n";
  std::cin >> arr2;
  std::cout << "=\n";
  unsigned int LengthOfBiggestArray = 0;
  SumOfArray(arr1, arr2, ARRAY_SIZE, &LengthOfBiggestArray);
  if (!(arr1[0] == '0')) {
    std::cout << arr1[0];
  }
  unsigned i = 1;
  for (unsigned i = 1; i <= LengthOfBiggestArray; ++i) {
    std::cout << arr1[i];
  }
}