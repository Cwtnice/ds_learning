/*
 * 在二叉搜索树中删除关键字为x的结点
 *
 */

#include <iostream>
using namespace std;

// BST结点
typedef struct BSTNode{
    int val;
    BSTNode *l; // 左孩子
    BSTNode *r;
}BSTNode, *BSTree;

// BST插入
BSTree BST_insert(BSTree &t, int k){    /* NOLINT */
    // 原树为空 k将新建结点并作为根
    if(t == nullptr){
        t = (BSTree)malloc(sizeof(BSTNode));
        t->val = k;
        t->l = t->r = nullptr;
    }
        // 类似于查找的递归算法
    else{
        if(k < t->val)
            return BST_insert(t->l, k);
        else if(k > t->val)
            return BST_insert(t->r, k);
        else
            printf("已经存在该结点, 插入失败！");
    }
    return t;
}

// BST建树
void BST_create(BSTree &t, int a[], int n){
    t = nullptr;    // 初始为空树
    for(int i = 0; i < n; i++)
        BST_insert(t, a[i]);
}

// BST查找 递归
BSTree BST_search(BSTree t, int key){   /* NOLINT */
    if(t == nullptr)
        return nullptr;

    if(key < t->val)
        return BST_search(t->l, key);
    else if(key > t->val)
        return BST_search(t->r, key);
    else
        return t;
}

// BST查找 非递归
// 是不用栈实现递归转非递归的好例子
BSTree BST_search_2(BSTree t, int key) {
    while(t != nullptr && key != t->val){
        if(key < t->val)
            t = t->l;
        else
            t = t->r;
    }
    return t;
}

// BST删除结点 采用右子树中最小元素代替策略
BSTree BST_delete(BSTree t, int key){

}

int main(){
    int a[] = {10, 5, 2, 3, 8, 4, 6, 1, 7, 9};
    BSTree t;
    BST_create(t, a, 10);

    return 0;
}