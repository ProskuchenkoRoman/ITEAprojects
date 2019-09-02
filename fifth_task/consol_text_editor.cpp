#include <iostream>

//g++ -std=c++14 -Wall -Werror -pedantic -O2  consol_text_editor.cpp

namespace {
const char* PRINT_COMAND = "print";
const char* SELECT_COMAND = "select";
const char* COPY_COMAND = "copy";
const char* PASTE_COMAND = "paste";
const char* MOVE_COMAND = "move";
const char* CUT_COMAND = "cut";
const char* SHOW_COMAND = "show";
const char* STOP_COMAND = "stop";
const char* LEFT_COMAND = "left";
const char* RIGHT_COMAND = "right";
}

unsigned StringLength(const char* ARRAY) {
  if (ARRAY != nullptr) {
    unsigned i = 0;
    while (ARRAY[i] != '\0') {
      ++i;
    }
    return i;
  }
  return false;
}

bool StringComapare(const char* ARRAY1, const char* ARRAY2) {
  if ((ARRAY1 != nullptr) && (ARRAY2 != nullptr)  && (ARRAY2 != ARRAY1)) {
    const unsigned LENGTH1 = StringLength (ARRAY1);
    const unsigned LENGTH2 = StringLength (ARRAY2);
    if (LENGTH1 != LENGTH2) return false;
    for (unsigned i = 0; i <= LENGTH2 ; ++i) {
      if (ARRAY1[i] != ARRAY2[i]) return false;
    }
    return true;
  }
  return false;
}

void PrintTextFromArray(char* text) {
  if (nullptr == text) return;
  unsigned i = 0;
  while (text[i]) {
    std::cout << text[i++];
  }
    std::cout << "\n";
}

void ClearArray(char* arr) {
  if (arr != nullptr) {
    unsigned i = 0;
    while (arr[i]) {
        arr[i++] = '\0';
    }
  }
}

bool ArrayShift(char* Array, const unsigned ARRAY_SIZE, const unsigned START_POINT, const unsigned SIZE) {
  if (nullptr == Array) return 0;
  if ((START_POINT + SIZE) > ARRAY_SIZE) {
    std::cout << "This buffer hasn't got enough space.";
    return false;
  }
  for (unsigned i = 0; (ARRAY_SIZE - SIZE - i) > START_POINT ; ++i) {
    Array[ARRAY_SIZE - i - 1] = Array[ARRAY_SIZE - i - SIZE - 1];
  }
  return true;
}

void InputPrint (char* text, char* buf, unsigned& PointerInText) {
  if ((nullptr != text) && (nullptr != buf) && (text != buf) && (StringLength(buf) > 0)) {
    const unsigned BUF_SIZE = StringLength(buf);
    for (unsigned i = 0; i < BUF_SIZE; ++i) {
      text[PointerInText + i] = buf[i];
    }
    PointerInText += BUF_SIZE;
  }
}

void SelectText (unsigned int* SelectStart,unsigned int* SelectLength) {
  if ((nullptr != SelectStart) && (nullptr != SelectLength) && (SelectStart != SelectLength)) {
    std::cin >> *SelectStart;
    std::cin >> *SelectLength;  
  }
}

void CopyTextFromArrayToArray (char* FromArr, char* ToArr, const unsigned int START_POINT, const unsigned int LENGTH) {
  if ((nullptr != FromArr) && (nullptr != ToArr) && (ToArr != FromArr)) {
    for(unsigned int i = 0; i < LENGTH; ++i) {
      ToArr[i] = FromArr[i + START_POINT - 1];
    }
  }
}

