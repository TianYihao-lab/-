#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct ListNode{
	E element;
	struct ListNode *next;
} ListNode, *Node;

void initList(Node node);	//链表的初始化
_Bool insertList(Node node, E e, int index);	// 按照位序插入元素
_Bool deleteList(Node node, int index);			// 删除元素
E *getList(Node node, int index);				// 查找1:按位查找,返回节点信息			
int findList(Node node, E e);					// 查找2:按值查找，返回节点位置

int sizeList(Node node);	// 求链表的长度
void printList(Node node);


void test01()
{
	ListNode node;
	initList(&node);
	for (int i = 1; i <= 3; i++)
	{
		insertList(&node, i, i);
	}
	printf("列表长度为:%d\n", sizeList(&node));
	printList(&node);
	deleteList(&node, 1);
	printf("列表长度为:%d\n", sizeList(&node));
	printList(&node);
}

void test02()
{
	ListNode node;
	initList(&node);
	for (int i = 1; i <= 3; i++)
	{
		insertList(&node, i, i);
	}
	printList(&node);
	// printf("%d ", *getList(&node, -1));    // 访问未被初始化的空间是危险行为
	printf("%d ", *getList(&node, 1));
	printf("%d ", *getList(&node, 3));
	// printf("%d ", *getList(&node, 31));    // 访问未被初始化的空间是危险行为
	puts("");
	printf("%d ", findList(&node, 10));
	printf("%d ", findList(&node, 1));
	printf("%d ", findList(&node, 2));
	printf("%d ", findList(&node, 3));
}

int main()
{
	test01();
	// test02();
	return 0;
}

void initList(Node node){ // 初始化链表
	node->next = NULL;
	// 第一个节点叫做首节点，它没有element
	node->element = 0; // 也可以初始化element成员为0
}

_Bool insertList(Node node, E e, int index){ // 在固定位置上插入元素e
	if (index < 1)
		return 0; // 插入位置不合法（情况一）

	while (--index)
	{
		node = node->next;
		if (node == NULL)
			return 0; // 插入位置不合法（情况二）
	}

	Node newnode = (ListNode *)malloc(sizeof(ListNode));
	if (newnode == NULL)	// 新节点创建失败
		return 0;
	newnode->element = e;
	newnode->next = node->next;
	node->next = newnode;
	return 1;
}

_Bool deleteList(Node node, int index){ // 删除规定位置上的元素
	if (index < 1)
		return 0;
	while (--index)
	{ // 找到要删除节点的前一个位置
		node = node->next;
		if (node == NULL)
			return 0;
	}
	if (node->next == NULL)
		return 0; //
	Node tempnode = node->next;
	node->next = tempnode->next;
	free(tempnode);
	return 1;
}

E *getList(Node node, int index){ // 找链表中第index个位置上的值

	if (index < 1)
		return 0;
	while (index--)
	{
		if (node == NULL)
			return 0;

		node = node->next;
	}
	return &node->element;
}

// E * getList(Node node, int index) {
//	int cnt = 0;
//	if (index < 1)return 0;
//	while (node != NULL) {
//		if (cnt == index)
//			return &node->element;
//		node = node->next;
//		cnt++;
//	}
//	return 0;
// }

// E* getList(Node head, int index) {
//	if (index < 1) return NULL;   //如果小于0那肯定不合法，返回NULL
//	do {
//		head = head->next;  //因为不算头结点，所以使用do-while语句
//		if (head == NULL) return NULL;  //如果已经超出长度那肯定也不行
//	} while (--index);  //到达index就结束
//	return &head->element;
// }

int findList(Node node, E e){ // 找链表中值为e的元素的下标
	int cnt = 0;
	while (node != NULL)
	{
		if (node->element == e)
			return cnt;

		node = node->next;
		cnt++;
	}
	return -1;
}

int sizeList(Node node){
	int cnt = 0; // 从0开始
	while (node->next)
	{ // 如果下一个为NULL那就停止
		node = node->next;
		cnt++; // 每向后找一个就+1
	}
	return cnt;
}

void printList(Node node){	// 打印链表
	node = node->next; // 首节点不需要打印出来
	while (node != NULL)
	{
		printf("%d ", node->element);
		node = node->next;
	}
	puts("");
}
