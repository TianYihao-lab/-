#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
    int m_Id;           // ְ�����  ע�⣺����ͬ�������±ꡣ
    string m_Name;     // ְ������
    int m_DeptId;      // ְ�����ű��

    // ��ʾְ����Ϣ     -- ���麯��
    virtual void showInfo() = 0;

    // ��ȡְ����λ����     -- ���麯��
    virtual string getDeptName() = 0;

    // Worker(int id, string name, int deptId);
    virtual ~Worker(){};
};