#include<iostream>
using namespace std;
int main() {
  unsigned int M, N;
  while (cin >> M >> N) {
    for (int i = 0; i < 16; i++) {
      if (M == N) {
        cout << "YES" << endl;
        break;
      } else if (i == 15) {
        cout << "NO" << endl;
      } else {
        M = M >> 1 | (M << 15 & 0x8000);
      }
    }
  }
}
/**
位操作练习题目总结：

法一：
循环右移：((a << (N - i)) & 0xffff) | (a >> i)
循环左移：((a << i) & 0xffff) | (a >> (N-i))

注意：
整数的位操作默认是32位的，题目中要求是16位二进制，所以左移的结果要&上低16位都为1 ，高16位都为0 的数（65535）。
循环左移可以用左移i位 &上 右移16-i位 （循环左移）
规律：必须是左移时&上0xffff


法二：
一个一个右移：M=M>>1|(M<<15&0xf000);
一个一个左移：M=M<<1|(M>>15&1);

易错点：一个一个右移时可声明为unsigned int或者unsigned short
一个一个左移时只能声明为unsigned short。若为unsigned int，则会出错。
初步猜想：是&后面的数导致的，若&1，则不确定有多少位，变为默认的32位，所以出错。但&0xf000则必是16位
*/