/*
 * 图的邻接表存储
 *
 */

#include <iostream>
using namespace std;

#define MaxSize 100

// 边表结点
typedef struct ArcNode{
    int adjvex; // 该弧指向的定点位置
    struct ArcNode * next;  // 指向下一条弧的指针
} ArcNode;

// 顶点表结点
typedef struct VNode{
    char data;    // 存储数据
    ArcNode * firstarc;    // 指向第一条邻接边的指针
} VNode, AdjList[MaxSize];

// 图
typedef struct{
    AdjList v;
    int v_num, arc_num;
}ALGraph;

int main(){


    return 0;
}