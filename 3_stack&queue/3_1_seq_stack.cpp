/*
 * 顺序栈
 * 顺序栈是用顺序存储结构实现的栈, 利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素
 * 不使用STL手动实现
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 20

// 顺序栈结构体
typedef struct{
    char data[MaxSize];	// 存放元素
    int top;	// 栈顶指针
}SeqStack;	// 顺序栈

// 顺序栈初始化
void SeqStack_Init(SeqStack &st){
    st.top = -1;
}

// 判栈空
bool SeqStack_Is_Empty(SeqStack st){
    if(st.top == -1)
        return true;
    return false;
}

// 返回栈顶元素
char SeqStack_Get_Top(SeqStack st){
    return st.data[st.top];
}

// 打印栈
char SeqStack_Print(SeqStack st){
    printf("栈内元素自顶向下为:");
    for(int i = st.top; i > -1; i--){
        printf(" %c ", st.data[i]);
    }
    puts("");
}

// 入栈
void SeqStack_Push(SeqStack &st, char c){
    if(st.top == MaxSize - 1){  // 栈满条件
        puts("栈已满, 停止入栈！");
        return;
    }
    st.data[++st.top] = c;
}

// 出栈
void SeqStack_Pop(SeqStack &st){
    if(st.top == -1) {    // 栈空条件
        puts("栈已空, 无法出栈！");
        return;
    }
    else
        printf("%c 出栈！", st.data[st.top--]);
    puts("");
}

int main(){
    SeqStack st;
    SeqStack_Init(st);  // 初始化
    printf("栈顶指针为：%d, 栈最大容量为：%d\n", st.top, MaxSize);

    if(SeqStack_Is_Empty(st))
        puts("顺序栈为空！");
    else
        puts("顺序栈非空！");

    // 打印栈
    SeqStack_Print(st);

    // 入栈
    string str = "algorithm";
    puts("入栈\"algorithm\"");
    for(auto s : str){
        SeqStack_Push(st, s);
    }

    // 打印栈
    SeqStack_Print(st);

    puts("出栈五个元素");
    for(int i = 0; i < 5; i++)
        SeqStack_Pop(st);

    // 打印栈
    SeqStack_Print(st);

    printf("栈顶指针为：%d, 栈最大容量为：%d\n", st.top, MaxSize);

    return 0;
}