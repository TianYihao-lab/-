#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxp = 4500;

int vis[maxp + 5], prime[maxp + 5], len;

// 用埃氏筛筛出4500以内的素数
void getPrime()
{
	for(int i = 2; i <= maxp; i ++){
		if(!vis[i]) prime[len ++] = i;
		for(int j = 2 * i; j <= maxp; j += i) vis[j] = 1;
	}
}

// 判断x是不是完全平方数或完全立方数
bool check(ll x)
{
	ll sq = sqrtl(x);
	if(sq*sq==x || (sq+1)*(sq+1)==x || (sq-1)*(sq-1)==x){ // 避免有误差，这个误差确定不超过1
		return true;
	}
	
	ll cb = cbrtl(x);
	if(cb*cb*cb==x || (cb+1)*(cb+1)*(cb+1)==x || (cb-1)*(cb-1)*(cb-1)==x){
		return true;
	}
	
	return false;
}

void solve()
{
	ll a;
	cin >> a;
	
	// 是完全平方数或完全立方数直接yes
	if(check(a)){
		cout << "yes\n";
		return ;
	}
	
	// 下面分解质因数
	bool flag = true;
	for(int i = 0; i < len; i ++){
		int cnt = 0;
		int p = prime[i];
		while(a % p == 0){
			cnt ++;
			a /= p;
		}
		// 出现1次方，不合法
		if(cnt == 1){
			cout << "no\n";
			return ;
		}
	}
	
	// 最后再判断一遍分解完的即可
	if(check(a)) cout << "yes\n";
	else cout << "no\n";
}

signed main()
{
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
	getPrime();
	int T; cin >> T;
	while(T --) solve();
	return 0;
}

