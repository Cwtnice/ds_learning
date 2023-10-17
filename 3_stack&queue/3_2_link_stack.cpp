/*
 * 链栈
 * 采用链式存储结构实现的栈，通常用单链表来表示
 * 特点是：用一组任意的存储单元存储线性表的数据元素（这组存储单元可以连续也可以不连续）
 * 不使用STL手动实现
 *
 */

#include <iostream>
using namespace std;

// 链栈
typedef struct LinkNode{
    char data;
    struct LinkNode *next;
}LNode, *LinkStack;


// 链栈的初始化：构造一个空栈S，栈顶指针置空
void LinkStack_Init(LinkStack &LS){
    LS = (LinkStack)malloc(sizeof(LinkStack));
    LS->next = nullptr;
}

// 判栈空
bool LinkStack_Is_Empty(LinkStack LS){
    if(LS->next == nullptr){
        cout << "当前栈为空！" << endl;
        return true;
    } else {
        cout << "当前栈为非空！" << endl;
        return false;
    }
}


// 打印栈
void LinkStack_Print(LinkStack LS){
    cout << "当前链栈从顶到底的元素依次为：";
    while(LS->next != nullptr){
        cout << LS->data << " ";
        LS = LS->next;
    }
    cout << endl;
}

// 入栈（不带头结点）
void LinkStack_Push(LinkStack &LS, char c){
    auto *s = (LNode*)malloc(sizeof(LNode));
    s -> data = c;
    s -> next = LS;
    LS = s;
}

//出栈（不带头结点）
void LinkStack_Pop(LinkStack &LS){
    if(LS->next == nullptr){
        cout << "当前栈空，无法出栈!" << endl;
        return;
    }
    LNode *p = LS -> next;
    free(LS);
    LS = p;
    cout << "出栈成功！" << endl;
}

// 获取链栈长度
void LinkStack_GetLength(LinkStack LS){
    int length = 0;
    while(LS->next != nullptr){
        LS=LS->next;
        length++;
    }
    cout << "栈的长度为：" << length << endl;
}


//读取栈顶元素
void LinkStack_GetTop(LinkStack LS){
    if(LS->next == nullptr){
        cout << "当前栈为空,无元素可读取!" << endl;
    } else {
        cout << "栈顶元素为：" << LS->data << endl;
    }
}



int main(){
    LinkStack LS;

    int num;

    //初始化链栈
    LinkStack_Init(LS);

    // 判断栈是否为空
    LinkStack_Is_Empty(LS);

    // 打印栈
    LinkStack_Print(LS);

    // 入栈
    string str = "algorithm";
    puts("入栈\"algorithm\"");
    for(auto s : str){
        LinkStack_Push(LS, s);
    }

    // 打印栈
    LinkStack_Print(LS);

    // 打印长度
    LinkStack_GetLength(LS);

    puts("出栈五个元素");
    for(int i = 0; i < 5; i++)
        LinkStack_Pop(LS);

    // 返回栈顶
    LinkStack_GetTop(LS);

    // 打印栈
    LinkStack_Print(LS);

    // 打印长度
    LinkStack_GetLength(LS);

    return 0;
}