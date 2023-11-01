/*
 * 图的邻接矩阵存储
 *
 */

#include<iostream>
using namespace std;

#define MaxSize 100

typedef char VerTexType;  // 假设顶点为字符型
typedef int ArcType;    // 假设边的权值为整型

bool visited[MaxSize];//定义标志数组

typedef struct {
    VerTexType vex_s[MaxSize];//顶点表
    ArcType edge_s[MaxSize][MaxSize];//邻接矩阵
    int v_num, e_num;//图的当前点数和边数
}AMGraph;

// 打印领接矩阵
void adj_matrix_print(AMGraph G) {
    cout << endl << "打印邻接矩阵：" << endl;
    for (int i = 0; i < G.v_num; i++) {
        cout << G.vex_s[i] << ":";
        for (int j = 0; j < G.v_num; j++)
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
            G.edge_s[i][j] = 0;
    printf("初始化领接矩阵完毕！\n");

    // 输入边
    for (int k = 0; k < G.e_num; k++) {
        int a, b; // 定义两个顶点a, b
        printf("请输入第%d条边:", k+1);
        cin >> a >> b;

        // 确定两个顶点在定点表的下标
        G.edge_s[a][b] = G.edge_s[b][a] = 1;
    }
}

int main() {
    AMGraph G;
    adj_matrix_create(G);
    adj_matrix_print(G);
    return 0;
}
