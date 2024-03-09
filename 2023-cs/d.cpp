#include <bits/stdc++.h>
using namespace std;

// 基础的动态规划问题，类似leetcode上那道二叉搜索树的数量
// 这道题的重点是递推公式
int main() {
  int n, cnt = 0;
  cin >> n;
  // dp[i]代表具有i个节点的二叉树的形态数量
  // 状态转移方程 => dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-1] + ... + dp[i-1]*dp[0]
  // 初始化 => dp[0] = 1, dp[1] = dp[0]*dp[0] = dp[1] = 1
  // 遍历顺序 => 从小到大
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  cout << dp[n];
  return 0;
}

/**
 * 输入n(1<n<13)，求n个结点的二叉树有多少种形态
*/