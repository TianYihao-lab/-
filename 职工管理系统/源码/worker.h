#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
    int m_Id;           // 职工编号  注意：不等同于数组下标。
    string m_Name;     // 职工姓名
    int m_DeptId;      // 职工部门编号

    // 显示职工信息     -- 纯虚函数
    virtual void showInfo() = 0;

    // 获取职工岗位名称     -- 纯虚函数
    virtual string getDeptName() = 0;

    // Worker(int id, string name, int deptId);
    virtual ~Worker(){};
};