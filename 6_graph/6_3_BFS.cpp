/*
 * 广度优先遍历
 *
 * 这里是有向图 用的是邻接表
 * BFS序列在邻接表情况下会唯一
 *
 * 可以看：https://blog.csdn.net/smart_jackli/article/details/127917964
 */

#include<iostream>
#include<queue>
using namespace std;

#define MAX 10
int visited[MAX];   // 访问标记数组

// 边表结点
typedef struct ENode{
    int adjvex;
    ENode* next;
}ENode;

// 顶点表结点
typedef struct VNode{
    char data;
    ENode* first;
}VNode;

// 图
typedef struct {
    VNode AdjList[MAX]; // 顶点表
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

// 广度有限遍历图
void BFS(ALGraph G, int v) {
    queue<int> Q;   // 需要一个队列

    // 访问当前结点
    cout << G.AdjList[v].data << " ";
    visited[v] = 1;
    Q.push(v);

    // 只要队列为空
    while (!Q.empty()) {
        // 取出队头
        v = Q.front();
        Q.pop();

        // 遍历v的所有临界点w
        ENode* p = G.AdjList[v].first;
        while(p){
            auto w = p->adjvex;
            if (visited[w] == 0){   // 如果w未被访问
                cout << G.AdjList[w].data << " ";
                visited[w] = 1;
                Q.push(w);
            }
            p = p->next;
        }
    }
}

int main() {
    ALGraph G;
    adj_list_create(G);
    adj_list_print(G);

    // 初始化
    for (int i = 0; i < G.v_num; i++)
        visited[i] = 0;

    cout << endl << "广度优先遍历序列： " << endl;
    BFS(G, 0);

    return 0;
}