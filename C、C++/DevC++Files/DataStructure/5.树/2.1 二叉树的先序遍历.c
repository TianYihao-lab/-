#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
二叉树的先序遍历可以分为
	1）借助递归
	2）直接实现（借助栈）
*/

typedef char E1;
typedef struct TreeNode
{
	E1 e;
	struct TreeNode *left;
	struct TreeNode *right;
} Node, *node;

node A, B, C, D, E, F;

void creat()
{
	A = (Node *)malloc(sizeof(struct TreeNode));
	B = (node)malloc(sizeof(Node));
	C = (node)malloc(sizeof(Node));
	D = (node)malloc(sizeof(Node));
	E = (node)malloc(sizeof(Node));
	F = (node)malloc(sizeof(Node));
	A->e = 'A', B->e = 'B', C->e = 'C', D->e = 'D', E->e = 'E', F->e = 'F';

	A->left = B, A->right = C;
	B->left = D, B->right = E;
	C->left = NULL, C->right = F;
	D->left = D->right = NULL;
	E->left = E->right = NULL;
	F->left = F->right = NULL;
}

void preOrder(node root)
{ // 利用递归实现先序遍历
	if (root == NULL)
		return;
	printf("%c", root->e);
	preOrder(root->left);
	preOrder(root->right);
}

void test01()
{
	printf("二叉树先序遍历的路径:");
	preOrder(A);
}

// 注释掉的部分是基于栈来实现的先序遍历

// typedef struct Stack{
//	node element;
//	struct Stack* next;
// }SNode,*Snode;
//
//// 首先需要手动实现一个栈
// void initStack(Snode node);
// bool push(Snode node,int e);
// node pop(Snode node);
// void printNode(SNode node);
// bool isEmpty(SNode node);
//
// void preorder(node root){  // 利用栈直接实现先序遍历
//	SNode treeStack;
//	initStack(&treeStack);
//	while (root || !isEmpty(treeStack)){   //两个条件，只有当栈空并且节点为NULL时才终止循环
//         while (root) {    //按照我们的思路，先不断遍历左子树，直到没有为止
//             push(&treeStack, root);   //途中每经过一个结点，就将结点丢进栈中
//             printf("%c", root->e);   //然后打印当前结点元素值
//             root = root->left;  //继续遍历下一个左孩子结点
//         }
//         root = pop(&treeStack);  //经过前面的循环，明确左子树全部走完了，接着就是右子树了
//         root = root->right;  //得到右孩子，如果有右孩子，下一轮会重复上面的步骤；如果没有右孩子那么这里的root就被赋值为NULL了，下一轮开始会直接跳过上面的while，继续出栈下一个结点再找右子树
//     }
// }
// void test02(){
//	preorder(A);
// }

// 测试部分
int main()
{
	creat();
	test01();
	printf("\n");
	// test02();
	return 0;
}

// void initStack(Snode node) {
//	node->next = NULL;
// }
// bool push(Snode node, int e) {
//	Snode newNode = (Snode)malloc(sizeof(SNode));
//	if (newNode == NULL)return false;
//	newNode->element = e;
//	newNode->next = node->next;
//	node->next = newNode;
//	return true;
// }
// node pop(Snode _node) {
//	Snode top = _node->next;
//	_node->next = top->next;
//	node e = top->element;
//	free(top);
//	return e;
// }
// void printNode(SNode node) {
//	while (node.next != NULL) {
//		printf("->%c",node.next->element);
//	}
// }
// bool isEmpty(SNode node) {
//	return node.next != NULL;
// }
