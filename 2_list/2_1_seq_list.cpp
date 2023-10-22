/*
 * 顺序表：线性表的顺序存储实现
 *
 *
 */

#include <iostream>
using namespace std;

#define MaxSize 10

// 顺序表结构
typedef struct {
    char data[MaxSize];  // 存储空间
    int length; // 表长
}SeqList;

// 顺序表初始化
void seq_list_init(SeqList &L){
    L.length = 0;
    printf("顺序表初始化完成！\n");
}

// 按值查找元素 返回下标
int seq_list_find(SeqList &L, int x){
    for(int i = 0; i < L.length; i++)
        if(L.data[i] == x) return i;
    return -1;
}

// 表长
void sel_list_length(SeqList &L){
    printf("当前顺序表的表长为：%d\n", L.length);
}

// 插入元素
void seq_list_insert(SeqList &L, char x){
    L.data[L.length++] = x;
}

// 删除元素
void seq_list_delete(SeqList &L, char x){
    int pos = seq_list_find(L, x);
    if(pos== -1){
        printf("顺序表中不存在元素：%c", x);
        return;
    }
    else{
        printf("%c的下标为：%d\n", x, pos);

        // 将它之后的元素前移 并且有效长度减一
        for(int i = pos; i < L.length - 1; i++)
            L.data[i] = L.data[i + 1];
        L.length--;
    }
}

// 打印顺序表
void seq_list_print(SeqList L){
    cout << "目前顺序表为：";
    if (L.length == 0)
        cout << "空表！";
    for (int k = 0; k < L.length; k++)
        cout << L.data[k] << " ";
    cout << endl;
}

int main(){
    SeqList L;
    seq_list_init(L);   // 初始化

    // 插入
    string str = "algorithm";
    puts("顺序表依次插入\"algorithm\"");
    for (auto s : str) {
        seq_list_insert(L, s);
    }

    seq_list_print(L);  // 打印

    sel_list_length(L); // 表长

    // 查找
    printf("查找字符g的下标: %d\n", seq_list_find(L, 'g'));

    // 删除
    puts("删除字符i");
    seq_list_delete(L, 'i');

    seq_list_print(L); // 打印

    sel_list_length(L); // 表长

    return 0;
}