void MovePointer(unsigned* PointerInText,const unsigned TEXT_SIZE, const unsigned COMMAND_SIZE) {
  if (nullptr != PointerInText) {
    const unsigned COMMAND_SIZE = 10;
    char command[COMMAND_SIZE] {};
    unsigned int shift;
    std::cin >> command >> shift;
    if (StringComapare(command, LEFT_COMAND)) {
      if (shift > *PointerInText) {
        std::cout << "Too big shift in left. "<< shift << " should be less/equal than " << *PointerInText << ". Try again: \n";
        return;
      }
    *PointerInText = *PointerInText - shift;
    } else if (StringComapare(command, RIGHT_COMAND)) {
      if (shift > (TEXT_SIZE - *PointerInText)) {
        std::cout << "Too big shift in right. "<< shift << " should be greater than " << *PointerInText << ". Try again: \n";
        return;
      }
      *PointerInText = *PointerInText + shift;
    } else {
      std::cout << "Something wrong, try again\n";
    }
  }
}

void ShiftOfTextInArrayToLeft(char* text,const unsigned SELECT_START,const unsigned SELECT_END) {
  if ((nullptr != text) || (SELECT_START < 1)) {
    unsigned int i = 0;
    while(text[SELECT_START + i] != '\0') {
    text[SELECT_START + i - 1] = text[SELECT_END + i - 1];
    ++i;
    }
    text[SELECT_START + i - 1] = '\0';
  }
}


int main()
{
const unsigned TEXT_SIZE = 200;
const unsigned COMMAND_SIZE = 10;
const unsigned BUF_SIZE = 50;
char command[COMMAND_SIZE] {};
char text[TEXT_SIZE] {};
char buffer[BUF_SIZE] {};
char InpBuf[BUF_SIZE] {};
unsigned int PointerInText = 0;
unsigned int SelectStart = 0;
unsigned int SelectLength = 0;
std::cout << "Hello! It is simple console text editor.\n";
std::cout << "Here is comands that you can use: \n";
std::cout << "---> print some_text \n";
std::cout << "---> select number_of_first_char length\n";
std::cout << "---> copy (copy selected part of text) \n";
std::cout << "---> paste (paste text from buffer from pointer in text) \n";
std::cout << "---> move left/right (move pointer in text) \n";
std::cout << "---> show (see text with which you work) \n";
std::cout << "---> stop (terminate program) \n";
std::cout << "Try first command:";

  while(true) {
  ClearArray(command);
  std::cin >> command;
  if (StringComapare(command, PRINT_COMAND)) {
    ClearArray(InpBuf);
    scanf("%[^\n]",InpBuf);
    if (ArrayShift(text, TEXT_SIZE,PointerInText, StringLength(InpBuf + 1))) {
    InputPrint (text, InpBuf + 1, PointerInText);
    }
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, SELECT_COMAND)) {
    SelectText (&SelectStart, &SelectLength);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, COPY_COMAND)) {
    if ((SelectStart == 0) || (SelectLength == 0)) {
      continue;
    }
    CopyTextFromArrayToArray (text, buffer, SelectStart, SelectLength);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, PASTE_COMAND)) {
    if (ArrayShift(text, TEXT_SIZE,PointerInText, StringLength(buffer))) {
    InputPrint (text, buffer, PointerInText);
    }
    SelectStart = 0;
    SelectLength = 0;
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, MOVE_COMAND)) {
    MovePointer(&PointerInText, TEXT_SIZE, COMMAND_SIZE);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, CUT_COMAND)) {
    if (SelectLength == 0) {
      continue;
    }
    ClearArray(buffer);
    CopyTextFromArrayToArray (text, buffer, SelectStart, SelectLength);
    ShiftOfTextInArrayToLeft(text, SelectStart, SelectLength + SelectStart);
    PointerInText -= SelectLength;
    SelectStart = 0;
    SelectLength = 0;
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, SHOW_COMAND)) {
      PrintTextFromArray(text);
      continue;
  }
//--------------------------------------------------------------------
    if (StringComapare(command, STOP_COMAND)) {
      break;
    }
//--------------------------------------------------------------------

      std::cout << "Wrong comand. Please try again: " << std::endl;

  }
}