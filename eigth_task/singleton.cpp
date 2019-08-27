#include <iostream>

class OneObj {
  public:
    static OneObj& Init() {
      static OneObj OneObj;
      return OneObj;
    }
    uint32_t change(){
      checkvar += 1;
      return checkvar;
    }
    ~OneObj() = default;
  private:
    uint32_t checkvar = 0;
    OneObj() = default;
    OneObj(const OneObj& st) = delete;
    OneObj& operator= (const OneObj& rhs) = delete;
};

int main () {
  OneObj& FirstObj = OneObj::Init();
  OneObj& SecondObj = OneObj::Init();

  std::cout << "1. First object: " << FirstObj.change() << "\n";
  std::cout << "2. Second object: " << SecondObj.change() << "\n";
  std::cout << "3. First object: " << FirstObj.change() << "\n";
  std::cout << "4. Second object: " << SecondObj.change() << "\n";
  FirstObj.~OneObj();
  std::cout << "5. First object: " << FirstObj.change() << "\n";
}