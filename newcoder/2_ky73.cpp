#include <bits/stdc++.h>
using namespace std;

// 两个最长公共上升子序列
vector<int> nums1, nums2;
vector<int> dp1, dp2;
int main() {
  int n, res = 0;
  cin >> n;
  nums1.resize(n, 0);
  nums2.resize(n, 0);
  dp1.resize(n, 1);
  dp2.resize(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
    nums2[n - 1 - i] = nums1[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums1[i] > nums1[j])
        dp1[i] = max(dp1[i], dp1[j] + 1);
      if (nums2[i] > nums2[j])
        dp2[i] = max(dp2[i], dp2[j] + 1);
    }
  }
  for (int i = 0; i < n; i++)
    res = max(res, dp1[i] + dp2[n - 1 - i]);
  cout << n - res + 1;
  return 0;
}