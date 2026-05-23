#include<iostream>
using namespace std;
class cal
{
public:
    int x, y;
    cal():x(0),y(0){};
    cal(int _x, int _y) : x(_x), y(_y) {};
    ~cal() {};

    cal operator+(const cal& c){        // 利用全局函数实现重载
        this->x += c.x;
        this->y += c.y;
        return *this;
    }

};
cal operator+(const cal& c1,const cal&c2){
    cal tempc;
    tempc.x = c1.x + c2.x;
    tempc.y = c1.y + c2.y;
    return tempc;
}

void test01(){
    cal c1(1, 2);
    cal c2(2, 3);
    c1.operator+(c2);       // 等价于 c1 = c1 + c2;

    // c1 += c2;    // err,没有重载'+='运算符
    cout << c1.x << " " << c1.y << endl;
}

void test02()
{
    cal c1(1, 2);
    cal c2(2, 3);
    c1 = operator+(c1,c2);   // 等价于 c1 = c1 + c2;
    cout << c1.x << " " << c1.y << endl;
}
int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}