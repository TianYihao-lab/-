#include<iostream>
using namespace std;

void Treenum(){  // 求n个结点最多构造多少棵形态不同的树
	int size;
	scanf("%d", &size);   //读取需要求的N
	int dp[size + 1];
	dp[0] = dp[1] = 1;   //没有结点或是只有一个结点直接得到1
	for (int i = 2; i <= size; ++i) {
		dp[i] = 0;   //一开始先等于0再说
		for (int j = 0; j < i; ++j) {   //内层循环是为了计算所有情况，比如i等于3，那么就从j = 0开始，计算dp[0]和dp[2]的结果，再计算dp[1]和dp[1]...
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	printf("%d\n", dp[size]);   //最后计算的结果就是N个结点构造的二叉树数量了
}


int factorial(int n){ // 这个函数功能是求阶乘
	int res = 1;
	for (int i = 2; i <= n; ++i) res *= i;
	return res;
}

int main(){
	Treenum();
	
	int n;
	scanf("%d", &n);
	printf("%d\n", factorial(2*n) / (factorial(n) * factorial(n + 1))); // 结果是卡特兰数的形式
	
	return 0;
}
