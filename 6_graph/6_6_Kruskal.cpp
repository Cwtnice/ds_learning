/*
 * 最小生成树 Kruskal算法
 * AcWing 859. Kruskal算法求最小生成树
 *
 */

/*
输入：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4

输出：
6
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200010;
int n, m;   // n顶点数 m边数
int p[maxn];    // 并查集

// 用结构体来存储边
struct Edge{
    int a, b, w;    // 左右端点和权值

    // 重载小于号 方便按权值大小排列
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[maxn];

// 并查集的find
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;

    // 读入m条边
    for(int i = 0; i < m; i++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    // 边按权值从小到大排序
    sort(edges, edges + m);

    // 初始化并查集
    for(int i = 1; i <= n; i++ ) p[i] = i;

    int res = 0, cnt = 0;   // res最小生成树的权值 cnt当前集合中结点数

    // 枚举每条边
    for(int i = 0; i < m; i++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        // 如果a和b不连通 将b和该边加入集合
        if(a != b){
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if(cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}