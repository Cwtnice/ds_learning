/*
 * 堆
 *
 */

#include <iostream>
using namespace std;

// 打印数组
void print_array(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        if(i == 1)
            cout << a[i];
        else
            cout << " " << a[i];
    }
    cout << endl;
}

// 将以k为根的子树调整为堆 向下调整
void HeapDown(int a[], int k, int len) {
    // a[0] 暂存根结点
    a[0] = a[k];

    // 沿key较大的子结点向下筛选
    for (int i = 2 * k; i <= len; i *= 2) {
        // 如果右孩子的值更大, 就走右边
        if (i < len && a[i] < a[i + 1])
            i++;

        // 筛选结束
        if (a[0] >= a[i]) break;
        else {
            // 将a[i]的值换到双亲结点上, 修改k的值, 方便向下筛选
            a[k] = a[i];
            k = i;
        }
    }
    // 循环结束时k的位置就是根节点该存放的位置
    a[k] = a[0];
}

// 建立大顶堆: 从 len/2 (最后一个有孩子的结点)往前反复调整堆 O(N)建堆
void BuildMaxHeap(int a[], int len) {
    for (int i = len / 2; i > 0; i--)
        HeapDown(a, i, len);
}


int main(){
    // int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    int a[11] = {0, 2, 3, 8, 1, 4, 9, 10, 7, 16, 14};
    printf("原始序列：");
    print_array(a, 10);

    puts("将数组调整为大顶堆：");
    BuildMaxHeap(a, 10);
    print_array(a, 10);

    return 0;
}