/*
 * 深度优先遍历
 *
 * 这里是有向图 用的是邻接表
 * DFS序列在邻接表情况下会唯一
 *
 * 邻接矩阵一般用递归 邻接表用非递归
 *
 * 可以看 https://blog.csdn.net/smart_jackli/article/details/127919542
 */

#include<iostream>
#include<stack>
using namespace std;

#define MAX 10
int visited[MAX];   // 访问标记数组

// 边表结点
typedef struct ENode{
    int adjvex;
    ENode* next;
}ENode;

// 顶点表结点
typedef struct VNode {
    char data;
    ENode* first;
}VNode;

// 图
typedef struct {
    VNode AdjList[MAX]; // 定点表
    int v_num;
    int e_num;
}ALGraph;

// 创建邻接表
void adj_list_create(ALGraph& G) {
    int i, j, k;
    ENode* e = nullptr;
    ENode* q = nullptr;

    cout << "请输入顶点数和边数： " << endl;
    cin >> G.v_num >> G.e_num;

    cout << "请输入顶点信息" << endl;
    for (k = 0; k < G.v_num; k++){
        cin >> G.AdjList[k].data;
        G.AdjList[k].first = nullptr;
    }

    for (k = 0; k < G.e_num; k++){
        cout << "请输入边(vi,vj)的下标i,j： " << endl;
        cin >> i >> j;

        // 用头插法加入边表
        e = new ENode;
        e->adjvex = j;
        e->next = G.AdjList[i].first;
        G.AdjList[i].first = e;
    }
}

// 打印邻接表
void adj_list_print(ALGraph G){
    cout << endl << "邻接表: " << endl;
    ENode* p;
    for (int i = 0; i < G.v_num; i++){
        cout << G.AdjList[i].data << ": ";  // 打印顶点表结点

        // 打印边表结点
        for (p = G.AdjList[i].first; p; p = p->next){
            cout << p->adjvex;
            if(p->next)
                cout << "->";
        }

        cout << endl;
    }
}

// 深度优先遍历 递归
void DFS(ALGraph G, int v){
    // 访问当前结点
    cout << G.AdjList[v].data << " ";
    visited[v] = 1;

    // 遍历v的所有邻接点w
    ENode *p = G.AdjList[v].first;
    while(p){
        int w = p->adjvex;
        if(visited[w] == 0)
            DFS(G, w);
        p = p->next;
    }
}

// 深度优先遍历 递归
// 由于使用了栈, 会先访问边表结点离得"远"的邻接点, 但仍是DFS
void DFS_2(ALGraph G, int v){
    stack<int> st;

    // 顶点入栈
    st.push(v);

    while(!st.empty()){
        int t = st.top();
        st.pop();
        visited[t] = 1;
        cout << G.AdjList[t].data << " ";

        ENode *p = G.AdjList[t].first;
        while(p){
            int w = p->adjvex;
            if(!visited[w]){
                st.push(w);
                visited[w] = 1;
            }
            p = p->next;
        }
    }
}

int main() {
    ALGraph G;
    adj_list_create(G);
    adj_list_print(G);

    // 初始化访问标记数组
    for (int i = 0; i < G.v_num; i++)
        visited[i] = 0;

    cout << endl << "递归实现的深度优先遍历序列： " << endl;
    DFS(G, 0);

    // 初始化访问标记数组
    for (int i = 0; i < G.v_num; i++)
        visited[i] = 0;

    cout << endl << "非递归实现深度优先遍历序列： " << endl;
    DFS_2(G, 0);

    return 0;
}