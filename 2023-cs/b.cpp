#include <bits/stdc++.h>
using namespace std;

// 暴力模拟
int main() {
  int n, m;
  cin >> n >> m;
  int nums[n][m] = {0}, ans[n][m] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> nums[i][j];
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        ans[i][j] = nums[i][j];
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      ans[i][j] = nums[i - 1][j] + nums[i + 1][j] + nums[i][j - 1] + nums[i][j + 1] + nums[i][j];
      ans[i][j] /= 5;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", ans[i][j]);
      if (j != m - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

/**
 * 给定n行m列的图像各像素点的灰度值，要求用如下方法对其进行模糊化处理：
  1. 四周最外侧的像素点灰度值不变；
  2. 中间各像素点新灰度值为该像素点及其上下左右相邻四个像素点原灰度值的平均（舍入到最接近的整数）。

  输入
  第一行包含两个整数n和m，表示图像包含像素点的行数和列数。1 <= n <= 100，1 <= m <= 100。
  接下来n行，每行m个整数，表示图像的每个像素点灰度。相邻两个整数之间用单个空格隔开，每个元素均在0~255之间。

  输出
  n行，每行m个整数，为模糊处理后的图像。相邻两个整数之间用单个空格隔开。
*/