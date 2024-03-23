#include <bits/stdc++.h>
using namespace std;

struct Ant {
  int pos, v;
} a[100];
bool cmp(Ant p1, Ant p2) {
  return p1.pos < p2.pos;
}

int main() {
  int n, s;
  while (cin >> n) {
    vector<Ant> vl, vr;
    for (int i = 0; i < n; i++) {
      cin >> a[i].pos >> a[i].v;
      if (a[i].v == 0)  s = i;
    }
    for (int i = 0; i < n; i++) {
      if (a[i].pos < a[s].pos && a[i].v > 0)
        vl.push_back(a[i]);
      else if (a[i].pos > a[s].pos && a[i].v < 0)
        vr.push_back(a[i]);
    }
    int l1 = vl.size(), l2 = vr.size();
    sort(vl.begin(), vl.end(), cmp);
    sort(vr.begin(), vr.end(), cmp);

    if (l1 == l2) {
      printf("Cannot fall!\n");
    } else if (l1 > l2) {
      cout << 100 - vl[l1 - l2 - 1].pos << endl;
    } else {
      cout << vr[l1].pos << endl;
    }
  }
}