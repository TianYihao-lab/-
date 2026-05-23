#include<iostream>
#include<cmath>
using namespace std;

int n,k;
typedef struct{
    int id;
    float score;
} stu;
stu ss[100];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> ss[i].id >> ss[i].score;
    }
    printf("%d %g", ss[k].id, ss[k].score);
    return 0;
}