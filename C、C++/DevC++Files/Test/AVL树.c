#include <stdio.h>
#include <stdlib.h>
typedef int E;

typedef struct TreeNode
{
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
    int height; // 每个结点需要记录当前子树的高度，便于计算平衡因子
} *Node;

Node createNode(E element)
{
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1; // 初始化时，树高度写为1就可以了
    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getHeight(Node root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

Node leftRotation(Node root)
{                                // 左旋操作，实际上就是把左边结点拿上来
    Node newRoot = root->right;  // 先得到左边结点
    root->right = newRoot->left; // 将左边结点的左子树丢到原本根结点的右边去
    newRoot->left = root;        // 现在新的根结点左边就是原本的跟结点了

    // 更新子树高度
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node rightRotation(Node root)
{
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node leftRightRotation(Node root)
{
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node rightLeftRightRotation(Node root)
{
    root->right = rightRotation(root->right);
    return leftRotation(root);
}
Node insert(Node root, E element)
{
    if (root == NULL)
    { // 说明找到了插入位置
        root = createNode(element);
    }
    else if (root->element)
}
int main()
{

    system("pause");
    return 0;
}