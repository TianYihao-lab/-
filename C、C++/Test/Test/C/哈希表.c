#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 9 // 规定哈希表的大小

//  ----------------
// 定义哈希表结构体
typedef struct Element
{ // 定义哈希表中的元素
    int key;
} Element;

typedef struct HashTable
{
    Element *table; // table是利用指针实现的一个数组
} HashTable, *hashTable;
// -----------------

void init(hashTable _hash)
{ // 初始化哈希表
    _hash->table = (Element *)malloc(sizeof(struct Element) * Max);
    for (int i = 0; i < Max; i++)
    {
        _hash->table[i].key = -1;
    }
}

int Hash(int key)
{ // 定义哈希函数
    return key % Max;
}

Element create(int key)
{ // 创建一个新的元素
    Element _e;
    _e.key = key;
    return _e;
}

void insert(hashTable _hash, Element _element)
{ // 插入元素
    int cmp = Hash(_element.key);
    _hash->table[cmp] = _element;
}

bool find(hashTable _hash, int _key)
{ // 哈希表的查找
    int cmp = Hash(_key);
    if (_hash->table[cmp].key == -1) // 先看哈希表对应位置是否为空
        return false;
    return _hash->table[cmp].key == _key; // 再判断值是否相等
}

void test01()
{
    struct HashTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(10));
    insert(&hashTable, create(7));
    insert(&hashTable, create(13));
    insert(&hashTable, create(29));

    for (int i = 0; i < Max; i++)
    {
        if (hashTable.table[i].key != -1)
        {
            printf("%d ", hashTable.table[i].key);
        }
        else
        {
            printf("NULL ");
        }
    }
    puts("");

    printf("%d\n", find(&hashTable, 1));
    printf("%d\n", find(&hashTable, 13));
}

int main()
{
    // test01();
    printf("哈希表");
    return 0;
}
