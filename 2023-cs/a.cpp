#include <bits/stdc++.h>
using namespace std;

// 算法笔记进制转换部分
int utils(int a) {
	int sum = 0;
	do {
		sum += a % 10;
		a /= 10;
	} while (a);
	return sum;
}

int main() {
	int a;
	cin >> a;
	while (++a)
		if (utils(a) == 20)
			break;
	cout << a;
	return 0;
}
/**
 *年号中的每个数之和为20的年号是特殊年号。例如：2099、1991、1892是特殊的年号，而2021则不是。
  给定一个年号，找出严格大于给定年号的最小特殊年号。
	输入 => 年号：整数y(1000≤y≤9000)。
	输出 => 特殊年号：严格意义上大于y的最小年号，并且它的每个数之和为20。
*/
