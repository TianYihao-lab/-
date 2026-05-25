#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 9 // 哈希表大小（桶的数量）

// ----------------------
// 链表节点（哈希表元素）
typedef struct Element
{
    int key;
    struct Element *next; // 指向下一个节点
} Element, *e;

// 哈希表结构
typedef struct HashTable
{
    e *table; // 指针数组，每个位置指向一个链表的头
} HashTable, *hashTable;
// ----------------------

// 初始化哈希表
void init(hashTable _hash)
{
    _hash->table = (e *)malloc(sizeof(e) * Max); // 分配指针数组
    for (int i = 0; i < Max; i++)
    {
        _hash->table[i] = NULL; // 每个桶的链表开始为空
    }
}

// 哈希函数
int Hash(int key)
{
    return key % Max;
}

// 创建一个元素节点
e create(int key)
{
    e _e = (e)malloc(sizeof(Element));
    _e->key = key;
    _e->next = NULL;
    return _e;
}

// 插入元素（头插法）
void insert(hashTable _hash, int key)
{
    int cmp = Hash(key);
    e newNode = create(key);

    // 头插到对应桶的链表里
    newNode->next = _hash->table[cmp];
    _hash->table[cmp] = newNode;
}

// 查找元素
bool find(hashTable _hash, int key)
{
    int cmp = Hash(key);
    e cur = _hash->table[cmp];
    while (cur)
    {
        if (cur->key == key)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// 打印哈希表
void printHash(hashTable _hash)
{
    for (int i = 0; i < Max; i++)
    {
        printf("[%d] -> ", i);
        e cur = _hash->table[i];
        while (cur)
        {
            printf("%d -> ", cur->key);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

// 释放哈希表内存
void freeHash(hashTable _hash)
{
    for (int i = 0; i < Max; i++)
    {
        e cur = _hash->table[i];
        while (cur)
        {
            e tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(_hash->table);
}

// 测试
void test01()
{
    struct HashTable hashTable;
    init(&hashTable);

    insert(&hashTable, 10);
    insert(&hashTable, 7);
    insert(&hashTable, 13);
    insert(&hashTable, 29);
    insert(&hashTable, 19); // 发生冲突（19 % 9 == 1，和10同桶）

    printHash(&hashTable);

    printf("Find 13? %d\n", find(&hashTable, 13));
    printf("Find 1? %d\n", find(&hashTable, 1));

    freeHash(&hashTable);
}

int main()
{
    test01();
    return 0;
}
