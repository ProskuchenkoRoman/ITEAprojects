// Example program
#include <iostream>

void ClearArray(char* arr);
int ArrayLength(char* arr);
void PushApart(char* arr,int arr_size,int start, int size);
void ShiftOfTextInArrayToLeft(char* text,unsigned int SelectStart,unsigned int SelectEnd, bool* fault);
void InputPrint (char* text,char* InputBuffer, unsigned int* PointerInText,bool* fault);
void SelectText (unsigned int* SelectStart,unsigned int* SelectEnd, bool* fault);
void CopyTextFromArrayToArray (char* FromArr, char* ToArr, unsigned int StartPoint, unsigned int length, bool clear);
void PasteTextFromBuffer(char* buffer,char* text,unsigned int* PointerInText,unsigned int* SelectStart, unsigned int* SelectEnd, bool* fault);
void MovePointer(char* command,unsigned int* PointerInText,const int text_size,bool* fault);
void MoveArrayClother(char* text,unsigned int SelectStart,unsigned int SelectEnd, bool* fault);
void PrintTextFromArray(char* text, bool* fault);

int main()
{
    const int text_size = 200;
    const int command_size = 10;
    const int buf_size = 50;
char command[command_size] {};
char text[text_size] {};
char buffer[buf_size] {};
char InpBuf[buf_size] {};
unsigned int PointerInText = 0;
unsigned int SelectStart = 0;
unsigned int SelectEnd = 0;
bool fault = true;
bool clear = true;
std::cout << "Hello! It is simple console text editor.\n";
std::cout << "Here is comands that you can use: \n";
std::cout << "---> print some_text (without spaces text that you want save) \n";
std::cout << "---> select number_of_first_char number_of_last_char (start < end) \n";
std::cout << "---> copy(copy selected part of text) \n";
std::cout << "---> paste(paste text from buffer from point where you 'select') \n";
std::cout << "---> move left\right (move pointer in text) \n";
std::cout << "---> show (see text with which you work) \n";
std::cout << "---> stop (terminate program) \n";
std::cout << "Try first command:";

  while(true) {
  fault = true;
  ClearArray(command);
  std::cin >> command;
// Part with entering of new text to main buffer
  if ((command[0] == 'p') && (command[1] == 'r') && (command[2] == 'i') && (command[3] == 'n') && (command[4] == 't') && (command[5] == '\0')) {
    std::cin >> InpBuf;
    PushApart(text, text_size, PointerInText, ArrayLength(InpBuf));
    InputPrint (text, InpBuf, &PointerInText, &fault);
  }
//--------------------------------------------------------------------
  if ((command[0] == 's') && (command[1] == 'e') && (command[2] == 'l') && (command[3] == 'e') && (command[4] == 'c') && (command[5] == 't') && (command[6] == '\0')) {
    SelectText (&SelectStart, &SelectEnd, &fault);
  }
//--------------------------------------------------------------------
  if ((command[0] == 'c') && (command[1] == 'o') && (command[2] == 'p') && (command[3] == 'y') && (command[4] == 't')) {
    clear = true;
    CopyTextFromArrayToArray (text, buffer, SelectStart, (SelectEnd - SelectStart), clear);
    fault = false;
  }
//--------------------------------------------------------------------
  if ((command[0] == 'p') && (command[1] == 'a') && (command[2] == 's') && (command[3] == 't') && (command[4] == 'e') && (command[5] == '\0')) {
    PushApart(text, text_size, PointerInText, ArrayLength(buffer));
    InputPrint (text, buffer, &PointerInText, &fault);
    SelectStart = 0;
    SelectEnd = 0;
  }
//--------------------------------------------------------------------
  if ((command[0] == 'm') && (command[1] == 'o') && (command[2] == 'v') && (command[3] == 'e') && (command[4] == '\0')) {
    MovePointer(command, &PointerInText, text_size, &fault);
  }
//--------------------------------------------------------------------
  if ((command[0] == 'c') && (command[1] == 'u') && (command[2] == 't') && (command[3] == '\0')) {
    if (SelectEnd == 0) {
      continue;
    }
    ClearArray(buffer);
    CopyTextFromArrayToArray (text, buffer, SelectStart, (SelectEnd - SelectStart), clear);
    ShiftOfTextInArrayToLeft(text, SelectStart, SelectEnd, &fault);
    PointerInText = SelectStart - 1;
    SelectStart = 0;
    SelectEnd = 0;
  }
//--------------------------------------------------------------------
  if ((command[0] == 's') && (command[1] == 'h')) {
      PrintTextFromArray(text, &fault);
  }
//--------------------------------------------------------------------
    if ((command[0] == 's') && (command[1] == 't')) {
      break;
    }
//--------------------------------------------------------------------
    if (fault) {
      std::cout << "\nWrong comand. Please try again: ";
    }
  }
}

