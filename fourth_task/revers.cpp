#include <iostream>

void print_reversed_utterance(char* arr) {
  if (arr != nullptr ){
    unsigned int i = 0;
    unsigned int count = 0;
    char tmp = 0;
    while (*(arr+i)!='\0'){
      ++i;
    }
    --i;
    while (count <= (int)(i/2)){
      tmp = *(arr + count);
      *(arr + count) = *(arr + i - count);
      *(arr + i - count) = tmp;
      ++count;
    }
    i = 0;
    while (*(arr+i)!='\0') {
      std::cout << *(arr+i);
      ++i;
    }
  }
}

int main()
{
  const unsigned int array_len = 100;
  char arr[array_len] {};
  std::cout << "This program reversing input string.\n";
  std::cout << "Please, enter input string:\n";
  std::cin >> arr;
  print_reversed_utterance(arr);
}

