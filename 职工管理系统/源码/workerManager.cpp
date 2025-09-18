#include "workerManager.h"
#include"employee.h"
#include"employer.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
    // cout << "WorkManager 构造函数调用" << endl;

    // 1. 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);    // 以读的方式打开文件

    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true; // 文件不存在，标志为真
        ifs.close();
        return;
    }
    // 2. 文件存在，但是没有数据
    char ch;
    ifs >> ch;  // 读取一个字符
    if(ifs.eof()){   // eof函数是用来判断文件指针指向的位置是否是空
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true; // 文件为空，标志为真
        ifs.close();
        return;
    }

    // 3. 文件存在，且有数据
    int num = this->getEmpNum();
    cout << "职工人数为：" << num << endl;
    this->m_EmpNum= num;
    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->m_FileIsEmpty = false; // 文件不为空，标志为假
    // 将文件中的数据读到数组中
    this->initEmp();
    ifs.close();
}

// 统计文件中的人数
int WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
}

// 初始化员工
void WorkerManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 读文件，接受数据
    int id;
    string name;
    int did;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if (did == 1) // 根据所属部门创建不同对象
        {
            worker = new Employee(id, name, 1);
        }
        else if (did == 2)
        {
            worker = new Employer(id, name, 2);
        }
        else if (did == 3)
        {
            worker = new Boss(id, name, 3);
        }
        // 存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
}

WorkerManager::~WorkerManager()
{
    // cout << "WorkManager 析构函数调用" << endl;
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::showMenu()
{
    cout << "**************************************" << endl;
    cout << "******** 欢迎使用职工管理系统 *********" << endl;
    cout << "********** 0.退出管理程序    **********" << endl;
    cout << "********** 1.增加职工信息    **********" << endl;
    cout << "********** 2.显示职工信息    **********" << endl;
    cout << "********** 3.删除离职职工    **********" << endl;
    cout << "********** 4.修改职工信息    **********" << endl;
    cout << "********** 5.查找职工信息    **********" << endl;
    cout << "********** 6.按照编号排序    **********" << endl;
    cout << "********** 7.清空所有文档    **********" << endl;
    cout << "**************************************" << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);    // 相当于 return 0;
}

