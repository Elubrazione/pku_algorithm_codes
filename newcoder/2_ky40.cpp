#include <bits/stdc++.h>
using namespace std;

// 最小生成树的prim算法解法
// 本题目为稠密图
struct V {
  double x, y;
  V(double _x, double _y): x(_x), y(_y) {}
};
const double INF = (double)0x3fffffff;
vector<V> ver;
vector<bool> vis;
vector<double> d;
vector<vector<double>> G;

double prim(int& n) {
  d[0] = 0.0;
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    double mx = INF;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return -1;
    vis[u] = true;
    ans += d[u];
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
        d[v] = G[u][v];
      }
    }
  }
  return ans;
}
double compute(V n1, V n2) {
  double a = pow(n1.x - n2.x, 2);
  double b = pow(n1.y - n2.y, 2);
  return sqrt(a + b);
}
int main() {
  int n;
  double x, y;
  cin >> n;
  vis.resize(n, false);
  d.resize(n, INF);
  G.resize(n, vector<double>(n, INF));
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ver.push_back(V(x, y));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      G[i][j] = compute(ver[i], ver[j]);
      G[j][i] = G[i][j];
    }
  }
  double ans = prim(n);
  printf("%.2f", ans);
  return 0;
}