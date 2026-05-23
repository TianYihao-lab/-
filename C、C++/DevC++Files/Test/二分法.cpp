#include<iostream>
using namespace std;

const int N = 1e6+10;
int n, q, arr[N];

int bsearch1(int *arr, int l, int r, int n) {
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (arr[mid] <= n)l = mid;
		else r = mid - 1;
	}
	if (arr[l] == n)return l;
	else return -1;
}

int bsearch2(int *arr, int l, int r, int n) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (arr[mid] >= n)r = mid;
		else l = mid + 1;
	}
	if (arr[l] == n)return l;
	else return -1;
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (q--) {
		int k;
		cin >> k;
		cout  << bsearch2(arr, 0, n - 1, k) << " " << bsearch1(arr, 0, n - 1, k) << endl;
	}
	return 0;

}
