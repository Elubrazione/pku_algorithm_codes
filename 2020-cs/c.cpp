/**
 * 有N（不大于100）种硬币，编号为1至N，
 * 已知每种硬币的重量（不超过100的正整数）和面额（不超过100的正整数），
 * 每种硬币数量不限。选取总重量不超过C（不大于1000的正整数）的硬币，最多能获得多少总面额？
 * 输入
 * 第一行输入N
 * 第二行输入C
 * 第三行输入各硬币重量，用空格隔开
 * 第四行输入各硬币价值，用空格隔开
 * 输出
 * 最大总面额
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> weight(n), cost(n);
  vector<int> dp(c + 1, 0);
  for (int i = 0; i < n; i++) cin >> weight[i];
  for (int i = 0; i < n ; i++) cin >> cost[i];
  for (int i = 0; i < n; i++) {
    for (int j = weight[i]; j <= c; j++) {
      dp[j] = max(dp[j], dp[j - weight[i]] + cost[i]);
    }
  }
  cout << dp[c];
  return 0;
}