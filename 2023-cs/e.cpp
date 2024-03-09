#include <bits/stdc++.h>
using namespace std;

// 类似动态规划的股票交易问题
int main() {
  int n;
  cin >> n;
  // dp[i][0] 此瓶没喝 dp[i][1]连续第一瓶 dp[i][2]连续第二瓶
  // 状态转移方程
  // dp[i][0] = dp[i-1][2]  // 这瓶没喝是因为前面已经连续喝了两瓶
  // dp[i][1] = dp[i-1][0] + A[i] // 这次是第一瓶是因为上一瓶没喝
  // dp[i][2] = dp[i-1][1] + A[i] // 连续的第二瓶，上一瓶是第一瓶子
  // 初始化 => dp[0][0] = 0, dp[0][1] = A[0], dp[0][2] = 0
  vector<int> drk(n);
  for (int i = 0; i < n; i++) cin >> drk[i];
  vector<int> dp(3, 0);
  dp[1] = drk[0];
  for (int i = 1; i < n; i++) {
    int temp = dp[2];
    dp[2] = dp[1] + drk[i];
    dp[1] = dp[0] + drk[i];
    dp[0] = temp;
  }
  int ans = max(max(dp[0], dp[1]), dp[2]);
  cout << ans;
  return 0;
}

/**
 * Santo 刚刚与房东打赌赢得了一间在 New Clondike 的大客厅。今天，他来到这个大客厅欣赏他的奖品。
 * 房东在酒吧上摆了一排瓶子，瓶子里都装有不同体积的酒。令 Santo 高兴的是，瓶子中的酒都有不同的味道。
 * 房东说道：“你可以喝尽可能多的酒，但是一旦打开酒盖你就必须把它喝完，喝完一瓶后把它放回原处。
 * 还有一件最重要的事，你必须从左至右依次喝，但不能连续三瓶或以上，不然会给你带来坏运气。”
 * 现在可怜的 Santo 站在酒吧前努力地想着，他到底应该喝哪几瓶才能使喝的酒最多呢？请帮助他找出他应该喝的酒瓶号，因为思考让他感到不安。
 *
 * 输入 => 第一行一个整数 N (1<=N<=700) 表示有 N 个酒瓶。接下有 N 行，第 i+1 行的整数 Ai (1<=Ai<=10000) 代表酒瓶 i 中酒的体积。
 * 输出 => 一个整数，表示 Santo 能喝的酒的最大总体积。遵守以上规则，使得任意连续三个瓶子中至少一个瓶子是满的。
*/