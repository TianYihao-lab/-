#include<stdio.h>
#include<stdlib.h>

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode* left,*right;
    _Bool leftTag,rightTag;
} TreeNode, *TNode;

TNode Create(E e){
    TNode tempNode = malloc(sizeof(TreeNode));
    tempNode->element=e;
    tempNode->left = tempNode->right = NULL;
    tempNode->leftTag = tempNode->rightTag = 0;     // 未被线索化的结点Tag都为 0,线索化之后Tag置为 1
    return tempNode;
}

TNode pre=NULL;     // pre指针指向root节点的根节点

void preOrderSignal(TNode root){        // 进行线索化的函数 -也是一次先序遍历的过程
    if(!root)return;

    if(root->left==NULL){
        root->left = pre;
        root->leftTag = 1;
    }
    if(pre&&pre->right==NULL){
        pre->right = root;
        pre->rightTag = 1;
    }

    pre=root;   // 遍历完当前节点,就把pre指向root

    if(root->leftTag==0)
        preOrderSignal(root->left);
    if (root->rightTag == 0)
        preOrderSignal(root->right);
}
void preOrder(TNode root){      // 经过线索化后的二叉树所用的先序遍历
    while(root){
        printf("%c", root->element);
        if(root->leftTag==0)
            root = root->left;
        else
            root = root->right;
    }
}
int main(){
    TNode A=Create('a'),B=Create('b'),C=Create('c'),D=Create('d'),E=Create('e'),F=Create('f');
    A->left=B,A->right=C;
    B->left = D, B->right = E;
    C->right = F;

    preOrderSignal(A);
    printf("先序遍历的二叉树路径：");
    preOrder(A);
    return 0;
}