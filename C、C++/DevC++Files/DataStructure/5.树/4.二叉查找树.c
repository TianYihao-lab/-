#include<stdio.h>
#include<stdlib.h>

typedef char E;
typedef struct TreeNode{
    E element;
    struct TreeNode *left,*right;
}TreeNode,*TNode;

TNode Create(E e){
    TNode tempNode= malloc(sizeof(TreeNode));
    tempNode->element=e;
    tempNode->left = tempNode->right = NULL;
    return tempNode;
}

void Insert(TNode root, TNode node)
{
    TNode parent = NULL;
    TNode current = root;
    // 找到插入位置
    while (current != NULL)
    {
        parent = current;
        if (node->element > current->element)
            current = current->right;
        else
            current = current->left;
    }
    // 插入到 parent 的合适位置
    if (node->element > parent->element)
        parent->right = node;
    else
        parent->left = node;
}

void preOrder(TNode root){
    if(!root)
        return;
    printf("%c",root->element);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    TNode A = Create('a');
    Insert(A, Create('b'));
    Insert(A,Create('c'));
    Insert(A,Create('d'));
    Insert(A,Create('e'));
    Insert(A, Create('f'));
    preOrder(A);
    puts("");
    system("pause");
    return 0;
}