void WorkerManager::addWorker()
{
    int num=0;
    cout << "请输入添加职工的数量：" << endl;
    cin >> num;
    if(num>0){
        // 首先要计算新空间的大小
        int newSize = this->m_EmpNum + num;

        // 开辟新空间
        Worker ** newSpace = new Worker *[newSize];     // 这里是一个二维指针。

        // 将原来空间下的数据拷贝到新空间中
        if(this->m_EmpArray != NULL){
            for(int i=0; i<this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // 批量添加新数据
        for(int i=0; i<num; i++){
            int id;         // 编号
            string name;    // 姓名
            int dSelect;    // 部门选择

            cout << "请输入第 " << i+1 << " 个新职工的编号：" << endl;
            cin >> id;

            cout << "请输入第 " << i+1 << " 个新职工的姓名：" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;

            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Employer(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            // 将创建的职工对象，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete [] this->m_EmpArray;
        // 更改新空间的指向
        this->m_EmpArray = newSpace;
        // 更新新的职工人数
        this->m_EmpNum = newSize;
        // 提示添加成功
        cout << "成功添加 " << num << " 名新职工" << endl;
        
        // 保存数据到文件中
        this->save();

    }else{
        cout << "输入有误" << endl;
    };
    // 按任意键清屏，后再继续操作
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    // 1.打开文件
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 文件不存在会自动创建，存在会覆盖

    // 2.写入数据
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    // 3.关闭文件
    ofs.close();
}

void WorkerManager::showWorker()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // 利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls"); 
}

void WorkerManager::deleteWorker()
{
    if(this->m_FileIsEmpty){
        cout << "文件不存在！\n";
        return;
    }
    cout << "请输入你要删除的员工的编号：\n";
    int tempid;
    cin >> tempid;
    int ret = isExist(tempid);
    if (ret != -1)  // 找到该员工
    {
        // cout << "在数组中的位置：" << ret << " ta的编号：" << m_EmpArray[ret]->m_Name<<endl;
        for (int i = ret; i < this->m_EmpNum - 1; i++)
        {
            this->m_EmpArray[i]->m_Name = this->m_EmpArray[i+1]->m_Name;
            this->m_EmpArray[i]->m_Id = this->m_EmpArray[i+1]->m_Id;
            this->m_EmpArray[i]->m_DeptId = this->m_EmpArray[i+1]->m_DeptId;
        }
        this->m_EmpNum--;
        this->save(); // 把新的信息存入文件
        cout << "删除成功\n";
    }
    else
    {
        cout << "要删除的员工不存在！\n";
        return;
    }
    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id)
{
    int index = -1;
    for(int i=0; i<this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;   // 返回的是对应编号的员工在数组中的下标。
}

void WorkerManager::changeWorker()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在！\n";
        return;
    }
    cout << "请输入需要修改的员工的编号：\n";
    int tempid;
    cin >> tempid;
    int ret = isExist(tempid);
    if(ret!=-1){
        cout << "找到该员工\n";
        int newId = 0;
        string newName = "";
        int dSelect = 0;
        cout << "请输入第" << tempid << "号员工的新信息：";
        cout << "请输入新的职工号：", cin >> newId;
        cout << "请输入新的名字：", cin >> newName;
        cout << "请输入新的职位编号：", cin >> dSelect;

        this->m_EmpArray[ret]->m_DeptId = dSelect;
        this->m_EmpArray[ret]->m_Id = newId;
        this->m_EmpArray[ret]->m_Name = newName;

        this->save();   // 把新的信息存入文件
        cout << "用户修改成功了";

    }else{
        cout << "该员工不存在！\n";
        return;
    }
    system("pause");
    system("cls");
}

void WorkerManager::findWorker(){
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在！\n";
        return;
    }
    cout << "请选择查询方式：\n";
    cout << "1.按职工编号查询" << endl;
    cout << "2.按职工姓名查询" << endl;
    cout << "请输入你的选择：";
    int select = 0; 
    cin >> select;
    if(select == 1){    // 按编号查询
        int id;
        cout << "请输入要查询的职工编号：";
        cin >> id;
        int ret = isExist(id);
        if(ret != -1){
            cout << "查找成功，职工信息如下：" << endl;
            this->m_EmpArray[ret]->showInfo();
        }else{
            cout << "查无此人！\n" << endl;
        }
    }else if(select == 2){  // 按姓名查询
        string name;
        cout << "请输入要查询的职工姓名：";
        cin >> name;
        bool flag = false; // 标志是否找到
        int _flag = false; // 保证不会重复输出找到的提示语
        for(int i=0; i<this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_Name == name){
                if(!_flag){
                    cout << "查找成功，职工信息如下：" << endl;
                    _flag = true, flag = true;
                }
                this->m_EmpArray[i]->showInfo(); 
            }
        }
        if(!flag){
            cout << "查无此人！\n" << endl;
        }
    }else{
        cout << "输入选项有误!";
    }
    system("pause");
    system("cls");
}

void WorkerManager::sortWorker(){
    if (m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式:" << endl;
        cout << "1、按职工号升序" << endl;
        cout << "2、按职工号降序:" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum- 1; i++)
        {
            int minOrmax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1) // 升序
                {
                    if (this->m_EmpArray[minOrmax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
                else // 降序
                {
                    if (this->m_EmpArray[minOrmax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
            }
            if (i != minOrmax)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrmax];
                m_EmpArray[minOrmax] = temp;
            }
        }
        cout << "排序成功，排序后的结果为：" << endl;
        this->save();
        this->showWorker();
    }
}

void WorkerManager::clearWorker(){
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在！\n";
        return;
    }

    cout << "取人清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;
    int select;
    cin >> select;
    if(select==1){
        // 以截断模式打开文件，文件名为test.txt
        ofstream outFile("empFile.txt", ios::trunc);
        if (outFile.is_open())
        {
            // 文件打开成功，已经清空原有内容，这里可以选择关闭文件，也可以继续写入新内容
            if (this->m_EmpArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArray[i] != NULL)
                    {
                        delete this->m_EmpArray[i];
                    }
                }
                this->m_EmpNum = 0;
                delete[] this->m_EmpArray;
                this->m_EmpArray = NULL;
                this->m_FileIsEmpty = true;
            }
            outFile.close();
            cout << "文件已清空。" << endl;
        }
        else
        {
            cerr << "无法打开文件。" << endl;
        }
    }
}