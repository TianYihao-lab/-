#include "employee.h"

Employee::Employee(int id, string name, int deptId)
{
    // cout << "Employee ���캯������" << endl;
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

Employee::~Employee()
{
    // cout << "Employee ������������" << endl;
}

void Employee::showInfo()
{
    cout << "ְ����ţ�" << this->m_Id
         << "\tְ��������" << this->m_Name
         << "\t��λ��" << this->getDeptName()
         << "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName()
{
    return string("Ա��");
}