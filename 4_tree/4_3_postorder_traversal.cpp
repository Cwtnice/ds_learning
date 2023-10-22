/*
 * 二叉树的后序遍历
 * 方法有：
 *      递推（类似于前序, 区别只在于访问结点的顺序）
 *      非递归 用到栈
            算法思想：
            ①. 从根结点开始, 沿着左子树依次入栈, 直到左子树为空
            ②. 读栈顶元素, 如果右孩子存在且未被访问过, 对右孩子执行①
                否则将栈顶元素出栈并且访问

            关于判断右孩子是否被访问过：
                设置一个最近访问指针r, 或者在结点中新增一个访问标志域

            注意：
                每次出栈访问完一个结点，相当于遍历完以该结点为根的子树, 需将p置为NULL
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

// 后序遍历 非递归
void post_order_traversal(TreeNode* root){
    if(root == nullptr)
        return;

    stack<TreeNode*> s;
    TreeNode* p = root;
    TreeNode* r = nullptr;  // r指向最近访问的结点

    while(!s.empty() || p){
        if(p){
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            // 如果p有右孩子且右孩子没有被访问过
            if(p->right && p->right != r)
                p = p->right;

            // 左右孩子都已访问过 访问该结点
            else{
                s.pop();
                ans.push_back(p->val);
                r = p;  // 最近访问的结点更新为p
                p = nullptr; // 将p置空
            }
        }
    }
}

int main(){
    vector<int>v = {1,2,3,-1,-1,4,5};
    TreeNode* root = createTree(v); // 建树

    post_order_traversal(root); // 后序遍历

    puts("非递归实现的后序遍历序列：");
    for(int an : ans)
        cout << an << " ";

    return 0;
}