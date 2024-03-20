#include<bits/stdc++.h>
using namespace std;
/**
 * 每一组数据，可能又会有多个没有判断过，但是也可能只有一个没判断过，剩下全是真的，此时这个未判断过的就是答案。
 * 但是如果有很多未判断过的，此时必须有一个判断为必假的，否则答案不确定。
 * 如果一组数据两侧相等，那么他们全部是真的。
 * 如果一组数据两侧不相等，那么除了他们之外全部的硬币都是真的。
 * 两次判断相矛盾的硬币肯定是真的，比如有个硬币第一次判断是可能比较重，第二次又判断比较轻，如果是假的，那他在哪一侧那一侧肯定只有唯一一种表现/要么重要么轻，所以该硬币肯定是真的。
 * 如果最终结果有多个硬币是假的，说明还是没有判断成功，答案仍然不确定。
*/

int main() {
  int n, k, num, tmp, cnt = 0, pos, flag[1000], pi;
  cin >> n >> k;
  char ch;
  vector<int> left, right;
  map<int, int> m;
  for (int i = 1; i <= n; i++)  m[i] = 1;
  for (int i = 0; i < k; i++) {
    memset(flag, 0, sizeof(flag));
    cin >> pi;
    for (int j = 0; j < pi; j++)
      cin >> tmp, left.push_back(tmp);
    for (int j = 0; j < pi; j++)
      cin >> tmp, right.push_back(tmp);
    cin >> ch;
    if (ch == '=') {
      for (auto i : left) m[i] = 2;
      for (auto i : right)  m[i] = 2; //1未确定，2真币，3“疑似”过轻，4“疑似”超重
    }
    if (ch == '<') {
      for (auto i : left)
        m[i] = (m[i] != 1 && m[i] != 3) ? 2 : 3, flag[i] = 1;
      for (auto i : right)
        m[i] = (m[i] != 1 && m[i] != 4) ? 2 : 4, flag[i] = 1;
      for (int i = 1; i <= n; i++)
        if (!flag[i]) m[i] = 2;
    }
    if (ch == '>') {
      for (auto i : left)
        m[i] = (m[i] != 1 && m[i] != 4) ? 2 : 4, flag[i] = 1;
      for (auto i : right)
        m[i] = (m[i] != 1 && m[i] != 3) ? 2 : 3, flag[i] = 1;
      for (int i = 1; i <= n; i++)
        if (!flag[i]) m[i] = 2;
    }
    left.clear();
    right.clear();
  }
  for (auto iter : m)
    if (iter.second != 2)
      cnt++, pos = iter.first;
  if (cnt == 1) cout << pos << endl;
  else cout << 0 << endl;
  return 0;
}