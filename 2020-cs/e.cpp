/**
 * 有N（不大于10）座城市，编号为1至N，已知任意两个城市间距离（不超过1000的非负整数）。
 * 求从城市1至城市N的最短路。
 *
 * 输入
 * 第一行输入N
 * 之后N行，每行N个整数，描述了城市间距离的邻接矩阵，其中第i行第j个表示城市i到城市j的距离。相邻整数用空格分开
 *
 * 输出
 * 第一行输出最短路径长度
 * 第二行输出经过的城市编号，用空格隔开
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
vector<vector<int>> G, pre;
vector<int> d, tempPath, path;
vector<bool> vis;

void init(int n) {
  G.clear(); G.resize(n + 1, vector<int>(n + 1, INF));
  pre.clear(); pre.resize(n + 1);
  d.clear(); d.resize(n + 1, INF);
  vis.clear(); vis.resize(n + 1, false);
}

void dijkstra(int n) {
  d[1] = 0;
  for (int i = 1; i <= n; i++) {
    int u = -1, mx = INF;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
      if (!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
        d[v] = d[u] + G[u][v];
        pre[v].clear();
        pre[v].push_back(u);  // v的前驱节点u
      }
    }
  }
}

int ans = INT_MAX;
void dfs(int v) {
  if (v == 1) { // 回溯到起始节点
    tempPath.push_back(v);
    int cur = 0;
    for (int i = tempPath.size() - 1; i > 0; i--) {
      int id = tempPath[i], nxt = tempPath[i-1];
      cur += G[id][nxt];
    }
    if (cur < ans) {
      ans = cur;
      path = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (auto a: pre[v])  dfs(a);
  tempPath.pop_back();
}
int main() {
  int n;
  cin >> n;
  init(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> G[i][j];
  dijkstra(n);
  dfs(n);
  cout << ans << endl;
  for (int i = path.size() - 1; i >= 0; i--) {
    if (i)  printf("%d ", path[i]);
    else  printf("%d", path[i]);
  }
  return 0;
}