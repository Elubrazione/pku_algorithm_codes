/**
 * 在一个长度为n(1 < n < 1000)的整数（0至1000之间）序列中，
 * 选出两个元素使得它们的和最接近但不超过K(0 <= K < 2000)。
 * 保证一定存在不超过K的两元素和。
 *
 * 输入
 * 第一行输入一个整数n
 * 第二行输入一个整数K
 * 第三行输入序列，用空格分开
 *
 * 输出
 * 最接近但不超过K的和
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, mx = INT_MIN;
  cin >> n >> k;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int left = 0, right = n - 1;
  while (left < right) {
    if (nums[left] + nums[right] <= k) {
      mx = max(mx, nums[left] + nums[right]);
      left++;
    } else {
      right--;
    }
  }
  cout << mx;
  return 0;
}