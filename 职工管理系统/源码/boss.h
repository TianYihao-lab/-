#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Boss : public Worker
{
public:
    Boss(int id, string name, int deptId);
    // 显示职工信息
    virtual void showInfo();
    // 获取职工岗位名称
    virtual string getDeptName();
    ~Boss();
};