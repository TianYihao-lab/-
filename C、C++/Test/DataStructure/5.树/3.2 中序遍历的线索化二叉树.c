#include<stdio.h>
#include<stdlib.h>

typedef char E;
typedef struct TreeNode
{
    E element;
    struct TreeNode *left, *right;
    _Bool leftTag, rightTag;
} TreeNode, *TNode;

TNode Create(E e)
{
    TNode tempNode = malloc(sizeof(TreeNode));
    tempNode->element = e;
    tempNode->left = tempNode->right = NULL;
    tempNode->leftTag = tempNode->rightTag = 0; // 未被线索化的结点Tag都为 0,线索化之后Tag置为 1
    return tempNode;
}

TNode pre = NULL;
void inOrderSignal(TNode root){
    if(!root)return;

    if(root->leftTag==0&&root->left!=NULL){
        inOrderSignal(root->left);
    }
    
    if(root->left==NULL){
        root->left = pre;
        root->leftTag = 1;
    }
    if(pre!=NULL&&pre->right==NULL){
        pre->right=root;
        pre->rightTag = 1;
    }

    pre=root;

    if(root->rightTag==0){
        inOrderSignal(root->right);
    }
}
void inOrder(TNode root)
{
    while (root)
    {                                      // 因为中序遍历需要先完成左边，所以说要先走到最左边才行
        while (root && root->leftTag == 0) // 如果左边一直都不是线索，那么就一直往左找，直到找到一个左边是线索的为止，表示到头了
            root = root->left;

        printf("%c", root->element); // 到最左边了再打印，中序开始

        while (root && root->rightTag == 1)
        { // 打印完就该右边了，右边如果是线索化之后的结果，表示是下一个结点，那么就一路向前，直到不是为止
            root = root->right;
            printf("%c", root->element); // 注意按着线索往下就是中序的结果，所以说沿途需要打印
        }
        root = root->right; // 最后继续从右结点开始，重复上述操作
    }
}

int main(){
    TNode A = Create('a'), B = Create('b'), C = Create('c'), D = Create('d'), E = Create('e'), F = Create('f');
    A->left = B, A->right = C;
    B->left = D, B->right = E;
    C->right = F;

    inOrderSignal(A);
    printf("先序遍历的二叉树路径：");
    inOrder(A);
    return 0;
}