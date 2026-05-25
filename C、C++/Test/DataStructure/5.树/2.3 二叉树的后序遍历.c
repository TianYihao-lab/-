#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
二叉树的后序遍历可以分为
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

void creat();

void postOrder(node root)
{
	if (!root)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%c", root->e);
}
void test01()
{
	creat();
	printf("二叉树后序遍历路径:");
	postOrder(A);
}

int main()
{
	test01();
	return 0;
}

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
	printf("创建二叉树成功\n");
}
