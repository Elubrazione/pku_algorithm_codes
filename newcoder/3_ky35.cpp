#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (!b) return a;
  else  return gcd(b, a % b);
}
int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    int cnt = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++) { // down
      for (int j = 0; j < i; j++) { // up
        if (gcd(nums[i], nums[j]) == 1)
          cnt++;
      }
    }
    cout << cnt << endl;
  }
}