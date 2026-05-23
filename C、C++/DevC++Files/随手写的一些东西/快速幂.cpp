#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int n, arr[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
