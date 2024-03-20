#include <bits/stdc++.h>
using namespace std;

// 出错问题：有环
// 判断条件：x == father[x]的节点只能有一个，即没有森林，只有一个连通分量
// 为了排除自己指向自己和环的情况还要计算入度为0的节点的个数是一个
// 特殊情况是入度为0的节点一个也没有，即空树，此时连通分量也应该为0
int mx, cnt;
const int MAXN = 10000;
vector<int> father(MAXN), used(MAXN), inDegree(MAXN);

void init() {
  cnt++;
  mx = 0;
  fill(used.begin(), used.end(), 0);
  fill(inDegree.begin(), inDegree.end(), 0);
  for (int i = 0; i < MAXN; i++)  father[i] = i;
}
int findFather(int x) {
  int a = x;
  while (x != father[x])  x = father[x];
  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}
void union2(int a, int b) {
  int faA = findFather(a);
  int faB = findFather(b);
  if (faA != faB)
    father[faB] = father[faA];
  return;
}
bool isTree() {
  int r = 0, c = 0;
  for (int i = 1; i <= mx; i++) {
    if (!used[i]) continue;
    if (inDegree[i] > 1)  return false;
    if (inDegree[i] == 0) c++;
    if (i == findFather(i)) r++;
  }
  if (!c && c == r) return true;
  else if (c == 1 && r == 1)  return true;
  return false;
}
int main() {
  int a, b;
  init();
  while (cin >> a >> b) {
    if (a == -1 && b == -1) break;
    if (!a && !b) {
      bool c = isTree();
      c? printf("Case %d is a tree.\n", cnt): printf("Case %d is not a tree.\n", cnt);
      init();
      continue;
    }
    used[a] = 1, used[b] = 1;
    mx = max(max(mx, a), b);
    union2(a, b);
    inDegree[b]++;
  }
}