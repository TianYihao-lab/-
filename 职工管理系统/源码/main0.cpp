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
        cout << "请输入您的选择??" ;
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            wm.exitSystem();
            break;
        case 1: // 增加职工
            wm.addWorker();
            break;
        case 2: // 显示职工
            wm.showWorker();
            break;
        case 3: // 删除职工
            // {
            //     int tempid = 0;
            //     cout << "请输入想要删除的职工在数组中的序号是：" ;
            //     cin >> tempid;
            //     cout << wm.isExist(tempid) << endl;
            //     break;
            // }
            wm.deleteWorker();
            break;
        case 4: // 修改职工
            wm.changeWorker();
            break;
        case 5: // 查找职工
            wm.findWorker();
            break;
        case 6: // 职工排序
            wm.sortWorker();
            break;
        case 7: // 清空所有职工
            wm.clearWorker();
            break;
        default:
            system("cls"); // 清屏
            cout << "输入有误，请重新输入" << endl;
        }
    }
    system("pause");
    return 0;
}

// void test01()
// {
//     Worker *worker = new Boss(1, "张三", 1);
//     worker->showInfo();
//     // delete worker;
// }