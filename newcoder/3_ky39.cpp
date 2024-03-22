#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;

int div(string& c, int x) {
  int r = 0;
  for (int i = 0; i < c.size(); i++) {
    int k = r * 10 + c[i] - '0';
    // c[i] = k / x + '0';
    r = k % x;
  }
  if (r)  return false;
  else  return true;
}

int main() {
  while (cin >> s) {
    ans.clear();
    if (s == "-1")  break;
    for (int i = 2; i < 10; i++) {
      if (div(s, i))
        ans.push_back(i);
    }
    if (!ans.size()) {
      cout << "none\n";
      continue;
    }
    for (int i = 0; i < ans.size(); i++) {
      if (i != ans.size() - 1)  printf("%d ", ans[i]);
      else  printf("%d\n", ans[i]);
    }
  }
}