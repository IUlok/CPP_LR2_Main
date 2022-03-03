#include <iostream>
#include <cctype>
#include <clocale>
#include <cstring>
using namespace std;

int main() {
  char tmp[80];
  int len;
  char *str;
  chat *p;

  setlocale(LC_ALL, "Russian");

  do {
    cin.getline(tmp, 80);
    len = strlen(tmp)+1;
    str = new char[len];
    p = strcpy_s(str, len, tmp);

    while (*str) {
      *str=(*str)++;
      str++;
    }
    cout << str << endl;
    delete []str;
  }
  while(tmp[0]&&!isalpha(tmp[len-1])&&!isalpha(tmp[len-2]));
  return 0;
}
