#include<iostream>
#include<cmath>
using namespace std;

double n;
const double eps = 1e-7;	// eps表示精度，取决于题目的要求(可以选取一个精度更高的值来进行运算)

int main() {
	scanf("%lf", &n);
	double l = -1000, r = 1000;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (pow(mid, 3.0) > n)r = mid;
		else l = mid;
	}
	printf("%.6lf", l);
	return 0;
}

//#include <iostream>
//using namespace std;
//double x;
//int main () {
//	cin >> x;
//	double l = -100, r = 100;
//	while (r - l > 1e-7) {
//		double mid = (l + r) / 2;
//		if (mid * mid * mid <= x) l = mid;  //如果是小于等于的话，就可以说明答案会更大
//		else r = mid;
//	}
//	printf ("%.6lf", l);
//	return 0;
//}

