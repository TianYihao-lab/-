#include<iostream>
#include<vector>
using namespace std;

void test05()
{
    string str = "hello";

    // ≤Â»Î
    str.insert(1, "***");
    cout << str << endl;

    // …æ≥˝
    str.erase(1, 2);
    cout << str << endl;
}

int main(){
    test05();
    return 0;
}