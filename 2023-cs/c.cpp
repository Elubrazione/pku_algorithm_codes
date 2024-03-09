#include <bits/stdc++.h>
using namespace std;

// 递归回溯，需要继续加强
void generateParenthesis(int lcnt, int rcnt, string res, vector<string> &ans) {
  if (lcnt == 0 && rcnt == 0) {
    ans.push_back(res);
    return;
  }
  // 两个if的判断顺序必须是这样，因为题目要求按照字典序输出，左括号的字典序比较小，所以优先添加左括号
  // 如果还有剩余可添加的左括号，则可以继续添加左括号
  if (lcnt > 0) generateParenthesis(lcnt - 1, rcnt, res + "(", ans);
  // 如果剩余的右括号数量比左括号多，则可以添加一个右括号
  if (rcnt > lcnt) generateParenthesis(lcnt, rcnt - 1, res + ")", ans);
}

int main() {
  int n;
  cin >> n;
  vector<string> ans;
  generateParenthesis(n, n, "", ans);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1)  cout << endl;
  }
  return 0;
}

/**
 * 描述
  Paul是一名数学专业的同学，在课余选修了C++编程课，
  现在他能够自己写程序判断判断一个给定的由'('和')'组成的字符串是否是正确匹配的。
  可是他不满足于此，想反其道而行之，设计一个程序，能够生成所有合法的括号组合，请你帮助他解决这个问题。
  输入只有一行N，代表生成括号的对数（1 ≤ N ≤ 10)。
  输出所有可能的并且有效的括号组合，按照字典序进行排列，每个组合占一行。
*/