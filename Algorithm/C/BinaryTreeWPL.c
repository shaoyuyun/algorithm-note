#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode{
    // �����������ݽṹ�������ڵ�Ȩֵweight�����Һ���left��right
    int weight;
    struct BinaryTreeNode *left, *right;
}BinaryTreeNode, *BinaryTree;

//����һ���������ڴ洢wpl
static int wpl = 0;

int computeWpl(BinaryTree root){
    return wplPreOrder(root, 0);
}

int wplPreOrder(BinaryTree root, int deepNum){
    // �жϽڵ�����
    if(root->left == NULL && root->right == NULL)
    {
        //���ڵ�ΪҶ�ӽ�㣬���ۼ�wpl
        wpl += deepNum*root->weight;
    }

    if(root->left != NULL)
    {
        //�����Ӳ�Ϊ�գ������ӵݹ����
        wplPreOrder(root->left, deepNum+1);
    }
    if(root->right != NULL)
    {
        //���Һ��Ӳ�Ϊ�գ����Һ��ӵݹ����
        wplPreOrder(root->right, deepNum+1);
    }

    return wpl;
}

void CreateBinaryTree(BinaryTree *T){
    // ����һ�Ŷ�����
    *T = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    (*T)->weight = 1;
    (*T)->left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    (*T)->right = NULL;
    (*T)->left->weight = 2;
    (*T)->left->left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    (*T)->left->right = NULL;
    (*T)->left->left->weight = 3;
    (*T)->left->left->left = NULL;
    (*T)->left->left->right = NULL;
}

int main(){
    BinaryTree Tree;
    // ����������
    CreateBinaryTree(&Tree);
    // ����wple
    computeWpl(Tree);
    // ��ʾwpl������
    printf("�˶�������wplΪ��%d\n", wpl);

    return 0;
}
