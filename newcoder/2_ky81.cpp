#include <bits/stdc++.h>
using namespace std;

vector<string> s;
int main() {
  string a, ans;
  int len = 0, add = 0;
  while (cin >> a) {
    if (a == "0") break;
    len = max(len, (int)a.size());
    reverse(a.begin(), a.end());
    s.push_back(a);
  }
  for (int i = 0; i < len; i++) {
    int sum = add;
    for (auto str: s) {
      if (str.size() <= i)  continue;
      sum += str[i] - '0';
    }
    ans.push_back(sum % 10 + '0');
    add = sum / 10;
  }
  while (add) {
    ans.push_back(add % 10 + '0');
    add /= 10;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}