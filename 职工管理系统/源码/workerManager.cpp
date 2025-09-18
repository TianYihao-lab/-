#include "workerManager.h"
#include"employee.h"
#include"employer.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
    // cout << "WorkManager ���캯������" << endl;

    // 1. �ļ�������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);    // �Զ��ķ�ʽ���ļ�

    if(!ifs.is_open()){
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true; // �ļ������ڣ���־Ϊ��
        ifs.close();
        return;
    }
    // 2. �ļ����ڣ�����û������
    char ch;
    ifs >> ch;  // ��ȡһ���ַ�
    if(ifs.eof()){   // eof�����������ж��ļ�ָ��ָ���λ���Ƿ��ǿ�
        cout << "�ļ�Ϊ��" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true; // �ļ�Ϊ�գ���־Ϊ��
        ifs.close();
        return;
    }

    // 3. �ļ����ڣ���������
    int num = this->getEmpNum();
    cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum= num;
    // ���ٿռ�
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->m_FileIsEmpty = false; // �ļ���Ϊ�գ���־Ϊ��
    // ���ļ��е����ݶ���������
    this->initEmp();
    ifs.close();
}

// ͳ���ļ��е�����
int WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
}

// ��ʼ��Ա��
void WorkerManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // ���ļ�����������
    int id;
    string name;
    int did;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if (did == 1) // �����������Ŵ�����ͬ����
        {
            worker = new Employee(id, name, 1);
        }
        else if (did == 2)
        {
            worker = new Employer(id, name, 2);
        }
        else if (did == 3)
        {
            worker = new Boss(id, name, 3);
        }
        // �����������
        this->m_EmpArray[index] = worker;
        index++;
    }
}

WorkerManager::~WorkerManager()
{
    // cout << "WorkManager ������������" << endl;
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::showMenu()
{
    cout << "**************************************" << endl;
    cout << "******** ��ӭʹ��ְ������ϵͳ *********" << endl;
    cout << "********** 0.�˳��������    **********" << endl;
    cout << "********** 1.����ְ����Ϣ    **********" << endl;
    cout << "********** 2.��ʾְ����Ϣ    **********" << endl;
    cout << "********** 3.ɾ����ְְ��    **********" << endl;
    cout << "********** 4.�޸�ְ����Ϣ    **********" << endl;
    cout << "********** 5.����ְ����Ϣ    **********" << endl;
    cout << "********** 6.���ձ������    **********" << endl;
    cout << "********** 7.��������ĵ�    **********" << endl;
    cout << "**************************************" << endl;
}

void WorkerManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);    // �൱�� return 0;
}

void WorkerManager::addWorker()
{
    int num=0;
    cout << "���������ְ����������" << endl;
    cin >> num;
    if(num>0){
        // ����Ҫ�����¿ռ�Ĵ�С
        int newSize = this->m_EmpNum + num;

        // �����¿ռ�
        Worker ** newSpace = new Worker *[newSize];     // ������һ����άָ�롣

        // ��ԭ���ռ��µ����ݿ������¿ռ���
        if(this->m_EmpArray != NULL){
            for(int i=0; i<this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // �������������
        for(int i=0; i<num; i++){
            int id;         // ���
            string name;    // ����
            int dSelect;    // ����ѡ��

            cout << "������� " << i+1 << " ����ְ���ı�ţ�" << endl;
            cin >> id;

            cout << "������� " << i+1 << " ����ְ����������" << endl;
            cin >> name;

            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;

            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Employer(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            // ��������ְ�����󣬱��浽������
            newSpace[this->m_EmpNum + i] = worker;
        }

        // �ͷ�ԭ�пռ�
        delete [] this->m_EmpArray;
        // �����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        // �����µ�ְ������
        this->m_EmpNum = newSize;
        // ��ʾ��ӳɹ�
        cout << "�ɹ���� " << num << " ����ְ��" << endl;
        
        // �������ݵ��ļ���
        this->save();

    }else{
        cout << "��������" << endl;
    };
    // ����������������ټ�������
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    // 1.���ļ�
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // �ļ������ڻ��Զ����������ڻḲ��

    // 2.д������
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    // 3.�ر��ļ�
    ofs.close();
}

void WorkerManager::showWorker()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // ���ö�̬���ýӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls"); 
}

void WorkerManager::deleteWorker()
{
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڣ�\n";
        return;
    }
    cout << "��������Ҫɾ����Ա���ı�ţ�\n";
    int tempid;
    cin >> tempid;
    int ret = isExist(tempid);
    if (ret != -1)  // �ҵ���Ա��
    {
        // cout << "�������е�λ�ã�" << ret << " ta�ı�ţ�" << m_EmpArray[ret]->m_Name<<endl;
        for (int i = ret; i < this->m_EmpNum - 1; i++)
        {
            this->m_EmpArray[i]->m_Name = this->m_EmpArray[i+1]->m_Name;
            this->m_EmpArray[i]->m_Id = this->m_EmpArray[i+1]->m_Id;
            this->m_EmpArray[i]->m_DeptId = this->m_EmpArray[i+1]->m_DeptId;
        }
        this->m_EmpNum--;
        this->save(); // ���µ���Ϣ�����ļ�
        cout << "ɾ���ɹ�\n";
    }
    else
    {
        cout << "Ҫɾ����Ա�������ڣ�\n";
        return;
    }
    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id)
{
    int index = -1;
    for(int i=0; i<this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;   // ���ص��Ƕ�Ӧ��ŵ�Ա���������е��±ꡣ
}

void WorkerManager::changeWorker()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڣ�\n";
        return;
    }
    cout << "��������Ҫ�޸ĵ�Ա���ı�ţ�\n";
    int tempid;
    cin >> tempid;
    int ret = isExist(tempid);
    if(ret!=-1){
        cout << "�ҵ���Ա��\n";
        int newId = 0;
        string newName = "";
        int dSelect = 0;
        cout << "�������" << tempid << "��Ա��������Ϣ��";
        cout << "�������µ�ְ���ţ�", cin >> newId;
        cout << "�������µ����֣�", cin >> newName;
        cout << "�������µ�ְλ��ţ�", cin >> dSelect;

        this->m_EmpArray[ret]->m_DeptId = dSelect;
        this->m_EmpArray[ret]->m_Id = newId;
        this->m_EmpArray[ret]->m_Name = newName;

        this->save();   // ���µ���Ϣ�����ļ�
        cout << "�û��޸ĳɹ���";

    }else{
        cout << "��Ա�������ڣ�\n";
        return;
    }
    system("pause");
    system("cls");
}

