/*
 * 合并两个链表
 * 1. 合并有序链表
 *      https://leetcode.cn/problems/merge-two-sorted-lists/
 *
 * 2. 交差合并链表
 *
 *
 */

#include <iostream>
using namespace std;

// 单链表结点
typedef struct LinkNode{
    int data;
    struct LinkNode *next;

    LinkNode() : data(-1), next(nullptr) {}
    explicit LinkNode(int x) : data(x), next(nullptr) {}
}LinkNode, *LinkList;

// 初始化
LinkList link_list_init(LinkList &L){
    // auto head = (LinkList)malloc(sizeof(LinkNode));
    // head->data = -1;
    // head->next = nullptr;
    L = new LinkNode();

    return L;
}

// 根据数组生成链表
LinkList link_list_init_by_array(int a[], int n){
    // 创建一个结点
    LinkList L;
    link_list_init(L);

    // 采用尾插法
    auto r = L;
    for(int i = 0; i < n; i++){
        auto p = new LinkNode(a[i]);   // 创建一个新节点

        r->next = p;
        r = r->next;
        r->next = nullptr;
    }

    return L;
}

// 打印链表
void link_list_print(LinkList L){
    printf("当前链表为： ");
    while(L != nullptr){
        printf("%d -> ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

// 返回表长 L带虚拟头结点
int link_list_length(LinkList L){
    int i = 0;
    while(L->next != nullptr){
        L = L->next;
        i++;
    }
    return i;
}

// 交差合并链表
LinkList list_merge_cross(LinkList L1, LinkList L2){
    // 新建一个链表
    LinkList L3;
    link_list_init(L3);

    auto p = L1->next, q = L2->next, r = L3;

    bool flag = false;
    while(p && q){
        // flag为0时 合并L1
        if(!flag){
            auto t = p->next;
            r->next = p;
            p = t;
            flag = true;
        }

        // flag为1时 合并L2
        else{
            auto t = q->next;
            r->next = q;
            q = t;
            flag = false;
        }

        // 更新r
        r = r->next;
        r->next = nullptr;
    }

    // 扫尾
    if(p) r->next = p;
    if(q) r->next = q;

    return L3;
}

int main(){
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    int num_a = sizeof(a) / sizeof (a[0]);
    int num_b = sizeof(b) / sizeof (b[0]);

    // 根据数组创建链表
    LinkList La = link_list_init_by_array(a, num_a);
    LinkList Lb = link_list_init_by_array(b, num_b);

    int t = 2;
    printf("请选择合并的方式：1.交叉合并链表 2.合并有序链表:");
    cin >> t;
    switch(t){
        case 1:{
            printf("交叉合并链表\n");
            LinkList Lc = list_merge_cross(La, Lb);
            link_list_print(Lc->next);
            break;
        }
        case 2:{
            printf("合并有序链表\n");
        }

        default:
            break;
    }





}