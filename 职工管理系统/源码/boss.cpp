#include"boss.h"

Boss::Boss(int id, string name, int deptId)
{
    // cout << "Boss ���캯������" << endl;
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

Boss::~Boss()
{
    // cout << "Boss ������������" << endl;
}

void Boss::showInfo()
{
    cout << "ְ����ţ�" << this->m_Id
         << "\tְ��������" << this->m_Name
         << "\t��λ��" << this->getDeptName()
         << "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
    return string("�ϰ�");
}
