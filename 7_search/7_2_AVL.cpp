/*
 * 平衡二叉树
 *
 */

#include <iostream>
using namespace std;

// 结构体
struct node {
    int value;  // 值
    node *l, *r;    // 左右指针
};

// 左旋
node* L(node *root) {
    node *t = root->r;
    root->r = t->l;
    t->l = root;
    return t;
}

// 右旋
node* R(node *root) {
    node *t = root->l;
    root->l = t->r;
    t->r = root;
    return t;
}

// 先左后右旋
node* LR(node *root) {
    root->l = L(root->l);
    return R(root);
}

// 先右后左旋
node* RL(node *root) {
    root->r = R(root->r);
    return L(root);
}

// 得到以当前结点为根的子树的高度
int get_height(node *root) {    /* NOLINT */
    if(root == nullptr)
        return 0;
    return max(get_height(root->l), get_height(root->r)) + 1;
}

// 插入结点
node *insert(node *root, int val) { /* NOLINT */
    // root为空就新建一个结点
    if(root == nullptr) {
        root = new node();
        root->value = val;
        root->l = root->r = nullptr;
    }

    // 小于root就插入左子树
    else if(val < root->value) {
        root->l = insert(root->l, val);
        // 如果失衡
        if(get_height(root->l) - get_height(root->r) == 2)
            // LL情况 用右旋 LR情况
            root = val < root->l->value ? R(root) : LR(root);
    }

        // 大于root就插入右子树
    else {
        root->r = insert(root->r, val);
        // 如果失衡
        if(get_height(root->l) - get_height(root->r) == -2)
            root = val > root->r->value ? L(root) : RL(root);
    }
    return root;
}


int main() {
    int n, val;
    printf("请输入结点总数：");
    cin >> n;
    node *root = nullptr;

    // 插入建树
    printf("请依次输入%d个结点, 通过插入构建AVL: ", n);
    for(int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    printf("当前AVL的根结点为：%d", root->value);

    return 0;
}
