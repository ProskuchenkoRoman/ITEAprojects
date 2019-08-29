#include <iostream>
#include <functional>
#include <cmath>

#define PRINT(array)              \
do {                              \
 for (auto val : array) {         \
    std::cout << val << ' ';      \
}                                 \
std::cout << '\n';                \
} while(false);

template <typename Type>
using lambda = std::function <bool(Type, Type)>;

template <typename Type>
void bubblesort (Type* array, uint32_t LengthOfArray, lambda<Type> LambdaComparator) {
  if ((nullptr == array) || (0 == LengthOfArray)) return;
  bool flag = true;
  while (flag) {
    flag = false;
    for (uint32_t i = 0; i < (LengthOfArray - 1); ++i) {
      if (LambdaComparator(array[i], array[i + 1])) {
        std::swap(array[i],array[i + 1]);
        flag = true;
      }
    }
  }
}

int main () {
  const uint32_t ARRAY_LENGTH = 100;
  const double PI  =3.141592653589793238463;
  unsigned array_int[ARRAY_LENGTH] {};
  double array_db[ARRAY_LENGTH] {};
  char array_char[ARRAY_LENGTH] {};
  for (unsigned i = 0; i < ARRAY_LENGTH; ++i) {
    array_int[i] = rand();
  }
  for (unsigned i = 0; i < ARRAY_LENGTH; ++i) {
    array_db[i] = rand()/PI;
  }
  for (unsigned i = 0; i < ARRAY_LENGTH; ++i) {
    array_char[i] = static_cast<char>((rand() % 72) + 48);  
  }
  auto LambdaComparator = [](auto a, auto b) {return a > b;};
  bubblesort<unsigned> (array_int, ARRAY_LENGTH, LambdaComparator);
  bubblesort<double> (array_db, ARRAY_LENGTH, LambdaComparator);
  bubblesort<char> (array_char, ARRAY_LENGTH, [](auto a, auto b) {return ((a < 'A') && (b < 'A') && (a > b)) ||
                                                                         ((a >= 'A') && (b >= 'A') && (a > b)) ||
                                                                         ((a < 'A') && (b >= 'A') && (!(a > b))); });
  PRINT(array_int);
  PRINT(array_db);
  PRINT(array_char);
}