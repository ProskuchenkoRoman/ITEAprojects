#include <iostream>
#include <functional>
#include <chrono>

#define PRINT(array)           \
 for (auto val : array) {  \
    std::cout << val << ' ';       \
 }

void bubblesort (uint32_t* array, uint16_t LengthOfArray, std::function<bool(uint32_t, uint32_t)> LambdaComparator) {
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

int partition (unsigned* arr, unsigned low, unsigned high) {
  unsigned pivot = arr[high];
  unsigned i = (low - 1);
  for (unsigned j = low; j <= high - 1; ++j) {
    if (arr[j] <= pivot) {  
      std::swap(arr[++i], arr[j]);  
    }  
  }  
  std::swap(arr[i + 1], arr[high]);  
  return (i + 1);  
}


void quickSort(unsigned* arr, unsigned low, unsigned high) {
  if (nullptr == arr) return;
  if (low < high)  
  {
    unsigned pi = partition(arr, low, high);  
    quickSort(arr, low, pi - 1);  
    quickSort(arr, pi + 1, high);  
  }  
}  

int main () {
  const unsigned BUF_SIZE = 5000;
  unsigned array1[BUF_SIZE] {};
  unsigned array2[BUF_SIZE] {};
  for (unsigned i = 0; i < BUF_SIZE; ++i) {
    unsigned random_val = rand();
    array1[i] = random_val;
    array2[i] = random_val;
  }
  const unsigned START_POINT = 0;
  auto begin1 = std::chrono::high_resolution_clock::now();
  bubblesort(array1, BUF_SIZE, [](auto a, auto b) {return a > b;});
  auto end1 = std::chrono::high_resolution_clock::now();
  auto MicroSecForBubbleSort = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
  PRINT(array1);
  std::cout << "\n-----------------------------------------------------------------------------------------\n";
  auto begin2 = std::chrono::high_resolution_clock::now();
  quickSort(array2, START_POINT, BUF_SIZE - 1);
  auto end2 = std::chrono::high_resolution_clock::now();
  PRINT(array2);
  auto MicroSecForQuickSort = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
  std::cout << "\nThe time for bubblesort: " << MicroSecForBubbleSort.count() << " microseconds\n";
  std::cout << "\nThe time for quicksort: " << MicroSecForQuickSort.count() << " microseconds\n";
}