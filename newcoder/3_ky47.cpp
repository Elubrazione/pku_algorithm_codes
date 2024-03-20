#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    while (a != b)
      a > b? a /= 2: b /= 2;
    cout << a << endl;
  }
}