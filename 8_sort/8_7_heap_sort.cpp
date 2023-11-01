/*
 * 堆排序
 *
 * 使用数组存储堆
 *
 * 属于选择类的排序
 * 描述：
 *      1.未排序序列组成大根堆, 调整后将根和最后元素进行交换，此时最后元素已经确定了最终位置，未排序序列长度减一
 *      2.重复以上过程, n-1趟后完成排序
 * 每趟排序使得一个元素确定其最终位置, 进行n-1趟后完成排序
 * 从后往前逐渐形成有序序列
 *
 * 时间复杂度O(logn)
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

// 堆排序
void HeapSort(int a[], int len) {
    // 建立大顶堆
    BuildMaxHeap(a, len);
    printf("0先调整为大顶堆：");
    print_array(a, 10);

    // n-1趟交换和调整为堆的过程
    for (int i = len; i > 1; i--) {
        // 输出堆顶（和堆底元素交换, 加入完成排序的序列）
        swap(a[1], a[i]);

        printf("第%d趟排序的结果：", len - i + 1);  // TODO 这一趟的结果是在下一趟调整前还是后？
        print_array(a, 10);

        // 将未排序序列 a[1, i-1]调整为堆
        HeapDown(a, 1, i - 1);

    }
}


int main(){
    // int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    int a[11] = {0, 2, 3, 8, 1, 4, 9, 10, 7, 16, 14};
    printf("原始序列：");
    print_array(a, 10);

    puts("开始堆排序：");
    HeapSort(a, 10);

    return 0;
}