#include<iostream>
using namespace std;
#define MAX 1000

typedef struct {
    string name;
    int sex;
    int age;    // ������ 0����Ů��,1��������
    string phone;
    string address;
}Person;        // ��ϵ�˽ṹ��

typedef struct {
    Person person[MAX];
    int num=0;
}AddressBook;   // ͨѶ¼�ṹ��

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
    cout<<"��ӭʹ��СTͨѶ¼������"<<endl;
    while (choice!=0) {
        showMenu();
        cin>>choice;
        switch (choice) {
            case 0:
                break;
            case 1:     // �����ϵ��
                addPerson(book1);
                break;
            case 2:     // ��ʾ������ϵ��
                showPerson(book1);

                cout<<"�Ƿ�Ҫ�˳�?(Y/N)",cin>>choice2;
                while (choice2!='Y'&&choice2!='N') {
                    cout<<"������������������(Y/N):",cin>>choice2;
                }

                break;
            case 3:     // ɾ����ϵ��
                deletePerson(book1);
                break;
            case 4:     // ������ϵ��
            {
                string _name;
                cout<<"������Ҫ���ҵ��û�������:",cin>>_name;
                findPerson(book1,_name);
                break;
            }
            case 5:     // �޸���ϵ��
                changePerson(book1);
                break;
            case 6:     // ���ͨѶ¼
                clear(book1);
                break;
            default:
                cout<<"������������������."<<endl;

        }
        if (choice2=='Y')
            choice=0;
    }
    cout<<"��ӭ�´�ʹ�ã�"<<endl;

    system("pause");
    return 0;
}

void showMenu() {
    cout<<"********************************"<<endl;
    cout<<"********   1.�����ϵ��   ********"<<endl;
    cout<<"********   2.��ʾ��ϵ��   ********"<<endl;
    cout<<"********   3.ɾ����ϵ��   ********"<<endl;
    cout<<"********   4.������ϵ��   ********"<<endl;
    cout<<"********   5.�޸���ϵ��   ********"<<endl;
    cout<<"********   6.�����ϵ��   ********"<<endl;
    cout<<"********   0.�˳�ͨѶ¼   ********"<<endl;
    cout<<"********************************"<<endl;
    cout<<"��������Ҫ�����ҵ��";
}

void addPerson(AddressBook &book) {
    string name, phone, address;
    int sex,age;

    if (book.num==MAX) {
        cout<<"ͨѶ¼�Ѿ����˲���������µ��û���";
        return;
    }

    cout<<"��������Ҫ�������ϵ������:",cin>>name;
    cout<<"������ta���Ա�0-Ů�ԣ�1-����:";
    while (cin >> sex && (sex < 0 || sex > 1)) {
        cout << "����������������루0-Ů�ԣ�1-���ԣ�:";
        cin.clear(); // �������״̬
        cin.ignore(1024, '\n'); // ��ջ�����
    }
    cout<<"������",sex%2==0?cout<<"��":cout<<"��",cout<<"������:",cin>>age;
    cout<<"������",sex%2==0?cout<<"��":cout<<"��",cout<<"�ĵ绰����:",cin>>phone;
    cout<<"������",sex%2==0?cout<<"��":cout<<"��",cout<<"�ļ�ͥסַ:",cin>>address;

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
    cout<<"��������Ҫɾ�����û�����:",cin>>name;

    int cnt=0;
    while (book.person[cnt].name!=name&&cnt<book.num) {
        cnt++;
    }
    if (cnt==book.num) {
        cout<<"ͨѶ¼��û��"<<name<<"�����"<<endl;
        return;
    }

    // �ҵ�Ҫɾ�������ˣ�ִ��ɾ���Ĳ���
    book.person[cnt].name=book.person[book.num-1].name;
    book.person[cnt].sex=book.person[book.num-1].sex;
    book.person[cnt].age=book.person[book.num-1].age;
    book.person[cnt].phone=book.person[book.num-1].phone;
    book.person[cnt].address=book.person[book.num-1].address;
    book.num--;
    cout<<"ɾ���ɹ���"<<endl;
}
void showPerson(AddressBook book) {
    for (int i = 0; i < book.num; i++) {
        cout<<book.person[i].name<<"\t";
        book.person[i].sex%2==0?cout<<"Ů":cout<<"��",cout<<"\t";
        cout<<book.person[i].age<<"\t"\
            <<book.person[i].phone<<"\t"\
            <<book.person[i].address<<endl;
    }
}

void findPerson(AddressBook _book,string _name) {
    bool flag = false;
    for (int i = 0; i < _book.num; i++) {

        if (_book.person[i].name==_name) {      // �ҵ�Ŀ�꣬���ta����Ϣ
            flag=true;
            cout<<_book.person[i].name<<"\t";
            _book.person[i].sex%2==0?cout<<"Ů":cout<<"��",cout<<"\t";
            cout<<_book.person[i].age<<"\t"\
                <<_book.person[i].phone<<"\t"\
                <<_book.person[i].address<<endl;
        }

    }
    if (!flag)cout<<"û���ҵ�"<<_name<<"�����"<<endl;
}

void changePerson(AddressBook &book) {
    string name;
    cout<<"������Ҫ�޸ĵ���ϵ�˵�����:",cin>>name;

    int cnt=0;
    while (book.person[cnt].name!=name&&cnt<book.num) {
        cnt++;
    }
    if (cnt==book.num)
        cout<<"�Ҳ���Ҫ�޸ĵ���ϵ��"<<endl;

    if (book.person[cnt].name==name) {              // �ҵ�Ҫ�޸ĵ���
        cout<<book.person[cnt].name<<"\t";
        book.person[cnt].sex%2==0?cout<<"Ů":cout<<"��",cout<<"\t";
        cout<<book.person[cnt].age<<"\t"\
            <<book.person[cnt].phone<<"\t"\
            <<book.person[cnt].address<<endl;
    }

    cout<<"�������޸ĺ������:",cin>>book.person[cnt].name;
    cout<<"�������޸ĺ���Ա�:",cin>>book.person[cnt].sex;
    cout<<"�������޸ĺ������:",cin>>book.person[cnt].age;
    cout<<"�������޸ĺ����ϵ��ʽ:",cin>>book.person[cnt].phone;
    cout<<"�������޸ĺ�ļ�ͥסַ:",cin>>book.person[cnt].address;
    cout<<"�޸ĳɹ�"<<endl;
}

void clear(AddressBook &book) {
    book.num=0;
}