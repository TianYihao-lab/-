#include<iostream>
#include<cmath>
using namespace std;

void func1(int _num) {
	bool flag = true;
	if (_num % 2) {
		for (int i = 3; i <= int(sqrt(_num)); i += 2) {
			if (_num % i == 0) {
				flag = false;
//				cout << i << " " << _num / i << endl;
			}
		}
	} else {
		flag = false;
//		cout << _num << "是一个偶数" << endl;
	}
	if (flag)
		cout << _num << "是一个素数" << endl;
	else
		cout << _num << "不是一个素数" << endl;
}

void func2(int _num) {

}


int main() {
	cout << "请输入一个数字：";
	int num = 0;
	cin >> num;
	func1(num);
	return 0;
}
