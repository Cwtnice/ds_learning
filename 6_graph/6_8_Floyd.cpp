/*
 * 图的最短路径
 * Floyd算法
 *
 * https://blog.csdn.net/weixin_44105632/article/details/120460333
 *
 *
输入:
3 5
0 1 6
0 2 13
1 2 4
1 0 10
2 0 5
 */

#include <iostream>
#include <string>

using namespace std;

#define INF 0x3f3f3f
int A[100][100];    // 邻接矩阵
int path[100][100]; // 最短路径中的第一个结点
int n, m; // n顶点数 m边数

//输出矩阵
void printData(int data[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[i][j] != INF) {
                printf("%4d", data[i][j]);
            } else printf(" INF");
        }
        printf("\n");
    }
    printf("\n");
}

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 如果通过绕行k能使距离变小
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];    // 更新当前的最短距离
                    path[i][j] = k;
                }
            }
        }
        cout << "绕行" << k  << "后的邻接矩阵" << endl;
        printData(A);
    }
}

//// path矩阵递归找到完整路径
//void find_path_2(int st,int ed){
//    if(A[st][ed]<INF && path[st][ed]==(-1)){
//        printf("->>%d",ed);
//    }
//    else{
//        int mid = path[st][ed];
//        find_path_2(st,mid);
//        find_path_2(mid,ed);
//    }
//}

// 返回v到w的最短路径
void find_path(int v, int w) {
    cout << v << "到达" << w << "的最短路径长度为：" << A[v][w] << endl;
    int k = path[v][w];
    cout << "最短路径为：" << v;
    while (k != -1) {
        printf("-> %d ", k);//打印中间点
        k = path[k][w];
    }
    printf("-> %d\n", w);
}


int main() {
    // 初始化邻接矩阵以及path数组
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i != j)
                A[i][j] = INF;
            else
                A[i][j] = 0;
            path[i][j] = -1;
        }
    }

    cout << "请输入顶点和边的信息:" << endl;
    cin >> n >> m;
    int p, q, s;
    for (int i = 0; i < m; i++) {
        cin >> p >> q >> s;
        A[p][q] = s;
    }

    cout << "初始邻接矩阵：" << endl;
    printData(A);

    Floyd();

    cout << "最终邻接矩阵：" << endl;
    printData(A);
    cout << "最终path数组：" << endl;
    printData(path);

    // 求2顶点间的最短距离
    cout << "请输入要查询最短路径的两个结点：" << endl;
    int st, ed;
    cin >> st >> ed;
    find_path(st, ed);
    return 0;
}

