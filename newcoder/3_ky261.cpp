#include <iostream>
using namespace std;

int main() {
  int A, B, g;
  while (cin >> A >> B >> g) {
    int a = 0, b = 0;
    while (!(a == g || b == g || a + b == g)) {
      if (a == A) {
        cout << "empty A" << endl;
        a = 0;
      } else if (b == 0) {
        cout << "fill B" << endl;
        b = B;
      } else {
        cout << "pour B A" << endl;
        if (b + a <= A) a = a + b, b = 0;
        else b = b - (A - a), a = A;
      }
    }
    cout << "success" << endl;
  }
  return 0;
}