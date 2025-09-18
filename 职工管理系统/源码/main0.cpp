#include <iostream>
using namespace std;

#include "workerManager.cpp"
#include "employee.cpp"
#include "employer.cpp"
#include "boss.cpp"
#include "worker.h"

// test01();

int main()
{
    //test01();
    WorkerManager wm;
    int choice = 0;
    while(true){
        wm.showMenu();
        cout << "����������ѡ��??" ;
        cin >> choice;
        switch (choice)
        {
        case 0: // �˳�ϵͳ
            wm.exitSystem();
            break;
        case 1: // ����ְ��
            wm.addWorker();
            break;
        case 2: // ��ʾְ��
            wm.showWorker();
            break;
        case 3: // ɾ��ְ��
            // {
            //     int tempid = 0;
            //     cout << "��������Ҫɾ����ְ���������е�����ǣ�" ;
            //     cin >> tempid;
            //     cout << wm.isExist(tempid) << endl;
            //     break;
            // }
            wm.deleteWorker();
            break;
        case 4: // �޸�ְ��
            wm.changeWorker();
            break;
        case 5: // ����ְ��
            wm.findWorker();
            break;
        case 6: // ְ������
            wm.sortWorker();
            break;
        case 7: // �������ְ��
            wm.clearWorker();
            break;
        default:
            system("cls"); // ����
            cout << "������������������" << endl;
        }
    }
    system("pause");
    return 0;
}

// void test01()
// {
//     Worker *worker = new Boss(1, "����", 1);
//     worker->showInfo();
//     // delete worker;
// }