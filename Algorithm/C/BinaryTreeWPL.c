#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode{
    // 二叉树的数据结构，包含节点权值weight，左右孩子left和right
    int weight;
    struct BinaryTreeNode *left, *right;
}BinaryTreeNode, *BinaryTree;

//定义一个变量用于存储wpl
static int wpl = 0;

int computeWpl(BinaryTree root){
    return wplPreOrder(root, 0);
}

int wplPreOrder(BinaryTree root, int deepNum){
    // 判断节点类型
    if(root->left == NULL && root->right == NULL)
    {
        //若节点为叶子结点，则累加wpl
        wpl += deepNum*root->weight;
    }

    if(root->left != NULL)
    {
        //若左孩子不为空，对左孩子递归遍历
        wplPreOrder(root->left, deepNum+1);
    }
    if(root->right != NULL)
    {
        //若右孩子不为空，对右孩子递归遍历
        wplPreOrder(root->right, deepNum+1);
    }

    return wpl;
}

void CreateBinaryTree(BinaryTree *T){
    // 创建一颗二叉树
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
    // 创建二叉树
    CreateBinaryTree(&Tree);
    // 计算wple
    computeWpl(Tree);
    // 显示wpl计算结果
    printf("此二叉树的wpl为：%d\n", wpl);

    return 0;
}
