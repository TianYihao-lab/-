#include"boss.h"

Boss::Boss(int id, string name, int deptId)
{
    // cout << "Boss 构造函数调用" << endl;
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

Boss::~Boss()
{
    // cout << "Boss 析构函数调用" << endl;
}

void Boss::showInfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
    return string("老板");
}
