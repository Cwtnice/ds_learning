/*
 * 878 2019
 * 重排链表
 *
 * 给定一个非空的、至少有 2 个结点的链表 L→L1→L2→...→Ln−1→Ln
 * 要求你编写函数List Rearrange( List L ), 将链表重新排列为 L→Ln→L1→Ln−1→L2→...
 *
 * 思路：
 *  重排链表，就是将链表的后半段部分的顺序反转，然后依次插入到前半段链表的间隙中
 *  1. 把链表拆成前半段和后半段两个子链表（快慢指针）
 *  2. 把后半段的子链表顺序反转
 *  3. 将前半段链表和反转后的后半段链表按照规则合并
 *
输入：
6
1 2 3 4 5 6
输出：
6 1 5 2 4 3
 *
 * */

#include <iostream>
using namespace std;

typedef struct Node *PtrToNode;
struct Node {
    int Key;
    PtrToNode Next;
};
typedef PtrToNode List;

// 读取链表 尾插法
List Read(){
    List L = (List) malloc(sizeof(Node));
    L->Key = -1;
    L->Next = nullptr;

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        List p = (List) malloc(sizeof(Node));
        p->Key = x;
        p->Next = nullptr;

        List r = L; // 创建一个指针, 指向链表的末尾元素
        while(r->Next != nullptr)
            r = r->Next;
        r->Next = p;
    }

    return L;
}


void Print( List L ){
    if(L->Next == nullptr) printf("链表为空！");
    else{
        L = L->Next;
        while(L != nullptr){
            printf("%d ", L->Key);
            L = L->Next;
        }
    }
    printf("\n");
}

List Rearrange( List L );

int main()
{
    List L;
    L = Read();
    L = Rearrange( L );
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Rearrange( List L ){
    List p, q, r, s;
    p = q = L;

    // 1.快慢指针将链表分成2段 p为前半段的最后 q为后半段的最前
    while(q->Next != nullptr && q->Next->Next != nullptr){
        p = p->Next;    // p走一步
        q = q->Next;
        if(q->Next != nullptr)  // q走两步
            q = q->Next;
    }
    q = p->Next;
    p->Next = nullptr;

    // 2.将后半段链表逆置 这里L1是第一个结点 不是虚拟头结点了
    auto t = q;
    r = t->Next;
    while(r){
        s = r->Next;
        r->Next = t;
        t = r, r = s;
    }
    q->Next = nullptr;

    // 新建一个L1 作为第二段的虚拟头结点 也可以不要的
    List L1 = (List) malloc(sizeof(Node));
    L1->Key = -1;
    L1->Next = t;


    // 3.两段链表交差合并
    bool flag = false;  // 为true时需要进行插入
    p = L->Next, q = L1;
    while(p && q){
        // q向后移动
        if(!flag){
            q = q->Next;
            flag = true;
        }
        // 将p插入q的后面
        else{
            t = p->Next;
            p->Next = q->Next;
            q->Next = p;
            p = t;

            q = q->Next;
            flag = false;
        }
    }

    return L1;

}