#include <iostream>


void bubblesort (uint32_t* array, uint16_t LengthOfArray, auto LambdaComparator) {
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

int partition (unsigned* arr, unsigned low, unsigned high) {  
  unsigned pivot = arr[high];
  unsigned i = (low - 1);
  for (unsigned j = low; j <= high - 1; ++j) {
    if (arr[j] <= pivot) {  
      i++;
      std::swap(arr[i], arr[j]);  
    }  
  }  
  std::swap(arr[i + 1], arr[high]);  
  return (i + 1);  
}


void quickSort(unsigned* arr, unsigned low, unsigned high) {
  if (low < high)  
  {
    unsigned pi = partition(arr, low, high);  
    quickSort(arr, low, pi - 1);  
    quickSort(arr, pi + 1, high);  
  }  
}  

int main () {
  unsigned array1[] {12,321,1,14,52,25,46,35,57,234,76,342,2,56,6};
  unsigned array2[] {12,321,1,14,52,25,46,35,57,234,76,342,2,56,6};
  const uint16_t LENGTH_OF_ARRAY = sizeof(array1)/sizeof(array1[0]);
  const unsigned START_POINT = 0;
  //--------------------------------------------------------------
  bubblesort(array1, LENGTH_OF_ARRAY, [](auto a, auto b) {return a > b;});
  for (uint16_t i = 0; i < LENGTH_OF_ARRAY; ++i) {
    std::cout << array1[i] << ' ';
  }
  std::cout << '\n';
  //--------------------------------------------------------------
  quickSort(array2, START_POINT, LENGTH_OF_ARRAY - 1);
  for (uint16_t i = 0; i < LENGTH_OF_ARRAY; ++i) {
    std::cout << array2[i] << ' ';
  }
  //--------------------------------------------------------------
}