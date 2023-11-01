/*
 * 最小生成树 prim算法
 * 这里用邻接矩阵，带权图
 *
 * 每次将离连通部分的最近的点和点对应的边加入的连通部分，连通部分逐渐扩大，最后将整个图连通起来，并且边长之和最小。
 *
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MaxSize 100
const int INF = 0x3f3f3f;


int dist[MaxSize];  // 记录顶点到集合的最短距离
int pre[MaxSize];   // 记录顶点的前驱结点
bool st[MaxSize];   // 记录顶点是否在集合中

// 图的结构体
typedef struct {
    char vex_s[MaxSize]; // 顶点表
    int edge_s[MaxSize][MaxSize];   // 邻接矩阵
    int v_num, e_num;   //顶点数 边数
} AMGraph;

// 打印领接矩阵
void adj_matrix_print(AMGraph G) {
    cout << endl << "打印邻接矩阵：" << endl;
    for (int i = 0; i < G.v_num; i++) {
        cout << G.vex_s[i] << ":";
        for (int j = 0; j < G.v_num; j++)
            if(G.edge_s[i][j] == INF)
                cout << "INF ";
            else
                cout << G.edge_s[i][j] << " ";
        cout << endl;
    }
}

// 采用邻接矩阵表示法建图 无向图就是两个方向都有边的有向图
void adj_matrix_create(AMGraph& G) {
    printf("请输入图的顶点总数和边总数:");
    cin >> G.v_num >> G.e_num;

    printf("请依次输入点的信息:");
    for (int i = 0; i < G.v_num; i++)
        cin >> G.vex_s[i];

    for (int i = 0; i < G.v_num; i++)
        for (int j = 0; j < G.v_num; j++)
            G.edge_s[i][j] = INF;
    printf("初始化领接矩阵完毕！\n");

    // 输入边
    for (int k = 0; k < G.e_num; k++) {
        int a, b, c; // 边<a, b> 权值c
        printf("请输入第%d条边:", k+1);
        cin >> a >> b >> c;

        // 确定两个顶点在定点表的下标
        G.edge_s[a][b] = G.edge_s[b][a] = c;
    }
}

// 最小生成树 prim算法 以u为起点
void prim(AMGraph &G, int u){


}

int main(){
    AMGraph G;
    adj_matrix_create(G);
    adj_matrix_print(G);

    puts("");
    puts("采用prim算法求最小生成树:");
    prim(G, 0);

    return 0;
}