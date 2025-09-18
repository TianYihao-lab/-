#include"employer.h"

void Employer::showInfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：给员工发布任务" << endl;
}

string Employer::getDeptName()
{
    return string("经理");
}

Employer::Employer(int id, string name, int deptId)
{
    // cout << "Employer 构造函数调用" << endl;
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

Employer::~Employer()
{
    // cout << "Employer 析构函数调用" << endl;
}