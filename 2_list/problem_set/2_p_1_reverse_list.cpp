/*
 * 反转链表
 * AcWing 35. 反转链表
 *
 * 可以看 https://www.acwing.com/problem/content/video/33/
 */

#include <iostream>
using namespace std;

// 单链表结点
typedef struct LinkNode{
    int data;
    struct LinkNode *next;

    LinkNode() : data(-1), next(nullptr) {}
    LinkNode(int x) : data(x), next(nullptr) {} /* NOLINT */
}LinkNode, *LinkList;

// 初始化
LinkList link_list_init(LinkList &L){
    L = new LinkNode();
    return L;
}

// 打印链表
void link_list_print(LinkList L){
    while(L != nullptr){
        printf("%d -> ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

// 尾插法
void link_list_create_tail(LinkList &L, int x){
    auto p = new LinkNode(x);

    LinkList r = L; // 创建一个指针, 指向链表的末尾元素
    while(r->next != nullptr)
        r = r->next;
    r->next = p;
}

// 反转链表 递归
LinkList reverse_list(LinkList head){   /* NOLINT */
    if(!head || !head->next)
        return head;

    // 返回的是后面部分新的头结点（原先链表的最后结点）
    auto tail = reverse_list(head->next);

    // 看做head之后的结点都已实现反转
    head->next->next = head;
    head->next = nullptr;

    return tail;
}

// 反转链表 非递归(迭代思想, 循环实现)
LinkList reverse_list_2(LinkList head){
    if(!head || !head->next)
        return head;

    auto a = head, b = a->next;
    while(b){
        auto c = b->next;
        b->next = a;
        a = b, b = c;
    }

    head->next = nullptr;
    return a;
}

int main(){
    LinkList L;
    link_list_init(L);

    int a[] = {1, 2, 3, 4, 5};

    // 尾插法建立链表
    printf("原始链表：");
    for(int i : a)
        link_list_create_tail(L, i);
    link_list_print(L->next);

    printf("递归反转链表后：");
    auto head = reverse_list(L->next);
    link_list_print(head);

    printf("非递归反转链表：");
    auto new_head = reverse_list_2(head);
    link_list_print(new_head);

    return 0;
}