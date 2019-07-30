#include <iostream>

int is_it_even_num (int var) {
  if (var % 2) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int last_level_of_tree, floor;
  std::cout << "Please, enter number of stars for last level of tree: ";
  std::cin >> last_level_of_tree;
  if (is_it_even_num(last_level_of_tree)) {
    last_level_of_tree++;
  }
  floor = (last_level_of_tree + 1) / 2;
  int stars_on_level= 0;
  for (floor ; floor > 0 ; floor--) {
    for(int space=0 ; space < (floor - 1); space++) {
      std::cout << " ";
    }
    for (int stars=0 ; stars <= stars_on_level ; ++stars) {
      std::cout << "*";
    }
    stars_on_level=stars_on_level + 2;
    for(int space=0; space < (floor - 1); space++) {
      std::cout << " ";
    }
    std::cout << "\n";
  }
}