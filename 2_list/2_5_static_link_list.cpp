/*
 * 静态链表：借助数组来实现类似指针的功能
 *
 *
 */

#include <iostream>
using namespace std;

#define MaxSize 20

typedef struct SLinkNode {
    int data;
    int next;	// 下一个元素的数组下标
}SLinkList[MaxSize];

// 初始化
void static_link_list_init(SLinkList &sl){

}

int main(){
    SLinkList sl;

    return 0;
}
