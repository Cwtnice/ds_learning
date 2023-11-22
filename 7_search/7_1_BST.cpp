/*
 * 二叉排序树
 *
 * 核心操作有：
 *      插入
 *      建树
 *      删除(难)
 *      查找
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

// 层序遍历 用队列
void level_order_traversal(BSTNode* root){
    queue<BSTNode*> q;
    q.push(root);

    // 只要队不为空
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        ans.push_back(p->val);

        // 如果左右孩子不为空 按顺序入队
        if(p->l) q.push(p->l);
        if(p->r) q.push(p->r);
    }
}

int calDepth(BSTNode* root) {
    int h = 0;
    if (root->l) {
        h = max(h, calDepth(root->l) + 1);
    }
    if (root->r) {
        h = max(h, calDepth(root->r) + 1);
    }
    return h;
}

void dfs(vector<vector<string>>& res, BSTNode* root, int r, int c, const int& height) {
    res[r][c] = to_string(root->val);
    if (root->l) {
        dfs(res, root->l, r + 1, c - (1 << (height - r - 1)), height);
    }
    if (root->r) {
        dfs(res, root->r, r + 1, c + (1 << (height - r - 1)), height);
    }
}

// 打印二叉树
vector<vector<string>> printTree(BSTNode* root) {
    int height = calDepth(root);
    int m = height + 1;
    int n = (1 << (height + 1)) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    dfs(res, root, 0, (n - 1) / 2, height);
    return res;
}



int main(){
    int a[] = {10, 5, 2, 3, 8, 4, 6, 1, 7, 9};
    BSTree t;
    BST_create(t, a, 10);

    auto tree = printTree(t);
    for(auto i : tree){
        for(auto j : i){
            if(j == "") cout << "-";
            else cout << j;
        }
        cout << endl;
    }





    return 0;
}