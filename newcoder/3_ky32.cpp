#include <bits/stdc++.h>
using namespace std;

struct Log {
  double time;
  string date, whole;
  Log(string _n, double _t, string _dat): whole(_n), time(_t), date(_dat) {}
};
vector<Log> vec;

int main() {
  string str;
  char n[15], s1[15], s2[15];
  double t;
  while (getline(cin, str)) {
    sscanf(str.c_str(), "%s%s%s%lf(s)", n, s1, s2, &t);
    vec.emplace_back(Log(str, t, string(s1) + string(s2)));
  }
  sort(vec.begin(), vec.end(), [&](Log a, Log b) {
    if (a.time != b.time) return a.time < b.time;
    else  return a.date < b.date;
  });
  for (auto it: vec)  printf("%s\n", it.whole.c_str());
}