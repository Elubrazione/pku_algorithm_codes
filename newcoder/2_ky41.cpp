#include <iostream>
using namespace std;

const int maxn = 12;
int dp[maxn][maxn];
// dp[i][j]表示有i个苹果j个盘子

int main() {
  int m, n;
  while(scanf("%d %d", &m, &n) != EOF) {
    for(int i = 1; i <= m; i++) dp[i][0] = 0; // 0个盘子，非0苹果，没法分
    for(int j = 0; j <= n; j++) dp[0][j] = 1; // 0个苹果，只有一种分法
    for(int i = 1; i <= m; i++) {
      for(int j = 1; j <= n; j++) {
        if(j > i) dp[i][j] = dp[i][i];  // 摔碎多余的盘子
        else dp[i][j] = dp[i - j][j] + dp[i][j - 1];  // 没有多余的盘子+至少多余一个盘子
      }
    }
    printf("%d\n",dp[m][n]);
  }
  return 0;
}