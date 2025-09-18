#pragma once // ������ֹͷ�ļ����ظ�����
#include <iostream>
using namespace std;
#include"worker.h"
#include<fstream>

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    int m_EmpNum;        // ��¼ְ������
    Worker **m_EmpArray; // ְ������ָ��
    bool m_FileIsEmpty;  // �ļ���־���ж��ļ��Ƿ����

    // ���캯��
    WorkerManager();
    int getEmpNum();    // ͳ���ļ��е�����
    void initEmp();     // ��ʼ��Ա��(���ļ��е�Ԫ��ȫ��ȡ�������� m_EmpArray��)

    // չʾ����
    void showMenu();

    // �˳�ְ������ϵͳ
    void exitSystem();

    // ����ְ����Ϣ
    void addWorker();
    void save();        // ��Ա����Ϣ�����ı�
    
    // ��ʾְ����Ϣ
    void showWorker();

    // ɾ����ְְ��
    void deleteWorker();
    int isExist(int id);    // �ж�Ա���Ƿ����

    // �޸�ְ����Ϣ
    void changeWorker();

    // ����ְ����Ϣ
    void findWorker();

    // ���ձ������
    void sortWorker();

    // ��������ĵ�
    void clearWorker();

    ~WorkerManager();
};
