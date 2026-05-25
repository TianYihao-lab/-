#include <iostream>
using namespace std;

// 前向声明 Buliding（因为 GoodGay 中需要用到）
class Buliding;

// 先定义 GoodGay 类（声明成员函数 visit01）
class GoodGay
{
public:
    Buliding *b;    // 用指针避免 "不完整类型" 错误（此时 Buliding 仅前向声明）
    void visit01(); // 声明友元函数
    void visit02();
};

// 再定义 Buliding 类（此时已知 GoodGay::visit01 存在）
class Buliding
{
    // 声明 GoodGay::visit01 为友元（此时编译器已知道该函数存在）
    friend void GoodGay::visit01();

public:
    string house;
    Buliding() : house("房子"), bedroom("卧室") {};

private:
    string bedroom; // 私有成员
};

// 实现 GoodGay 的成员函数（此时 Buliding 已完整定义）
void GoodGay::visit01()
{
    cout << "visit01 访问" << b->house << endl;
    // 友元函数可访问私有成员 bedroom
    cout << "visit01 访问" << b->bedroom << endl;
}

void GoodGay::visit02()
{
    cout << "visit02 访问" << b->house << endl;
    // visit02 不是友元，无法访问私有成员（取消注释会报错）
    // cout << "visit02 访问" << b->bedroom << endl;
}

int main()
{
    GoodGay goodGay;
    goodGay.b = new Buliding(); // 动态创建 Buliding 对象
    goodGay.visit01();
    puts("");
    goodGay.visit02();

    delete goodGay.b; // 释放内存
    system("pause");
    return 0;
}
