#include <bits/stdc++.h>
using namespace std;

string divide(string n, int q, int m) {
  // 字符串除法, q是除数, m是字符串n代表的大整数的进制
  int r = 0;
  for (int i = 0; i < n.size(); i++) {
    int cur = r * m + n[i] - '0';
    n[i] = cur / q + '0';
    r = cur % q;
  }
  int pos = 0;
  // 去除前导0
  while (n[pos] == '0') pos++;
  return n.substr(pos);
}
void convert(string& s, int q) {
  string str = "";
  do {
    str.push_back((s[s.size() - 1] - '0') % 2 + '0'); // 取模
    s = divide(s, 2, 10); // 整除
  } while (s.size());
  reverse(str.begin(), str.end());
  cout << str << endl;
}
int main() {
  string s;
  while (cin >> s)
    convert(s, 2);
  return 0;
}