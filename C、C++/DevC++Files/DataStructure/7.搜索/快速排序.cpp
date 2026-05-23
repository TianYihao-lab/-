#include<bits/stdc++.h>
using namespace std;
const int N = 1e8+10;

int n, arr[N];

void quick_sort(int *arr, int l, int r) {
	if (l >= r)return ;

	int x = arr[l], left = l, right = r;
	while (left < right) {
		while (arr[left] < x)left++;	// while (arr[left] <= x)left++;
		while (arr[right] > x)right--;	// while (arr[right] >= x)right--;

		if (left < right)swap(arr[left], arr[right]);
	}

	quick_sort(arr, l, right - 1);
	quick_sort(arr, left + 1, r);
}

void quick_sort2(int *arr, int l, int r) {
	if (l >= r) return;
	int x = arr[l], i = l - 1, j = r + 1;
	while (i < j) {
		do i ++ ;
		while (arr[i] < x);
		do j -- ;
		while (arr[j] > x);
		if (i < j) swap(arr[i], arr[j]);
	}
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
