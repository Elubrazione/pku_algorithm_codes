#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int nums[N + 1][N + 1], sum[N + 1][N + 1];

int main() {
  int n, mx = INT_MIN;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> nums[i][j];
      sum[i][j] = nums[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = i; p <= n; p++) {
        for (int q = j; q <= n; q++) {
          int cur = sum[p][q] - sum[i - 1][q] - sum[p][j - 1] + sum[i - 1][j - 1];
          if (cur > mx) mx = cur;
        }
      }
    }
  }
  cout << mx;
  return 0;
}