void PrintTextFromArray(char* text, bool* fault) {
  for(int i = 0; text[i] != '\0' ; ++i) {
    std::cout << text[i];
  }
    std::cout << "\n";
    *fault = false;
}

void ClearArray(char* arr) {
    int i = 0;
    while(*(arr+i) != '\0') {
        *(arr+i) = '\0';
        ++i;
    }
}

int ArrayLength(char* arr) {
  int i = 0;
  while (*(arr+i) != '\0') {
    ++i;
  }
  --i;
  return i;
}

void PushApart(char* arr,int arr_size,int start, int size) {
    ++size;
  for (int i = 0; i < (arr_size-start-size +2);++i) {
    *(arr + arr_size - i) = *(arr + arr_size - i - size);
  }
}

void InputPrint (char* text, char* buf, unsigned int* PointerInText,bool* fault) {
  unsigned int i = 0;
  while (*(buf+i) != '\0') {
  *(text + *PointerInText + i) = *(buf+i);
  ++i;
  }
  *PointerInText += i;
  *fault = false;
}

void SelectText (unsigned int* SelectStart,unsigned int* SelectEnd, bool* fault) {
    std::cin >> *SelectStart;
    std::cin >> *SelectEnd;
    if (*SelectStart > *SelectEnd) {
      std::cout << "Please, enter command again (start <= end)\n";
    }     
    *fault = false;
}

void CopyTextFromArrayToArray (char* FromArr, char* ToArr, unsigned int StartPoint, unsigned int length, bool clear) {
  if (clear) { 
    ClearArray(ToArr);
    for(unsigned int i = 0; i <= length; ++i) {
      *(ToArr + i) = *(FromArr + i + StartPoint - 1);
    }
  } else {
    for(unsigned int i = 0; i <= length; ++i) {
      *(ToArr + i + StartPoint - 1) = *(FromArr + i);
    }   
  }
}

void MovePointer(char* command,unsigned int* PointerInText,const int text_size,bool* fault) {
  ClearArray(command);
  std::cin >> command;
  unsigned int shift;
  std::cin >> shift;
  if ((*command == 'l') && (*(command + 1) == 'e')) {
    if (shift > *PointerInText) {
      std::cout << "Too big shift in left. "<< shift << " should be less/equal than " << *PointerInText << ". Try again: \n";
      return;
    }
  *PointerInText = *PointerInText - shift;
  } else if ((*command == 'r') && (*(command+1) == 'i')) {
    if (shift > (text_size - *PointerInText)) {
      std::cout << "Too big shift in right. "<< shift << " should be greater than " << *PointerInText << ". Try again: \n";
      return;
    }
    *PointerInText = *PointerInText + shift;
  }
  *fault = false;
}

void ShiftOfTextInArrayToLeft(char* text,unsigned int SelectStart,unsigned int SelectEnd, bool* fault) {
    unsigned int i = 0;
    while(*(text+SelectStart+i-1) != '\0') {
    *(text + SelectStart + i - 1)=*(text + SelectEnd + i);
    ++i;
    }
    *fault = false;
}
