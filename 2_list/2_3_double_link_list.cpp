/*
 * 双链表：和单链表的区别就是多了一个前驱指针
 *
 * 关注：
 *      头插法（需要特判）
 *      插入元素
 *      删除元素
 *
 */

#include <iostream>
using namespace std;

// 双链表结点
typedef struct DLinkNode{
    int data;
    struct DLinkNode *prior, *next; // 和单链表比多了一个前驱指针

    DLinkNode() : data(-1), prior(nullptr), next(nullptr) {}
    explicit DLinkNode(int x) : data(x), prior(nullptr), next(nullptr) {}
}DLinkNode, *DLinkList;


// 初始化
DLinkList double_link_list_init(DLinkList &L){
    L = new DLinkNode();
    puts("双链表初始化完成");

    return L;
}

// 打印链表
void double_link_list_print(DLinkList L){
    printf("当前链表为： ");
    while(L != nullptr){
        printf("%d -> ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

// 返回表长
int double_link_list_length(DLinkList L){
    int i = 0;
    while(L->next != nullptr){
        L = L->next;
        i++;
    }
    return i;
}

// 清空链表
void double_link_list_drop(DLinkList &L){
    L->next = nullptr;
    puts("清空链表！");
}

// 头插法
void double_link_list_create_head(DLinkList &L, int x){
    auto p = new DLinkNode(x);   // 创建一个新节点

    // 如果只有头结点 为什么要区分呢？因为null不会有prior
    if(L->next == nullptr){
        p->next = nullptr;
        p->prior = L;
        L->next = p;
    }
    else{
        p->next = L->next;
        L->next->prior = p;

        L->next = p;
        p->prior = L;
    }
}

// 尾插法
void double_link_list_create_tail(DLinkList &L, int x){
    auto p = new DLinkNode(x);

    DLinkList r = L; // 创建一个指针, 指向链表的末尾元素
    while(r->next != nullptr)
        r = r->next;

    r->next = p;
    p->prior = r;
}

// 在第i个位置上插入元素
void double_link_list_insert(DLinkList &L, int idx, int x){
    if(double_link_list_length(L) < idx){
        printf("插入位置的设置不合法！");
        return;
    }

    // 找到第i个元素的前驱p
    DLinkList p = L;
    for(int i = 1; i < idx; i++)
        p = p->next;

    auto q = new DLinkNode(x);   // 创建一个新节点q

    q->next = p->next;
    q->next->prior = q;

    p->next = q;
    q->prior = p;
}

// 删除第i个位置上的结点
void double_link_list_delete(DLinkList &L, int idx){
    if(double_link_list_length(L) < idx){
        printf("删除位置的设置不合法！");
        return;
    }

    // 找到第i个元素的前驱p
    DLinkList p = L;
    for(int i = 1; i < idx; i++)
        p = p->next;

    // q为需要删除的结点
    auto q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

// 按值查找 返回下标
int double_link_list_search(DLinkList L, int x){
    DLinkList p = L;
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
    DLinkList L;
    double_link_list_init(L);

    int a[] = {3, 4, 7, 2, 1, 8, 4, 7, 5};

    // 头插法建立链表
    puts("头插法");
    for(int i : a)
        double_link_list_create_head(L, i);
    double_link_list_print(L->next);

    double_link_list_drop(L);

    // 尾插法建立链表
    puts("尾插法");
    for(int i : a)
        double_link_list_create_tail(L, i);
    double_link_list_print(L->next);

    int idx;
    printf("需要删除的元素位置：");
    cin >> idx;
    double_link_list_delete(L, idx);
    double_link_list_print(L->next);

    int t;
    printf("需要插入的元素位置：");
    cin >> idx;
    printf("需要插入的元素的值：");
    cin >> t;
    double_link_list_insert(L, idx, t);
    double_link_list_print(L->next);

    printf("需要查找的元素的值：");
    cin >> t;
    printf("该元素的下标为：%d", double_link_list_search(L, t));

    return 0;
}