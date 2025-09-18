#pragma once // 用来防止头文件被重复包含
#include <iostream>
using namespace std;
#include"worker.h"
#include<fstream>

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    int m_EmpNum;        // 记录职工人数
    Worker **m_EmpArray; // 职工数组指针
    bool m_FileIsEmpty;  // 文件标志，判断文件是否存在

    // 构造函数
    WorkerManager();
    int getEmpNum();    // 统计文件中的人数
    void initEmp();     // 初始化员工(将文件中的元素全都取出来放在 m_EmpArray中)

    // 展示函数
    void showMenu();

    // 退出职工管理系统
    void exitSystem();

    // 增加职工信息
    void addWorker();
    void save();        // 将员工信息存入文本
    
    // 显示职工信息
    void showWorker();

    // 删除离职职工
    void deleteWorker();
    int isExist(int id);    // 判断员工是否存在

    // 修改职工信息
    void changeWorker();

    // 查找职工信息
    void findWorker();

    // 按照编号排序
    void sortWorker();

    // 清空所有文档
    void clearWorker();

    ~WorkerManager();
};
