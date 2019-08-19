#include <iostream>

unsigned StringLength(const char* ARRAY) {
  if (ARRAY != nullptr) {
    unsigned i = 0;
    while (ARRAY[i] != '\0') {
      ++i;
    }
    return i;
  }
  return 0;
}

bool StringComapare(const char* ARRAY1, const char* ARRAY2,const unsigned LENGTH2) {
  if ((ARRAY1 != nullptr) && (ARRAY2 != nullptr)  && (ARRAY2 != ARRAY1)) {
    for (unsigned i = 0; i <= LENGTH2 ; ++i) {
      if (ARRAY1[i] != ARRAY2[i]) return 0;
    }
    return 1;
  }
  return 0;
}

void PrintTextFromArray(char* text, const unsigned TEXT_SIZE) {
  if (text != nullptr) {
  for(int i = 0; i < TEXT_SIZE ; ++i) {
    std::cout << text[i];
  }
    std::cout << "\n";
  }
}

void ClearArray(char* arr, const unsigned ARRAY_SIZE) {
  if (arr != nullptr) {
    for (unsigned i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = '\0';
    }
  }
}

int ArrayLength(const char* ARRAY, const unsigned ARRAY_SIZE) {
  if (ARRAY != nullptr) {
    unsigned LastCharPosition = 0;
    for (unsigned i = 0; i < ARRAY_SIZE; ++i) {
      if (ARRAY[i] > ' ') {
        LastCharPosition = i;
      }
    }
    return LastCharPosition + 1;
  }
  return 0;
}

void PushApart(char* Array, const unsigned ARRAY_SIZE, const unsigned START_POINT, const unsigned SIZE) {
  if (Array != nullptr) {
    for (unsigned i = 0; (ARRAY_SIZE - SIZE - i) > START_POINT ; ++i) {
      Array[ARRAY_SIZE - i - 1] = Array[ARRAY_SIZE - i - SIZE - 1];
    }
  }
}

void InputPrint (char* text, char* buf, unsigned int* PointerInText, const unsigned BUF_SIZE) {
  if ((nullptr != text) && (nullptr != buf) && (nullptr != PointerInText) && (text != buf)) {
    unsigned counter = 0;
    for (unsigned i = 0; i < ArrayLength(buf,BUF_SIZE); ++i) {
      text[*PointerInText + i] = buf[i];
      ++counter;
    }
    *PointerInText += counter;
  }
}

void SelectText (unsigned int* SelectStart,unsigned int* SelectLength) {
  if ((nullptr != SelectStart) && (nullptr != SelectLength) && (SelectStart != SelectLength)) {
    std::cin >> *SelectStart;
    std::cin >> *SelectLength;  
  }
}

void CopyTextFromArrayToArray (char* FromArr, char* ToArr, unsigned int StartPoint, unsigned int length) {
  if ((nullptr != FromArr) && (nullptr != ToArr) && (ToArr != FromArr)) {
    ClearArray(ToArr, length);
    for(unsigned int i = 0; i < length; ++i) {
      ToArr[i] = FromArr[i + StartPoint - 1];
    }
  }
}

void MovePointer(char* command,unsigned int* PointerInText,const unsigned TEXT_SIZE, const unsigned COMMAND_SIZE) {
  if ((nullptr != command) && (nullptr != PointerInText)) {
    const char* LEFT_COMAND = "left";
    const char* RIGHT_COMAND = "right";
    ClearArray(command, COMMAND_SIZE);
    std::cin >> command;
    unsigned int shift;
    std::cin >> shift;
    if (StringComapare(command, LEFT_COMAND, StringLength(LEFT_COMAND))) {
      if (shift > *PointerInText) {
        std::cout << "Too big shift in left. "<< shift << " should be less/equal than " << *PointerInText << ". Try again: \n";
        return;
      }
    *PointerInText = *PointerInText - shift;
    } else if (StringComapare(command, RIGHT_COMAND, StringLength(RIGHT_COMAND))) {
      if (shift > (TEXT_SIZE - *PointerInText)) {
        std::cout << "Too big shift in right. "<< shift << " should be greater than " << *PointerInText << ". Try again: \n";
        return;
      }
      *PointerInText = *PointerInText + shift;
    } else {
      std::cout << "Something wrong, try again\n";
      return;
    }
  }
}

void ShiftOfTextInArrayToLeft(char* text,unsigned int SelectStart,unsigned int SelectEnd) {
  if (nullptr != text) {
    unsigned int i = 0;
    while(text[SelectStart + i] != '\0') {
    text[SelectStart + i - 1] = text[SelectEnd + i - 1];
    ++i;
    }
    text[SelectStart + i - 1] = text[SelectEnd + i - 1];
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
const char* PRINT_COMAND = "print";
const char* SELECT_COMAND = "select";
const char* COPY_COMAND = "copy";
const char* PASTE_COMAND = "paste";
const char* MOVE_COMAND = "move";
const char* CUT_COMAND = "cut";
const char* SHOW_COMAND = "show";
const char* STOP_COMAND = "stop";
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
  ClearArray(command,COMMAND_SIZE);
  std::cin >> command;
  if (StringComapare(command, PRINT_COMAND, StringLength(PRINT_COMAND))) {
    ClearArray(InpBuf, BUF_SIZE);
    scanf("%[^\n]",InpBuf);
    for (unsigned i = 0; i < (BUF_SIZE - 1); ++i) {
      InpBuf[i]=InpBuf[i + 1];
    }
    PushApart(text, TEXT_SIZE, PointerInText, ArrayLength(InpBuf,BUF_SIZE));
    InputPrint (text, InpBuf, &PointerInText,BUF_SIZE);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, SELECT_COMAND, StringLength(SELECT_COMAND))) {
    SelectText (&SelectStart, &SelectLength);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, COPY_COMAND, StringLength(COPY_COMAND))) {
    if ((SelectStart == 0) || (SelectLength == 0)) continue;
    CopyTextFromArrayToArray (text, buffer, SelectStart, SelectLength);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, PASTE_COMAND, StringLength(PASTE_COMAND))) {
    PushApart(text, TEXT_SIZE, PointerInText, ArrayLength(buffer,BUF_SIZE));
    InputPrint (text, buffer, &PointerInText, BUF_SIZE);
    SelectStart = 0;
    SelectLength = 0;
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, MOVE_COMAND, StringLength(MOVE_COMAND))) {
    MovePointer(command, &PointerInText, TEXT_SIZE, COMMAND_SIZE);
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, CUT_COMAND, StringLength(CUT_COMAND))) {
    if (SelectLength == 0) {
      continue;
    }
    ClearArray(buffer,BUF_SIZE);
    CopyTextFromArrayToArray (text, buffer, SelectStart, SelectLength);
    ShiftOfTextInArrayToLeft(text, SelectStart, SelectLength + SelectStart);
    PointerInText -= SelectLength;
    SelectStart = 0;
    SelectLength = 0;
    continue;
  }
//--------------------------------------------------------------------
  if (StringComapare(command, SHOW_COMAND, StringLength(SHOW_COMAND))) {
      PrintTextFromArray(text, TEXT_SIZE);
      continue;
  }
//--------------------------------------------------------------------
    if (StringComapare(command, STOP_COMAND, StringLength(STOP_COMAND))) {
      break;
    }
//--------------------------------------------------------------------

      std::cout << "Wrong comand. Please try again: " << std::endl;

  }
}

