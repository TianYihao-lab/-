#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e9+10;

int n, num;
bool arr[N];

bool is_prime(int _num) {
	if (_num % 2 == 0)return false;
	for (int i = 3; i < _num / i; i++) {
		if (_num % i == 0)return false;
	}
	arr[_num] = true;
	return true;
}
void func(int _num) {
	int cnt = 0;
	while (_num % 2 == 0) {
		cnt++, _num /= 2;
	}
	if (cnt != 0)cout << 2 << " " << cnt << endl;

	for (int i = 3; i <= _num / i; i += 2) {
		if (arr[i] || is_prime(i)) {
			int temp = 0;
			while (_num % i == 0) {
				temp++, _num /= i;
			}
			if (temp != 0)cout << i << " " << temp << endl;
		}
	}

	if (_num != 1)cout << _num << " " << 1 << endl;

	puts("");
}

int main() {
	cin >> n;
	while (n--) {
		cin >> num;
		func(num);
	}
	return 0;
}
