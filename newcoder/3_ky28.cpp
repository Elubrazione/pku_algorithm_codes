#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v, c;
  Node(int _v, int _c): v(_v), c(_c) {}
};
const int INF = 0X3fffffff;
vector<int> d, camp;
vector<bool> vis;
vector<vector<Node>> Adj;

void init(int n) {
  camp.clear(); camp.resize(n + 1, 0);
  d.clear(); d.resize(n + 1, INF);
  vis.clear(); vis.resize(n + 1, false);
  Adj.clear(); Adj.resize(n + 1);
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
    for (auto p: Adj[u]) {
      // 分为两个阵营，只能左边到右边限制单向就绝对只包含一条
      if (!(camp[u] == 2 && camp[p.v] == 1)) {
        if (!vis[p.v] && d[u] + p.c < d[p.v]) {
          d[p.v] = p.c + d[u];
        }
      }
    }
  }
  return;
}
int main() {
  int n, m;
  while (cin >> n) {
    if (!n) break;
    init(n);
    cin >> m;
    int a, b, t;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> t;
      Adj[a].push_back(Node(b, t));
      Adj[b].push_back(Node(a, t));
    }
    for (int i = 1; i <= n; i++)  cin >> camp[i];
    dijkstra(n);
    if (d[2] == INF)  cout << -1 << endl;
    else  cout << d[2] << endl;
  }
  return 0;
}