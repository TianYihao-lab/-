#include <iostream>
using namespace std;

class Person
{
    int age;
    string name;

public:
    Person()    // 默认构造函数
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(string _name,int _age) // 带参数的构造函数
    {
        name = _name, age = _age;
        cout << "调用了带参数的构造函数" << endl;
    }

    Person(const Person &p0){       // 拷贝构造函数
        printf("调用了拷贝构造函数\n");
        age = p0.age;
        name = p0.name;
    }

    ~Person()       // 析构函数
    {
        cout << "Person的析构函数调用" << endl;
    }
};

void test01()
{
    Person p;
}
int main()
{
     Person p;
    //test01();
     puts("");
     Person p1("tyh", 21);
     Person p3(p1);
     Person p2 = p1;


     system("pause");
     return 0;
}