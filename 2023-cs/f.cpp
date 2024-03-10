#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v, w;
  Node(int _v, int _w): v(_v), w(_w) {}
};
int n, m;
vector<bool> inq;
vector<int> d, innum;
const int MAX = 0x3fffffff;
vector<vector<Node>> G;

bool spfa(int s) {
  d.resize(n + 1), fill(d.begin(), d.end(), MAX);
  inq.resize(n + 1), fill(inq.begin(), inq.end(), false);
  innum.resize(n + 1), fill(innum.begin(), innum.end(), 0);
  queue<int> q;
  q.push(s);
  inq[s] = true;
  innum[s]++;
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (auto p: G[u]) {
      if (d[u] + p.w < d[p.v])
        d[p.v] = d[u] + p.w;
      if (!inq[p.v]) {
        q.push(p.v);
        inq[p.v] = true;
        innum[p.v]++;
        if (innum[p.v] >= n)
          return false;
      }
    }
  }
  return true;
}

int main() {
  int s, t;
  int x, y, z;
  cin >> t;
  while (t--) {
    cin >> n >> m >> s;
    G.resize(n + 1), fill(G.begin(), G.end(), vector<Node>());
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      G[x].push_back(Node(y, z));
    }
    bool res = spfa(s);
    if (!res) cout << "Error\n";
    else {
      for (int i = 1; i <= n; i++) {
        d[i] == MAX? cout << "null": cout << d[i];
        if (i != n) cout << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

/**
 * 给定一个n个点, m条边的有向图, 求从点S出发, 到其它所有点的最短路径.
 *
 * 输入
 * 第一行一个整数T, 表示有T组数据
 * 对于每组测试数据, 第一行三个整数n, m, S, 表示有n个点, m条边, 起点为S.
 * 接下来m行, 每行三个整数x, y, z, 代表从x到y有长度为z的边点的编号从1到n
 * T <= 10, n <= 10000, m <= 20000, |z| <= 10000. 所有数据的n之和 <= 30000, 所有数据的m之和 <= 60000.
 *
 * 输出
 * 对于每组数据:
 * 如果从S点出发可以走入负圈 (即到某些点的最短路径可以无限小), 那么输出一行Error.
 * 否则, 输出一行用空格分隔的n个整数, 其中第i个整数表示从S点到i点的最短路长度. 如果从S点无法到达i点, 则第i个输出为”null”.
*/