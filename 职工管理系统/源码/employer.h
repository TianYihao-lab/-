#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Employer : public Worker
{
public:
    Employer(int id, string name, int deptId);
    // ��ʾְ����Ϣ
    virtual void showInfo();
    // ��ȡְ����λ����
    virtual string getDeptName();
    ~Employer();
};