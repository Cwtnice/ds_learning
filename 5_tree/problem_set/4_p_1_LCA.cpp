/*
 * 二叉树的最近公共祖先
 * Leetcode 236. 二叉树的最近公共祖先
 *
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> ans;

// 树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // 一个构造器是接收单个参数的 那么最好要加上explicit 如果不加的话 该构造函数还会拥有类型转换的情形，造成混淆。
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 建树 根据向量
TreeNode * createTree(vector<int>v) {
    if (v.empty()) {
        return nullptr;
    }
    // 使用逐层遍历的方式，生成树
    queue<TreeNode*> q;
    auto root = new TreeNode(v[0]);
    q.push(root);

    int idx = 1; // 用以表示当前数组可用的元素下标
    while (!q.empty() && idx < v.size()) {
        int cnt = q.size();
        for (int i = 1; i <= cnt; i++) {
            TreeNode* cur = q.front();
            q.pop();
            //判断左子树是否为空
            if (v[idx] != -1) {
                auto t = new TreeNode(v[idx]);
                cur->left = t;
                q.push(cur->left);
            }
            idx++;
            if (idx >= v.size()) {
                break;
            }
            //判断右子树是否为空
            if (v[idx] != -1) {
                auto t = new TreeNode(v[idx]);
                cur->right = t;
                q.push(cur->right);
            }
            idx++;
        }
    }
    return root;
}

// 根据值返回结点的指针 类似于层序遍历
TreeNode* find_node(TreeNode* root, int val){
    queue<TreeNode*> q;
    q.push(root);

    // 只要队不为空
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p->val == val)
            return p;

        // 如果左右孩子不为空 按顺序入队
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}

// 最近公共祖先LCA
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root ==  nullptr)
        return nullptr;
    if(root == p || root == q)
        return root;

    // 递归左右孩子
    auto left = LCA(root->left, p, q);
    auto right = LCA(root->right, p, q);

    if(left && right) return root;
    if(left) return left;
    if(right) return right;

    return nullptr;
}



int main(){
    vector<int>v = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = createTree(v); // 建树

    int p, q;
    printf("输入两个结点p和q：");
    cin >> p >> q;
    auto p_node = find_node(root, p), q_node = find_node(root, q);
    printf("p结点和q结点的最近公共祖先的值为：%d", LCA(root, p_node, q_node)->val);

    return 0;
}

