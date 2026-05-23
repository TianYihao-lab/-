#include <iostream>
using namespace std;
class cal
{
public:
    int x, y;
    cal() : x(0), y(0) {};
    cal(int _x, int _y) : x(_x), y(_y) {};
    ~cal() {};

    // 重载++运算符     --前置++
    cal &operator++()
    {
        this->x++;
        this->y++;
        return *this;
    }

    // 后置++
    cal operator++(int)
    {
        cal temp = *this;
        this->x++, this->y++;
        return temp;
    }
};

// 重载左移运算符
ostream& operator<<(ostream& cout,const cal& c)     
{
    cout << c.x << " " << c.y << endl;
    return cout;
}

int main()
{
    cal c1(1, 2);
    cout << c1 << endl;

    cout << ++c1 << endl;

    cout << c1++;
    cout << c1 << endl;

    system("pause");
    return 0;
}