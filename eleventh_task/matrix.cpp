#include <iostream>
#include <cstring>

//g++ -std=c++14 -Wall -Werror -pedantic -O2  matrix.cpp

class matrix {
  public:
    matrix(const uint16_t LINE = 2, const uint16_t COLUMN = 2) : LINE(LINE), COLUMN(COLUMN) {
      unsigned MEM_SIZE = COLUMN * LINE * sizeof(uint32_t);
      do {
        array = static_cast<uint32_t*>(malloc(MEM_SIZE));
      } while (nullptr == array);
      memset(array, 0, MEM_SIZE);
    }

    ~matrix() {
      if (nullptr != array) free(array);
    }

    matrix& operator= (matrix MATRIX) { // не позволяет написать (const matrix& MATRIX)
      array = static_cast<uint32_t*>(malloc(COLUMN * LINE * sizeof(uint32_t)));
      for (uint32_t i = 0; i < COLUMN * LINE; ++i) {
        array[i] = MATRIX[i];
      }
      return *this;
    }

    matrix& operator+= (matrix& MATRIX) { // не позволяет написать (const matrix& MATRIX)
      for(uint32_t i = 0; i < (COLUMN * LINE); ++i) {
        array[i] += MATRIX[i];
      }
      return *this;
    }

    const matrix operator+ (matrix& MATRIX) { // не позволяет написать (const matrix& MATRIX)
    matrix& tmp = *this;
    for (uint32_t i = 0; i < (COLUMN * LINE); ++i) {
      tmp[i] += MATRIX[i];
    }
    return tmp;
    }

    uint32_t& operator[] (const uint32_t& POSIT) {
      return array[POSIT];
    }

    matrix operator* (matrix MATRIX) {
      uint16_t tmp_column = this->COLUMN;
      uint16_t tmp_line = this->LINE;
      std::cout << tmp_column << '\n';
      std::cout << tmp_line << '\n';
      if (tmp_column != MATRIX.LINE) {
        std::cout << "Sorry, but dimension COLUMN of matrix A do not equal dimension LINE of matrix B";
        std::cout << "In equation A * B";
        return *this;
      }
      matrix tmp{tmp_line, tmp_column};
      tmp.show();
      for (unsigned CountLine = 0; CountLine < tmp_line; ++CountLine) {
        for (unsigned CountColumn = 0; CountColumn < tmp_column; ++CountColumn) {
          for (unsigned CountCoef = 0; CountCoef < tmp_column; ++CountCoef) {
            tmp[CountLine * tmp_line + CountColumn] += array[CountLine * tmp_line + CountCoef] * MATRIX[CountCoef * tmp_line + CountColumn];
          }
        }
      }
      return tmp;
    }

    matrix operator* (const uint16_t COEFIC) {
      matrix tmp = *this;
      for (unsigned i = 0; i < (COLUMN * LINE); ++i) {
        tmp[i] *= COEFIC;
      }
      return tmp;
    }

    void show() {
      for (uint32_t i = 0; i < LINE; ++i){
        for (uint32_t j = 0; j < COLUMN; ++j){
          std::cout << array[i * LINE + j] << ' ';
        }
        std::cout << '\n';
      }
    }
  private:
    const uint16_t LINE;
    const uint16_t COLUMN;
    uint32_t* array;
};

int main () {
  constexpr uint16_t COL = 3;
  constexpr uint16_t LIN = 2;
  matrix matr{LIN, COL};
  matrix matr2{LIN, COL};
  matrix matr3{(uint16_t)(LIN + 1), COL};
  for (unsigned i = 0; i < COL * LIN; ++i) {
    matr2[i] = i + 1;
  }
  for (unsigned i = 0; i < 9; ++i) {
    matr[i] = i + 1;
    matr3[i] = i + 1;
  }
  
  std::cout << "Matrix = \n";
  matr.show();
  std::cout << "Mult\n";
  // matr = (matr2 * matr3);
  (matr2 * matr3).show();
  matr2.show();
  std::cout << "Matrix = \n";
  matr.show();
  matr3.show();
}
