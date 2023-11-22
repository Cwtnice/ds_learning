/* Done
 * 拓扑排序
 *
 * 这里采用邻接表存储图
 * 应用于有向无环图（DAG图）
 *
 * 步骤：
 *      1.在有向图中选取一个没有前驱的顶点并输出
 *      2.从图中删除该顶点和所有以它为起点的边
 *
 *  对有向无回路图G进行拓扑排序后, 结果为该图所有顶点的一个先行序列
 *  满足如果G包含有向边<u, v>, 则在该序列中， u就出现在v的前面
 *  (如果图存在回路,就不可能存在这样的线性序列)【算法导论】
 *
 */

#include <iostream>
#include <stack>
using namespace std;

#define Max_Size 20

int in[Max_Size] = {0};   // 记录结点的入度

// 边表结点
typedef struct ENode{
    int adjvex; // 下标
    ENode* next;
}ENode;

// 顶点表结点
typedef struct VNode{
    char data;  // 值
    ENode* first;
}VNode;

// 图
typedef struct {
    VNode AdjList[Max_Size]; // 顶点表
    int v_num;
    int e_num;
}ALGraph;

// 创建邻接表
void adj_list_create(ALGraph& G){
    int i, j, k;
    ENode* e = nullptr;
    ENode* q = nullptr;

    cout << "请输入顶点数和边数: ";
    cin >> G.v_num >> G.e_num;

    cout << "请输入顶点信息: ";
    for (k = 0; k < G.v_num; k++){
        cin >> G.AdjList[k].data;
        G.AdjList[k].first = nullptr;
    }

    for (k = 0; k < G.e_num; k++){
        cout << "请输入第" << k+1 << "条边<vi,vj>的下标i,j: ";
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

// 拓扑排序
void topological_sort(ALGraph &G){
    stack<int> s;   // 栈 用于存放入度为0的顶点
    string ans;    // 用于记录拓扑排序序列
    int counts = 0; // 记录已经输出的顶点个数

    //计算各个顶点的入度
    for(int i = 0 ; i < G.v_num; i++){
        auto p = G.AdjList[i].first;
        while(p){
            in[p->adjvex]++;   //计算入度
            p = p->next;
        }
    }

    //将度为0 的顶点入栈，这里进栈的下标
    for(int i = 0; i < G.v_num; i++)
        if(in[i] == 0)
            s.push(i);

    while(!s.empty()){
        // 将栈顶的元素出栈且输出
        int t = s.top();
        s.pop();
        ans += G.AdjList[t].data;
        counts++;

        // 去掉该结点后, 更新该结点到达的其余结点的入度
        auto p = G.AdjList[t].first;  //让p指向入度为0的第一个节点
        while(p){
            int v = p->adjvex;
            if(--in[v] == 0 )
                s.push(v);
            p = p->next;
        }
    }

    // 特判 是否有环
    if(counts < G.v_num)
        ans = "图中有环, 不存在拓扑排序序列！";

    cout << ans;
}

int main(){
    ALGraph G;
    adj_list_create(G);
    adj_list_print(G);

    cout << endl << "拓扑排序序列为: " << endl;
    topological_sort(G);

    return 0;
}