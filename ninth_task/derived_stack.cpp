#include <iostream>
#include <functional>

//g++ -std=c++14 -Wall -Werror -pedantic -O2  derived_stack.cpp

/*
Я немного по памяти накосячил) немогу быстро продебажить)
я правильно заблочил методы базового класса?
*/

template <typename Type>
using lambda = std::function <bool(Type, Type)>;

template<typename Type>
void CopyArray(const Type* FROM_ARRAY,Type* ToArray,const size_t SIZE_FOR_COPY) {
  if ((nullptr == FROM_ARRAY) || (nullptr == ToArray) || (FROM_ARRAY == ToArray) || (0 == SIZE_FOR_COPY)) return;
  for (size_t i = 0; i < SIZE_FOR_COPY; ++i){
    ToArray[i] = FROM_ARRAY[i];
  }
}

template<typename Type>
class vector {
  public:
    bool push_back(const Type VALUE) {
      if (0 == PlaceLeft) {
        const unsigned NEW_MEM_SIZE = NumberOfItems + PART_SIZE;
        Type* NewMemPtr = static_cast<Type*>(malloc(NEW_MEM_SIZE * sizeof(Type)));
        if (nullptr == NewMemPtr) {
          std::cout << "Not enought memmory.";
          return false;
        }
        CopyArray<Type>(MemoryPtr,NewMemPtr,NumberOfItems);
        PlaceLeft = PART_SIZE;
        free(MemoryPtr);
        MemoryPtr = NewMemPtr;
      }
      MemoryPtr[NumberOfItems] = VALUE;
      ++NumberOfItems;
      --PlaceLeft;
      return true;
    }
    Type pop_back() {
      if ((nullptr == MemoryPtr) || (0 == NumberOfItems)) {
        std::cout << "Sorry, it is empty or nullptr: ";
        return Type();
      }
      const Type OUT = MemoryPtr[NumberOfItems - 1];
      MemoryPtr[NumberOfItems - 1] = 0;
      if ((PART_SIZE - 1) <= PlaceLeft) {
        const unsigned NEW_MEM_SIZE = ((NumberOfItems <= PART_SIZE) ? PART_SIZE : (NumberOfItems - PART_SIZE));
        Type* NewMemPtr = static_cast<Type*>(malloc(NEW_MEM_SIZE * sizeof(Type)));
        if (nullptr == NewMemPtr) {
          std::cout << "Sorry, not enought memory \n";
          return Type();
        }
        --NumberOfItems;
        CopyArray<Type>(MemoryPtr,NewMemPtr,NumberOfItems);
        PlaceLeft = 0;
        free(MemoryPtr);
        MemoryPtr = NewMemPtr;
      } else {
        ++PlaceLeft;
        --NumberOfItems;
      }
      return OUT;
    }
    Type top () {
      return MemoryPtr[NumberOfItems - 1];
    }
    Type operator [](uint32_t position) const {
      if (nullptr == MemoryPtr) {
        std::cout << "Sorry, nullptr. \n";
        return Type();
      }
      if (position <= NumberOfItems) {
        return MemoryPtr[position];
      } else {
        std::cout << "This position isn't exist.\n";
        return Type();
      }
    }
    uint32_t find(const Type ELEMENT) const {
      for(uint32_t i = 0; i < NumberOfItems; ++i) {
        if (ELEMENT == MemoryPtr[i]) {
          return i;
        }
      }
      std::cout << "Did not find same element: " << ELEMENT << "\n";
      return uint32_t();
    }
    void sort(lambda<Type> LambdaComparator = [](Type a, Type b) {return a < b;}) {
      if ((nullptr == MemoryPtr) || (1 > NumberOfItems)) return;
      bool flag = true;
      while (flag) {
        flag = false;
        for (uint32_t i = 0; i < (NumberOfItems); ++i) {
          if (LambdaComparator(MemoryPtr[i], MemoryPtr[i + 1])) {
            std::swap(MemoryPtr[i],MemoryPtr[i + 1]);
            flag = true;
          }
        }
      }
    }
    bool insert(const Type VALUE,const uint32_t POSITION) {
      if (POSITION >= NumberOfItems) return false;
      if (0 == PlaceLeft) {
        const unsigned NEW_MEM_SIZE = NumberOfItems + PART_SIZE;
        Type* NewMemPtr = static_cast<Type*>(malloc(NEW_MEM_SIZE * sizeof(Type)));
        if (nullptr == NewMemPtr) {
          std::cout << "Not enought memmory.";
          return false;
        }
        CopyArray<Type>(MemoryPtr,NewMemPtr,NumberOfItems);
        PlaceLeft = PART_SIZE;
        free(MemoryPtr);
        MemoryPtr = NewMemPtr;
      }
      const unsigned CALC_MEM_SIZE = (((int)(NumberOfItems / PART_SIZE)) + 1) * PART_SIZE;
      for (uint32_t i = 0; i < (CALC_MEM_SIZE - POSITION) + 1; ++i) {
        MemoryPtr[(CALC_MEM_SIZE - i)] = MemoryPtr[(CALC_MEM_SIZE - i) - 1];
      }
      MemoryPtr[POSITION - 1] = VALUE;
      ++NumberOfItems;
      --PlaceLeft;
      return true;
    }
    ~vector () {
      if (nullptr != MemoryPtr) {
        free(MemoryPtr);
      }
    }
  private:
    const size_t PART_SIZE = 4;
    Type* MemoryPtr = nullptr; 
    uint32_t PlaceLeft = 0;
    uint32_t NumberOfItems = 0;
};

