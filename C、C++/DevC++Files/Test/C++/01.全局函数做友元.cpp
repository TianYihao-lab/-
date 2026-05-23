#include<iostream>
using namespace std;

class Buliding{
    friend void visit2();

public:
    string house;
    Buliding() : house("房子"), bedroom("卧室") {};

private:
    string bedroom;
};

void visit(){
    Buliding b;
    cout << "访问" << b.house << endl;
    // cout << "访问" << b.bedroom << endl;     // err
}
void visit2(){
    Buliding b;
    cout << "访问" << b.house << endl;
    cout << "访问" << b.bedroom << endl;     
}

int main(){
    visit();
    puts("");
    visit2();
    system("pause");
    return 0;
}