#include <iostream>
#include <cmath>

//g++ -std=c++14 -Wall -Werror -pedantic -O2 virtual_func.cpp

class shape {
  public:
  virtual void draw () {
    std::cout << "Some shape" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  virtual long double calc_square () {
    std::cout << "Calculate square" << std::endl;
    return false;
  }
};

class square: public shape {
  public:
    void draw () override {
      std::cout << " ";
      for (unsigned i = 0; i < side_len; ++i) {
        std::cout << "--";
      }
      std::cout << "\n";
      for (unsigned level = 0; level < side_len; ++level) {
        std::cout << '|';
        for (unsigned space = 0; space < side_len; ++space) {
          std::cout << "  ";
        }
        std::cout << '|' << '\n';
      }
      std::cout << " ";
      for (unsigned i = 0; i < side_len; ++i) {
        std::cout << "--";
      }
    }
    long double calc_square () override {
      return pow(side_len, 2);
    }
    square (unsigned side_len): side_len(side_len) {
      ;
    }
  private:
    unsigned side_len;
};

class triangle: public shape {
  public:
    void draw () override {
      if (0 == side_len) return;
      for (unsigned i = 0; i < side_len; ++i) {
        for (unsigned space = 0; space < (side_len - i); ++space) {
          std::cout << ' ';
        }
        std::cout << '/';
        for (unsigned space = 0; space < (2 * i); ++space) {
          std::cout << ' ';
        }
        std::cout << ((char)92) << '\n';
      }
      std::cout << ' ';
      for (unsigned i = 0; i < side_len; ++i) {
      std::cout << "--";
      }
    }
    long double calc_square () {
      const double FACTOR = 0.433012701;
      return (pow(side_len,2)*FACTOR);
    }
    triangle (unsigned side_len = 2): side_len(side_len) {
      ;
    }
  private:
    unsigned side_len;
};

class rectangle: public shape {
  public:
  void draw () override {
    std::cout << " ";
    for (unsigned i = 0; i < width; ++i) {
      std::cout << "--";
    }
    std::cout << "\n";
    for (unsigned level = 0; level < height; ++level) {
      std::cout << '|';
      for (unsigned space = 0; space < width; ++space) {
        std::cout << "  ";
      }
      std::cout << '|' << '\n';
    }
    std::cout << " ";
    for (unsigned i = 0; i < width; ++i) {
      std::cout << "--";
    }
  }
  long double calc_square () override {
    return (width * height);
  }
  rectangle (unsigned width = 2, unsigned height = 2): width(width), height(height) {
    ;
  }
  private:
    unsigned width;
    unsigned height;
};

void draw(shape& figure) {
  figure.draw();
}

long double calc_square(shape& figure) {
  return figure.calc_square();
}

int main () {
  square square {5};
  triangle triangle {5};
  rectangle rectangle {4, 5};
  draw(square);
  std::cout << '\n' << calc_square(square) << '\n';
  draw(triangle);
  std::cout << '\n' << calc_square(triangle) << '\n';
  draw(rectangle);
  std::cout << '\n' << calc_square(rectangle);
}