/*
 * 878 2017
 * 在BST中找到比X大的数 并以非递增的方式打印出来
 *
 * 通过中序遍历，实现BST从小到大的遍历，加一个判断，大于x的数才打印即可
 *
 */

#include <iostream>
#include <queue>
using namespace std;

// BST结点
typedef struct BSTNode{
    int val;
    BSTNode *l; // 左孩子
    BSTNode *r;
}BSTNode, *BSTree;

vector<int> ans;

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

// 以非递减顺序打印BST中大于x的元素
// 在中序遍历（递归）的基础上多一个判断
void find_large_than_x(BSTree t, int x){    /* NOLINT */
    if(t == nullptr) return;

    find_large_than_x(t->l, x);
    if(t->val > x)
        cout << t->val << " ";
    find_large_than_x(t->r, x);
}

int main(){
    int a[] = {10, 5, 2, 3, 8, 4, 6, 1, 7, 9};
    BSTree t;
    BST_create(t, a, 10);

    int x;
    cout << "请输入x的值：";
    cin >> x;
    find_large_than_x(t, x);
}