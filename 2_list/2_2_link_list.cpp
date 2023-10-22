/*
 * 链表（单链表）：顺序表的链式存储实现
 *
 * 关注：
 *      初始化
 *      头插法
 *      尾插法
 *      插入元素
 *      删除元素
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
    puts("单链表初始化完成");

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

// 返回表长
int link_list_length(LinkList L){
    int i = 0;
    while(L->next != nullptr){
        L = L->next;
        i++;
    }
    return i;
}

// 清空链表
void link_list_drop(LinkList &L){
    L->next = nullptr;
    puts("清空链表！");
}

// 头插法
void link_list_create_head(LinkList &L, int x){
    auto p = new LinkNode(x);   // 创建一个新节点

    p->next = L->next;
    L->next = p;
}

// 尾插法
void link_list_create_tail(LinkList &L, int x){
    auto p = new LinkNode(x);

    LinkList r = L; // 创建一个指针, 指向链表的末尾元素
    while(r->next != nullptr)
        r = r->next;
    r->next = p;
}

// 在第i个位置上插入元素
void link_list_insert(LinkList &L, int idx, int x){
    if(link_list_length(L) < idx){
        printf("插入位置的设置不合法！");
        return;
    }

    // 找到第i个元素的前驱p
    LinkList p = L;
    for(int i = 1; i < idx; i++)
        p = p->next;

    auto q = new LinkNode(x);   // 创建一个新节点q
    q->next = p->next;
    p->next = q;
}

// 删除第i个位置上的结点
void link_list_delete(LinkList &L, int idx){
    if(link_list_length(L) < idx){
        printf("删除位置的设置不合法！");
        return;
    }

    // 找到第i个元素的前驱p
    LinkList p = L;
    for(int i = 1; i < idx; i++)
        p = p->next;

    // q为需要删除的结点
    auto q = p->next;
    p->next = q->next;
    free(q);
}

// 按值查找 返回下标
int link_list_search(LinkList L, int x){
    LinkList p = L;
    int ans = 0;
    while(p->next != nullptr){
        if(p->data == x)
            return ans;
        else{
            p = p->next;
            ans++;
        }
    }
    return -1;
}

int main(){
    LinkList L;
    link_list_init(L);

    int a[] = {3, 4, 7, 2, 1, 8, 4, 7, 5};

    // 头插法建立链表
    puts("头插法");
    for(int i : a)
        link_list_create_head(L, i);
    link_list_print(L->next);

    link_list_drop(L);

    // 尾插法建立链表
    puts("尾插法");
    for(int i : a)
        link_list_create_tail(L, i);
    link_list_print(L->next);

    int idx;
    printf("需要删除的元素位置：");
    cin >> idx;
    link_list_delete(L, idx);
    link_list_print(L->next);

    int t;
    printf("需要插入的元素位置：");
    cin >> idx;
    printf("需要插入的元素的值：");
    cin >> t;
    link_list_insert(L, idx, t);
    link_list_print(L->next);

    printf("需要查找的元素的值：");
    cin >> t;
    printf("该元素的下标为：%d", link_list_search(L, t));

    return 0;
}