/**
 * 有一根长度为n的木材（n为不大于100的正整数），要将其切割为m（0 < m < n) 段出售，每段均为正整数长度。
 * 不同长度的木材具有不同的售价p（0 < p < 100)。求一个最优的切割方案，以尽可能卖出更多的钱。
 *
 * 输入
 * 第一行为n
 * 第二行为m
 * 第三行包含 n 个数字，第 i 个数字出售长为 i 的木材的价格，用空格隔开
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> nums;
void backtracking(int num, int s, int target) {
  if (num >= m && !target) {
    if (s > ans)  ans = s;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (target < 0) break;
    
  }
}

int main() {
  cin >> n >> m;
  nums.resize(n + 1, 0);
  for (int i = 1; i <= n; i++)  cin >> nums[i];

  return 0;
}