#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define PI 3.14
const int N=105;

int arr_1[N][N],arr_2[N][N];
int res[N][N];

void test01(){
	int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr_1[i][j];
	
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            cin>>arr_2[i][j];
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for (int l = 0; l < m; l++)
                res[i][j] += arr_1[i][l] * arr_2[l][j];
        }
    }

    for (int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	test01();
	return 0;
}