template<typename Type>
class stack: public vector<Type> {
  public:
  Type top() {
    return vector<Type>::top();
  }
  bool push_back (const Type DATA) {
    return vector<Type>::push_back(DATA);
  }
  Type pop_back() {
    return vector<Type>::pop_back();
  }
  Type operator [](uint32_t position) const = delete;
  void sort(lambda<Type> LambdaComparator = [](Type a, Type b) {return a < b;}) = delete;
  uint32_t find(const Type ELEMENT) const = delete;
  bool insert(const Type VALUE,const uint32_t POSITION) = delete;
};

int main () {
  vector<int> vector;
  std::cout << "push to vector " << vector.push_back(11) << std::endl;
  std::cout << "push to vector " << vector.push_back(22) << std::endl;
  std::cout << "push to vector " << vector.push_back(33) << std::endl;
  std::cout << "push to vector " << vector.push_back(44) << std::endl;
  std::cout << "push to vector " << vector.push_back(55) << std::endl;
  std::cout << "vector[0] " << vector[0] << std::endl;
  std::cout << "vector[1] " << vector[1] << std::endl;
  std::cout << "vector[2] " << vector[2] << std::endl;
  std::cout << "vector[3] " << vector[3] << std::endl;
  std::cout << "vector[4] " << vector[4] << std::endl;
  std::cout << "vector.find(11) " << vector.find(11) << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << "vector.find(44) " << vector.find(44) << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.push_back(66) << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.push_back(77) << std::endl;
  std::cout << vector.push_back(88) << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;

  std::cout << "push to vector " << vector.push_back(12) << std::endl;
  std::cout << "push to vector " << vector.push_back(55) << std::endl;
  std::cout << "push to vector " << vector.push_back(11) << std::endl;
  std::cout << "push to vector " << vector.push_back(22) << std::endl;
  std::cout << "push to vector " << vector.push_back(44) << std::endl;
  std::cout << "push to vector " << vector.push_back(66) << std::endl;
  std::cout << "push to vector " << vector.push_back(33) << std::endl;
  vector.sort();
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << vector.pop_back() << std::endl;
  std::cout << "Stack" << std::endl;
  stack<int> stack;
  std::cout << stack.push_back(11) << std::endl;
  std::cout << stack.push_back(12) << std::endl;
  std::cout << stack.push_back(13) << std::endl;
  std::cout << stack.push_back(9) << std::endl;
  std::cout << stack.push_back(150) << std::endl;
  std::cout << stack.push_back(123) << std::endl;
  std::cout << stack.pop_back() << std::endl;
  std::cout << stack.pop_back() << std::endl;
  std::cout << stack.pop_back() << std::endl;
  std::cout << stack.pop_back() << std::endl;
  std::cout << stack.pop_back() << std::endl;
}