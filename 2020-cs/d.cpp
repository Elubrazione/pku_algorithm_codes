/**
 * 小A擅长制作香蕉蛋糕和巧克力蛋糕。
 * 制作一个香蕉蛋糕需要2个单位的香蕉，250个单位的面粉，75个单位的糖，100个单位的黄油。
 * 制作一个巧克力蛋糕需要75个单位的可可粉，200个单位的面粉，150个单位的糖，150个单位的黄油。
 * 一个香蕉蛋糕可以卖出400元，而一个巧克力蛋糕可以卖出450元。
 * 为了避免蛋糕变质，每种蛋糕至多只能制作100个。
 * 现已知每种原料的数量，求小A至多可以卖出多少元的蛋糕。
 *
 * 输入
 * 依次输入面粉、香蕉、糖、黄油、可可粉的数量，每种原料数量均为不超过10^5的整数.
 *
 * 输出
 * 依次输出卖出的钱数、香蕉蛋糕数量、巧克力蛋糕数量，每个数占一行。
*/

// 不要想太多，直接双重循环暴力枚举香蕉和巧克力的数量即可。
// 用sum和ansi以及ansj来记录最大值

#include <bits/stdc++.h>
using namespace std;
int mf, xj, t, hy, kkf;

bool calculate(int i, int j) {
  if (i > 100 || j > 100) return false;
  if (i * 250 + j * 200 > mf) return false;
  if (i * 75 + j * 150 > t) return false;
  if (i * 100 + j * 150 > hy)  return false;
  return true;
}
int main() {
  int sum = 0, ansi = 0, ansj = 0;
  cin >> mf >> xj >> t >> hy >> kkf;
  for (int i = 0; i < xj / 2; i++) { // 香蕉
    for (int j = 0; j < kkf / 75; j++) {  // 可可粉
      if (calculate(i, j)) {
        int cur = i * 400 + j * 450;
        if (cur > sum) {
          sum = cur;
          ansi = i, ansj = j;
        }
      }
    }
  }
  printf("%d\n%d\n%d", sum, ansi, ansj);
  return 0;
}