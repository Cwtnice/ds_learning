/*
 * 二叉树的前序遍历
 * 方法有：
 *      递归（关键在于找到递归退出条件和按条件分步进行递归）
 *
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

// 前序遍历 递归
void pre_order_traversal(TreeNode* root){
    // 递归出口
    if(root == nullptr)
        return;
    else
        ans.push_back(root->val);   // 访问根节点

    // 递归左右孩子
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

int main(){
    vector<int>v = {1,2,3,-1,-1,4,5};
    TreeNode* root = createTree(v); // 建树

    pre_order_traversal(root); // 前序遍历

    puts("递归实现的前序遍历序列：");
    for(int an : ans)
        cout << an << " ";

    return 0;
}

