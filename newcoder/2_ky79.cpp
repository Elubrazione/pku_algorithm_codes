#include <bits/stdc++.h>
using namespace std;

// 浮点数加法
int main() {
  string d1, d2;
  cin >> d1 >> d2;
  int g1 = d1.find('.'), g2 = d2.find('.');
  string i1 = d1.substr(0, g1), i2 = d2.substr(0, g2);
  d1 = d1.substr(g1 + 1, d1.size() - g1);
  d2 = d2.substr(g2 + 1, d2.size() - g2);

  if (d2.size() > d1.size()) swap(d1, d2);
  int len = d1.size() - d2.size();
  for (int i = 0; i < len; i++)
    d2.push_back('0');
  if (i2.size() > i1.size())  swap(i1, i2);
  reverse(i1.begin(), i1.end());
  reverse(i2.begin(), i2.end());

  int add = 0;
  for (int i = d1.size() - 1; i >= 0; i--) {
    int sum = d1[i] - '0' + d2[i] - '0' + add;
    d1[i] = sum % 10 + '0';
    add = sum / 10;
  }
  for (int i = 0; i < i1.size(); i++) {
    int sum = add;
    if (i < i2.size())  sum += i2[i] - '0';
    sum += i1[i] - '0';
    i1[i] = sum % 10 + '0';
    add = sum / 10;
  }
  while (add) {
    i1.push_back(add % 10 + '0');
    add /= 10;
  }
  reverse(i1.begin(), i1.end());
  cout << i1 + "." + d1;
  return 0;
}