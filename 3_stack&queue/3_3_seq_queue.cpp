/*
 * 顺序队列
 * 队列是一种操作受限的线性表, 只允许在队尾进行插入，而在队头删除
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MaxSize 20

// 顺序队列
typedef struct {
    char data[MaxSize];
    int front, rear;    // 首尾指针
} SqQueue;

// 初始化
void SqQueue_Init(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

// 判空
void SqQueue_Empty(SqQueue Q) {
    if (Q.front == Q.rear)
        cout << "顺序队列为空！" << endl;
    else
        cout << "顺序队列非空！" << endl;
}

// 获取队头元素
char SqQueue_Top(SqQueue Q) {
    return Q.data[Q.front];
}

// 入队
void SqQueue_Push(SqQueue &Q, char c) {
    if ((Q.rear + 1) % MaxSize == Q.front) // 队满
        return;
    Q.data[Q.rear] = c;
    Q.rear = (Q.rear + 1) % MaxSize;
}

// 出队
void SqQueue_Pop(SqQueue &Q) {
    if (Q.front == Q.rear) // 队空
        return;

    auto x = SqQueue_Top(Q);
    cout << x << "出队！" << endl;
    Q.front = (Q.front + 1) % MaxSize;
}

// 返回队列长度
int SqQueue_Length(SqQueue Q) {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}


int main() {
    SqQueue sq;
    SqQueue_Init(sq);   // 初始化
    SqQueue_Empty(sq);  // 判空

    // 入队
    string str = "algorithm";
    puts("入队\"algorithm\"");
    for (auto s : str) {
        SqQueue_Push(sq, s);
    }

    // 出队
    for (int i = 0; i < 5; i++) {
        SqQueue_Pop(sq);
    }

    cout << "当前队列长度为：" << SqQueue_Length(sq) << endl;


    return 0;
}