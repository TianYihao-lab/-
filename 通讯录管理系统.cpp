#include<iostream>
using namespace std;
#define MAX 1000

typedef struct {
    string name;
    int sex;
    int age;    // 这里用 0代表女性,1代表男性
    string phone;
    string address;
}Person;        // 联系人结构体

typedef struct {
    Person person[MAX];
    int num=0;
}AddressBook;   // 通讯录结构体

int choice=-1;
char choice2='N';
AddressBook book1;

void showMenu();
void addPerson(AddressBook &book);
void deletePerson(AddressBook &book);
void showPerson(AddressBook book);
void findPerson(AddressBook _book,string _name);
void changePerson(AddressBook &book);
void clear(AddressBook &book);

int main() {
    cout<<"欢迎使用小T通讯录！！！"<<endl;
    while (choice!=0) {
        showMenu();
        cin>>choice;
        switch (choice) {
            case 0:
                break;
            case 1:     // 添加联系人
                addPerson(book1);
                break;
            case 2:     // 显示已有联系人
                showPerson(book1);

                cout<<"是否要退出?(Y/N)",cin>>choice2;
                while (choice2!='Y'&&choice2!='N') {
                    cout<<"输入有误，请重新输入(Y/N):",cin>>choice2;
                }

                break;
            case 3:     // 删除联系人
                deletePerson(book1);
                break;
            case 4:     // 查找联系人
            {
                string _name;
                cout<<"请输入要查找的用户的名称:",cin>>_name;
                findPerson(book1,_name);
                break;
            }
            case 5:     // 修改联系人
                changePerson(book1);
                break;
            case 6:     // 清空通讯录
                clear(book1);
                break;
            default:
                cout<<"输入有误请重新输入."<<endl;

        }
        if (choice2=='Y')
            choice=0;
    }
    cout<<"欢迎下次使用！"<<endl;

    system("pause");
    return 0;
}

void showMenu() {
    cout<<"********************************"<<endl;
    cout<<"********   1.添加联系人   ********"<<endl;
    cout<<"********   2.显示联系人   ********"<<endl;
    cout<<"********   3.删除联系人   ********"<<endl;
    cout<<"********   4.查找联系人   ********"<<endl;
    cout<<"********   5.修改联系人   ********"<<endl;
    cout<<"********   6.清空联系人   ********"<<endl;
    cout<<"********   0.退出通讯录   ********"<<endl;
    cout<<"********************************"<<endl;
    cout<<"请输入你要办理的业务：";
}

void addPerson(AddressBook &book) {
    string name, phone, address;
    int sex,age;

    if (book.num==MAX) {
        cout<<"通讯录已经满了不能在添加新的用户。";
        return;
    }

    cout<<"请输入你要新添的联系人姓名:",cin>>name;
    cout<<"请输入ta的性别（0-女性，1-男性:";
    while (cin >> sex && (sex < 0 || sex > 1)) {
        cout << "输入错误，请重新输入（0-女性，1-男性）:";
        cin.clear(); // 清除错误状态
        cin.ignore(1024, '\n'); // 清空缓冲区
    }
    cout<<"请输入",sex%2==0?cout<<"她":cout<<"他",cout<<"的年龄:",cin>>age;
    cout<<"请输入",sex%2==0?cout<<"她":cout<<"他",cout<<"的电话号码:",cin>>phone;
    cout<<"请输入",sex%2==0?cout<<"她":cout<<"他",cout<<"的家庭住址:",cin>>address;

    book.person[book.num].name=name;
    book.person[book.num].phone=phone;
    book.person[book.num].age=age;
    book.person[book.num].address=address;
    book.person[book.num].sex=sex;
    book.num++;
    puts("");
}

void deletePerson(AddressBook &book) {
    string name;
    cout<<"请输入你要删除的用户名称:",cin>>name;

    int cnt=0;
    while (book.person[cnt].name!=name&&cnt<book.num) {
        cnt++;
    }
    if (cnt==book.num) {
        cout<<"通讯录中没有"<<name<<"这个人"<<endl;
        return;
    }

    // 找到要删除的人了，执行删除的操作
    book.person[cnt].name=book.person[book.num-1].name;
    book.person[cnt].sex=book.person[book.num-1].sex;
    book.person[cnt].age=book.person[book.num-1].age;
    book.person[cnt].phone=book.person[book.num-1].phone;
    book.person[cnt].address=book.person[book.num-1].address;
    book.num--;
    cout<<"删除成功。"<<endl;
}
void showPerson(AddressBook book) {
    for (int i = 0; i < book.num; i++) {
        cout<<book.person[i].name<<"\t";
        book.person[i].sex%2==0?cout<<"女":cout<<"男",cout<<"\t";
        cout<<book.person[i].age<<"\t"\
            <<book.person[i].phone<<"\t"\
            <<book.person[i].address<<endl;
    }
}

void findPerson(AddressBook _book,string _name) {
    bool flag = false;
    for (int i = 0; i < _book.num; i++) {

        if (_book.person[i].name==_name) {      // 找到目标，输出ta的信息
            flag=true;
            cout<<_book.person[i].name<<"\t";
            _book.person[i].sex%2==0?cout<<"女":cout<<"男",cout<<"\t";
            cout<<_book.person[i].age<<"\t"\
                <<_book.person[i].phone<<"\t"\
                <<_book.person[i].address<<endl;
        }

    }
    if (!flag)cout<<"没有找到"<<_name<<"这个人"<<endl;
}

void changePerson(AddressBook &book) {
    string name;
    cout<<"请输入要修改的联系人的名字:",cin>>name;

    int cnt=0;
    while (book.person[cnt].name!=name&&cnt<book.num) {
        cnt++;
    }
    if (cnt==book.num)
        cout<<"找不到要修改的联系人"<<endl;

    if (book.person[cnt].name==name) {              // 找到要修改的人
        cout<<book.person[cnt].name<<"\t";
        book.person[cnt].sex%2==0?cout<<"女":cout<<"男",cout<<"\t";
        cout<<book.person[cnt].age<<"\t"\
            <<book.person[cnt].phone<<"\t"\
            <<book.person[cnt].address<<endl;
    }

    cout<<"请输入修改后的名称:",cin>>book.person[cnt].name;
    cout<<"请输入修改后的性别:",cin>>book.person[cnt].sex;
    cout<<"请输入修改后的年龄:",cin>>book.person[cnt].age;
    cout<<"请输入修改后的联系方式:",cin>>book.person[cnt].phone;
    cout<<"请输入修改后的家庭住址:",cin>>book.person[cnt].address;
    cout<<"修改成功"<<endl;
}

void clear(AddressBook &book) {
    book.num=0;
}