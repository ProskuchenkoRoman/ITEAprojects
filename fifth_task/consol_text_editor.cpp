// Example program
#include <iostream>
#include <string>

void ClearArray(char* arr);

int main()
{
    const int text_size = 2054;
    const int command_size = 10;
    const int buf_size = 300;
char command[command_size] {};
char text[text_size] {};
char buffer[buf_size] {};
char InputBuffer[buf_size] {};
unsigned int PointerInText = 0;
unsigned int SelectStart = 0;
unsigned int SelectEnd = 0;
bool fault = true;
std::cout << "Hello! It is simple console text editor.\n";
std::cout << "Here is comands that you can use: \n";
std::cout << "print some_text (without spaces text that you want save) \n";
std::cout << "select number_of_first_char number_of_last_char (start < end) \n";
std::cout << "copy(copy selected part of text) \n";
std::cout << "paste(paste text from buffer from point where you finised write or where you 'move') \n";
std::cout << "move(copy selected part of text) \n";
std::cout << "Try first command:";

while(true) {
    fault = true;
  ClearArray(command);
  std::cin >> command;
// Part with entering of new text to main buffer
  if ((command[0] == 'p') && (command[1] == 'r')) {
    ClearArray(InputBuffer);
    std::cin >> InputBuffer;
    for(int i = 0; InputBuffer[i] != '\0'; ++PointerInText,++i) {
      text[PointerInText] = InputBuffer[i];
    }
    
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 's') && (command[1] == 'e')) {
        std::cin >> SelectStart;
        std::cin >> SelectEnd;
        if (SelectStart > SelectEnd) {
          std::cout << "Please, enter command again (start <= end)\n";
          continue;
        }     
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 'c') && (command[1] == 'o')) {
      ClearArray(buffer);
      for(unsigned int i = SelectStart - 1; i <= (SelectEnd - 1); ++i) {
      buffer[i-(SelectStart - 1)] = text[i];
      }    
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 'p') && (command[1] == 'a')) {
      for (int i = 0; buffer[i] != 0 ;++i) {
        text[i+PointerInText] = buffer[i];
      }
      PointerInText = PointerInText + (SelectEnd - SelectStart);
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 'm') && (command[1] == 'o')) {
      ClearArray(command);
      std::cin >> command;
      unsigned int shift;
      std::cin >> shift;
      if ((command[0] == 'l') && (command[1] == 'e')) {
        if ((shift - 1) > PointerInText) {
        std::cout << "Too big shift in left. "<< shift << "should be less/equal than " << PointerInText;
        }
        PointerInText = PointerInText - shift;
      } else if ((command[0] == 'r') && (command[1] == 'i')) {
        if (shift > (text_size - PointerInText)) {
        std::cout << "Too big shift in right. "<< shift << "should be greater than " << PointerInText;
        }
        PointerInText = PointerInText + shift;
      }
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 'c') && (command[1] == 'u')) {
      ClearArray(buffer);
      for(unsigned int i = SelectStart - 1; i <= (SelectEnd - 1); ++i) {
      buffer[i-(SelectStart - 1)] = text[i];
      text[i] = text[i+SelectEnd-SelectStart];
      }
      
    fault = false;
    }
//--------------------------------------------------------------------
    if ((command[0] == 's') && (command[1] == 'h')) {
      for(int i=0;text[i] != '\0';i++) {
        std::cout << text[i];
      }
    fault = false;
    }
//--------------------------------------------------------------------
    if (fault) {
      std::cout << "\nWrong comand. Please try again: ";
    }
}
}


void ClearArray(char* arr) {
    int i = 0;
    while(*(arr+i) != '\0') {
        *(arr+i) = '\0';
        ++i;
    }
}
