/*
 * 878 2016
 * 有序链表的并集与去重
 *
 * 给定两个带头结点的严格降序的链表 L1 和 L2，要求你求两个链表的并集，其中元素仍然严格降序排列，且必须排除重复元素；
 * 重复的元素必须链成另一个降序排列的链表。完成去重合并后，并集链表的表头为 L1，重复元素链表的表头为 L2。
 * 例如：L1→头结点→13→10→9→5；L2→头结点→15→10→5→2。
 * 则合并后：L1→头结点→15→13→10→9→5→2；L2→头结点→10→5。
 *
 * 要求算法额外空间复杂度为O(1)，时间复杂度为O(n)。
 *
输入：
4
13 10 9 5
4
15 10 5 2

输出：
15 13 10 9 5 2
10 5
 * */

#include <iostream>
using namespace std;

// 给struct Node*起别名为PtrToNode
typedef struct Node *PtrToNode;

// 定义结构体Node, 它包含2个成员：int型的key, 指向node类型的指针Next
struct Node {
    int Key;
    PtrToNode Next;
};

// 给PtrToNode起别名为List
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

// 构造函数 声明
void ListUnion( List L1, List L2 );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Read();
    ListUnion(L1, L2);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
// 合并两个链表 并集降序并删除重复元素 重复元素单独形成一个降序链表
void ListUnion(List L1,List L2){

    // a,b为遍历两个链表的指针 temp_a、temp_b是a、b的前一个元素, 用于插入
    List a, b, temp_a, temp_b;
    a = L1->Next;
    b = L2->Next;
    temp_a = L1;
    temp_b = L2;

    // 只要ab不为空
    while(a != nullptr && b != nullptr){
        // 当b较大时
        if(a->Key < b->Key){
            // 将b取下
            temp_b->Next = b->Next;

            // 将b插到a的前面
            temp_a->Next = b;
            b->Next = a;

            // 更新b为temp_b的后一个元素 a向后移动一位
            b = temp_b ->Next;
            temp_a = temp_a->Next;
        }
        // 当ab相等时
        else if(a->Key == b->Key){
            // a、b、temp_a、temp_b均向后移动一位 重复元素在两个链表中各存在一次
            temp_a = temp_a->Next;
            a = a->Next;
            temp_b = temp_b->Next;
            b = b->Next;
        }
        // 如果a比较大时
        else if(a->Key > b->Key){
            // a向后移动
            a = a->Next;
            temp_a = temp_a->Next;
        }
    }

    if(b != nullptr){
        // cout << temp_b->Key <<endl;
        // 将b接到temp_a的后面 temp_b后面为空
        temp_a->Next = b;
        temp_b ->Next = nullptr;
    }
}