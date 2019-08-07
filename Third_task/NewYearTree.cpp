#include <iostream>

bool is_it_even_num (int var) {
  return var % 2 != 0;
}

int main() {
  unsigned int last_level_of_tree;
  std::cout << "Please, enter number of stars for last level of tree: ";
  std::cin >> last_level_of_tree;
  if (is_it_even_num(last_level_of_tree)) {
    ++last_level_of_tree;
  }
  
  unsigned int stars_on_level= 0;
  for (unsigned int flr = (last_level_of_tree + 1) / 2; flr > 0 ; flr--) {
    for(unsigned int space=0 ; space < (flr - 1); ++space) {
      std::cout << " ";
    }
    for (unsigned int stars=0 ; stars <= stars_on_level ; ++stars) {
      std::cout << "*";
    }
    stars_on_level=stars_on_level + 2;
    for(unsigned int space=0; space < (flr - 1); ++space) {
      std::cout << " ";
    }
    std::cout << "\n";
  }
}