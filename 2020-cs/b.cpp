/**
 * 有N（不大于10）座城市，编号为1至N
 * 已知任意两个城市间直接距离（不超过1000的非负整数）。
 * 求距离（直接或间接）城市1不超过K（K为小于100的正整数）的所有城市中编号最大的是哪座。
 * 输入
 * 第一行输入一个整数n
 * 第二行输入一个整数K
 * 之后n行，每行n个整数，描述了城市间距离的邻接矩阵，其中第i行第j个表示城市i到城市j的距离。相邻整数用空格分开
 * 输出
 * 距离不超过K的城市的最大编号
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
vector<vector<int>> G;
vector<int> d;
vector<bool> vis;

void init(int n) {
  G.clear(); G.resize(n + 1, vector<int>(n + 1, INF));
  d.clear(); d.resize(n + 1, INF);
  vis.clear(); vis.resize(n + 1, false);
}
void dijkstra(int n) {
  d[1] = 0;
  for (int i = 1; i <= n; i++) {
    int u = -1, mx = INF;
    for (int j = 1; j <= n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
      if (vis[v] == false && G[u][v] != INF && G[u][v] + d[u] < d[v]) {
        d[v] = d[u] + G[u][v];
      }
    }
  }
}
int main() {
  int n, k, mx = 1;
  cin >> n >> k;
  init(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> G[i][j];
  dijkstra(n);
  for (int i = 1; i <= n; i++)
    if (d[i] <= k)  mx = max(mx, i);
  cout << mx;
  return 0;
}