// В 22 строке можно написать проверку. Но нужно-ли? Хммммммммм
//ѡ҄ѾҒѳ!.!Ѽ҄҈҉ѹѺ!��ҁѶ��ѿѵѱѳѱ҃ѶѼҍ "c
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include <clocale>
using namespace std;

int main() {
  char tmp[80];
  int len;
  char* str;

  setlocale(LC_ALL, "Russian");

  do {
    int n=0;
    cout << "Ввод: ";
    cin.getline(tmp, 80);
    len = strlen(tmp)+1;
    str = new char[len];
    strncpy(str, tmp, len); // Использована эта ф-ция вместо strcpy_s, т.к. эту ф-цию не обрабатывает компилятор g++. Она не такая безопасная, но в текущей программе проблем не возникнет

    for (int i = 0; i<len;i++) {
      if (*(str+i)=='z') {
      *(str+i)='a';
      continue;
      }
      else if (*(str+i)=='Z') {
        *(str+i)='A';
        continue;
      }
      *(str+i)=*(str+i)+1;
    }

    cout << str << endl;
    delete []str;
  } while(tmp[0] && (isalpha(tmp[len-3]) && isalpha(tmp[len-2])));
  return 0;
}
