#include"employer.h"

void Employer::showInfo()
{
    cout << "ְ����ţ�" << this->m_Id
         << "\tְ��������" << this->m_Name
         << "\t��λ��" << this->getDeptName()
         << "\t��λְ�𣺸�Ա����������" << endl;
}

string Employer::getDeptName()
{
    return string("����");
}

Employer::Employer(int id, string name, int deptId)
{
    // cout << "Employer ���캯������" << endl;
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

Employer::~Employer()
{
    // cout << "Employer ������������" << endl;
}