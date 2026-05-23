#include<iostream>
using namespace std;

class Cube
{
    int length=0, width=0, height=0;
    
public:
    //int _S = 2 * (length * width + length * height + width * height), _V = width * length * height;
     int _S = 0, _V = 0;

    void cLength()
    {
        cout << "请输入立方体的长：";
        cin >> length;
    }

    void cWidth()
    {
        cout << "请输入立方体的宽：";
        cin >> width;
    }

    void cWeight()
    {
        cout << "请输入立方体的高：";
        cin >> height;
    }

    void printLength()
    {
        cout << "立方体的长为：" << length << endl;
    }

    void printWeight()
    {
        cout << "立方体的宽为：" << width << endl;
    }

    void printHeight()
    {
        cout << "立方体的高为：" << height << endl;
    }

    void printS(int flag=0)
    {
         _S=2 * (length * width + length * height + width * height) ;
         if(flag==0)
            cout << "立方体的面积是：" << _S << endl;
    }

    void printV(int flag=0)
    {
        _V = width * length * height;
        if (flag==0)
            cout << "立方体的体积是：" << _V << endl;
    }
};

void Create(Cube &T)
{
    T.cLength();
    T.cWeight();
    T.cWidth();
}

void Show(Cube &T)
{
    T.printLength();
    T.printWeight();
    T.printHeight();
}
int main()
{
    Cube tem1;
    Create(tem1);
    Show(tem1);

    tem1.printS(1);
    tem1.printV(1);
    //Show(tem1);
    cout << "立方体的面积是：" << tem1._S << endl;
    cout << "立方体的体积是：" << tem1._V << endl;
    return 0;
}