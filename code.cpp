#include <iostream>
#include <cctype> // Содежрит ф-ции обработки символов
#include <cstring> // Содержит ф-ции обработки строк и массивов
#include <clocale> // Для setlocale()
using namespace std;

int main() {
  char tmp[80];
  int len;
  char* str;

  setlocale(LC_ALL, "Russian"); // Язык отображения - Русский

  while(1) { // Бесконечный цикл
    cout << "Ввод: ";
    cin.getline(tmp, 80); // Заполнение массива tmp
    len = strlen(tmp)+1; // Длина = длина введенного текста + 1 для динамической памяти
    str = new char[len]; // Динамический символьный массив
    strncpy(str, tmp, len); // Использована эта ф-ция вместо strcpy_s, т.к. эту ф-цию не обрабатывает компилятор g++. Она не такая безопасная, но в текущей программе проблем не возникнет

    if (*str==0) { // Проверки на "острые углы"
      cout << "Введена пустая строка!" << endl;
      return 0;
    }
    else if (!(isalpha(tmp[len-3]) && isalpha(tmp[len-2]))) {
      cout << "Введённый ряд символов не заканчивается двумя буквами, либо содержит не латинские буквы!" << endl;
      return 0;
    }

    for (int i = 0; i<len;i++) { // Проверка чтобы не выйти за рамки алфавита в таблице ASCII
      if (*(str+i)=='z') {
      *(str+i)='a';
      continue;
      }
      else if (*(str+i)=='Z') {
        *(str+i)='A';
        continue;
      }
      *(str+i)=*(str+i)+1; // Замена текущего символа на следующий в алфавите
    }
    cout << str << endl; // Полученная строка
    delete []str; // Освобождение памяти str
  }
}
