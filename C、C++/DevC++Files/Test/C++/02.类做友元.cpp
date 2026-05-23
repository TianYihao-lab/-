#include <iostream>
using namespace std;

class Buliding
{
    friend class GoodGay;

public:
    string house;
    Buliding() : house("房子"), bedroom("卧室") {};

private:
    string bedroom;
};

class GoodGay
{
public:
    Buliding b;
    void visit();
};

void GoodGay::visit()
{
    cout << "访问" << b.house << endl;
    cout << "访问" << b.bedroom << endl;
}


int main()
{
    GoodGay goodGay;
    goodGay.visit();
    system("pause");
    return 0;
}
