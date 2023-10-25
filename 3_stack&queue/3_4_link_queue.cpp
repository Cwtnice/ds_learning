/*
 * 链队列（带头结点）
 *
 */

#include <iostream>
using namespace std;

// 链队列结点
typedef struct LinkNode{
    char data;
    LinkNode *next;
}LinkNode;

// 链队列
typedef struct LinkQueue{
    LinkNode *front, *rear; // 队头、队尾指针
}LinkQueue;

// 初始化
void LinkQueue_Init(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); // 创建两个指针
    Q.front->next = nullptr;
}

// 判空
void LinkQueue_Empty(LinkQueue Q) {
    if (Q.front == Q.rear)
        cout << "链队列为空！" << endl;
    else
        cout << "链队列非空！" << endl;
}

// 获取队头元素
char LinkQueue_Top(LinkQueue Q) {
    return Q.front->data;
}

// 入队 从队尾入队所以是尾插法
void LinkQueue_Push(LinkQueue &Q, char c) {
    auto *s = (LinkNode*)malloc(sizeof(LinkNode));  // 创建一个新结点并赋值
    s->data = c;
    s->next = nullptr;

    Q.rear->next = s; // 将新结点s作为队尾的后继
    Q.rear = s; // 队尾指针指向s
}

// 出队
void LinkQueue_Pop(LinkQueue &Q) {
    // 队空
    if (Q.front == Q.rear){
        puts("链队已空！");
        return;
    }

    LinkNode * p = Q.front->next;
    cout << p->data << "出队！" << endl;
    Q.front->next = p->next;

    if(Q.rear == p) Q.rear = Q.front;   // 若队列中只有一个结点 删除后变空

    free(p);
}

// 遍历输出队列
void LinkQueue_Print(LinkQueue Q){
    printf("遍历输出队列：虚拟头结点->");
    LinkNode *p =Q.front->next;
    while (p){
        printf("%c->", p->data);
        p = p->next;
    }
    cout << "NULL" << endl;
}


int main(){
    LinkQueue lq;
    LinkQueue_Init(lq); // 初始化
    LinkQueue_Empty(lq); // 判空

    // 入队
    string str = "algorithm";
    puts("入队\"algorithm\"");
    for (auto s : str) {
        LinkQueue_Push(lq, s);
    }

    // 打印队列
    LinkQueue_Print(lq);

    // 出队
    for (int i = 0; i < 5; i++) {
        LinkQueue_Pop(lq);
    }

    // 打印队列
    LinkQueue_Print(lq);

    return 0;
}