void WorkerManager::findWorker(){
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڣ�\n";
        return;
    }
    cout << "��ѡ���ѯ��ʽ��\n";
    cout << "1.��ְ����Ų�ѯ" << endl;
    cout << "2.��ְ��������ѯ" << endl;
    cout << "���������ѡ��";
    int select = 0; 
    cin >> select;
    if(select == 1){    // ����Ų�ѯ
        int id;
        cout << "������Ҫ��ѯ��ְ����ţ�";
        cin >> id;
        int ret = isExist(id);
        if(ret != -1){
            cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
            this->m_EmpArray[ret]->showInfo();
        }else{
            cout << "���޴��ˣ�\n" << endl;
        }
    }else if(select == 2){  // ��������ѯ
        string name;
        cout << "������Ҫ��ѯ��ְ��������";
        cin >> name;
        bool flag = false; // ��־�Ƿ��ҵ�
        int _flag = false; // ��֤�����ظ�����ҵ�����ʾ��
        for(int i=0; i<this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_Name == name){
                if(!_flag){
                    cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
                    _flag = true, flag = true;
                }
                this->m_EmpArray[i]->showInfo(); 
            }
        }
        if(!flag){
            cout << "���޴��ˣ�\n" << endl;
        }
    }else{
        cout << "����ѡ������!";
    }
    system("pause");
    system("cls");
}

void WorkerManager::sortWorker(){
    if (m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ:" << endl;
        cout << "1����ְ��������" << endl;
        cout << "2����ְ���Ž���:" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum- 1; i++)
        {
            int minOrmax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1) // ����
                {
                    if (this->m_EmpArray[minOrmax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
                else // ����
                {
                    if (this->m_EmpArray[minOrmax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
            }
            if (i != minOrmax)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrmax];
                m_EmpArray[minOrmax] = temp;
            }
        }
        cout << "����ɹ��������Ľ��Ϊ��" << endl;
        this->save();
        this->showWorker();
    }
}

void WorkerManager::clearWorker(){
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڣ�\n";
        return;
    }

    cout << "ȡ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;
    int select;
    cin >> select;
    if(select==1){
        // �Խض�ģʽ���ļ����ļ���Ϊtest.txt
        ofstream outFile("empFile.txt", ios::trunc);
        if (outFile.is_open())
        {
            // �ļ��򿪳ɹ����Ѿ����ԭ�����ݣ��������ѡ��ر��ļ���Ҳ���Լ���д��������
            if (this->m_EmpArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArray[i] != NULL)
                    {
                        delete this->m_EmpArray[i];
                    }
                }
                this->m_EmpNum = 0;
                delete[] this->m_EmpArray;
                this->m_EmpArray = NULL;
                this->m_FileIsEmpty = true;
            }
            outFile.close();
            cout << "�ļ�����ա�" << endl;
        }
        else
        {
            cerr << "�޷����ļ���" << endl;
        }
    }
}