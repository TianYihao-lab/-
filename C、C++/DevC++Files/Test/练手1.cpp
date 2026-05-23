#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Person{
    public:
        string name;
        double score;
};
//vector<vector<int>> v;
vector<int> v1, v2, v3, v4, v5;
int cnt=1;

void printV(const vector<int> _vector){
    for (vector<int>::const_iterator it = _vector.begin(); it != _vector.end();it++){
        cout << *it << " ";
    }
    puts("");
}

int Sum(vector<int>::iterator left, vector<int>::iterator right)
{
    int _sum=0;
    while(left!=right){
        _sum += *left;
        left++;
    }
    return _sum;
}

void judge(vector<int>& _vector){
    int num;
    printf("\n 现在给第%d位选手打分:\n",cnt);
    for (int i=1;i<=4;i++){
        cout << "请第"<<i<<"位裁判给出选手成绩:";
        cin>>num;
        _vector.push_back(num);
    }
    //printV(_vector);
    sort(_vector.begin(), _vector.end());
    //printV(_vector);
    //cout << Sum(_vector.begin() + 1, _vector.end() - 1);
    cout << "第" << cnt++ << "位选手的平均分是:" << 1.0*Sum(_vector.begin() + 1, _vector.end() - 1) / 2;
}
int main(){
    cout<<"欢迎来到评审环节！"<<endl;
    judge(v1);
    judge(v2);
    judge(v3);
    judge(v4);
    judge(v5);
    return 0;
}