#include <iostream>
using namespace std;

int main() {
  int x, y;
  while (cin >> x >> y) {
    int md = x % 2;
    if (y == x) {
      cout << x + x - md << endl;
    } else if (y + 2 == x) {
      cout << x + x - md - 2 << endl;
    } else {
      cout << "No Number\n";
    }
  }
  return 0;
}