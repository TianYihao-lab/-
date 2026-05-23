#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 9 // 规定哈希表的大小

/*
    哈希冲突：线性探测法
*/

//  ----------------
// 定义哈希表结构体
typedef struct Element
{ // 定义哈希表中的元素
    int key;
} Element, *e;

typedef struct HashTable
{
    e *table; // table是利用指针实现的一个数组
} HashTable, *hashTable;
// -----------------

void init(hashTable _hash)
{ // 初始化哈希表
    _hash->table = (e *)malloc(sizeof(e) * Max);
    for (int i = 0; i < Max; i++)
    {
        _hash->table[i] = NULL;
    }
}

int Hash(int key)
{ // 定义哈希函数
    return key % Max;
}

e create(int key)
{ // 创建一个新的元素
    e _e = malloc(sizeof(struct Element));
    _e->key = key;
    return _e;
}

void insert(hashTable _hash, e _element)
{ // 插入元素
    int cmp = Hash(_element->key), count = 0;
    while (_hash->table[cmp] != NULL)
    {
        cmp = (cmp + 1) % Max, count++;
        if (count == Max)
        {
            printf("哈希表已经满了,元素%d插入失败\n", _element->key);
            return;
        }
    }
    _hash->table[cmp] = _element;
}

bool find(hashTable _hash, int _key)
{ // 哈希表的查找
    int cmp = Hash(_key), count = 0;
    if (_hash->table[cmp] == NULL) // 先看哈希表对应位置是否为空
        return false;
    else
    {
        while (_hash->table[cmp] != NULL && _hash->table[cmp]->key != _key && count != Max)
        {
            cmp = (cmp + 1) % Max, count++;
        }
        return _hash->table[cmp] != NULL && _hash->table[cmp]->key == _key;
    }
}

void test01()
{
    struct HashTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(1));
    insert(&hashTable, create(2));
    insert(&hashTable, create(3));
    insert(&hashTable, create(4));
    insert(&hashTable, create(5));
    insert(&hashTable, create(6));
    insert(&hashTable, create(7));
    insert(&hashTable, create(8));
    insert(&hashTable, create(9));
    insert(&hashTable, create(11));
    puts("");

    for (int i = 0; i < Max; i++)
    {
        if (hashTable.table[i])
        {
            printf("%d ", hashTable.table[i]->key);
        }
        else
        {
            printf("NULL ");
        }
    }
    puts("");
}

void test02()
{
    struct HashTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(1));
    insert(&hashTable, create(10));

    printf("%d\n", find(&hashTable, 1));
    printf("%d\n", find(&hashTable, 2));
    printf("%d\n", find(&hashTable, 10));

    for (int i = 0; i < Max; i++)
    {
        if (hashTable.table[i])
        {
            printf("%d ", hashTable.table[i]->key);
        }
        else
        {
            printf("NULL ");
        }
    }
    puts("");
}
void test03()
{
    struct HashTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(1));
    insert(&hashTable, create(2));
    insert(&hashTable, create(3));
    insert(&hashTable, create(4));
    insert(&hashTable, create(5));
    insert(&hashTable, create(6));
    insert(&hashTable, create(7));
    insert(&hashTable, create(8));
    insert(&hashTable, create(9));

    printf("%d\n", find(&hashTable, 10));
    printf("%d\n", find(&hashTable, 20));
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}