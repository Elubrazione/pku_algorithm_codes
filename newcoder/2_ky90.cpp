#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  while (getline(cin, str)) {
    if (str == "ENDOFINPUT")  break;
    if (str == "START" || str == "END") continue;
    for (char ch: str) {
      if (ch < 'A' || ch > 'Z') cout << ch;
      else  printf("%c", (ch - 'A' + 21) % 26 + 'A');
    }
    cout << endl;
  }
  return 0;
}