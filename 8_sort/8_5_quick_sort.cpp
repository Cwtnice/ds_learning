/*
 * 快速排序
 *
 * 属于交换类的排序
 * 基于分治, 关键在于划分, 一趟划分能确定pivot的位置(比它小的都在左边, 比它大的都在右边)
 * TODO 要多看看手动模拟便于理解
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

// 一趟划分, 返回最终pivot的位置
// 我的理解是, 先将pivot取出来, 序列中始终有一个空位, 利用双指针不断将值和空位进行交换, 最终确定pivot的正确位置将pivot填入
int Partition(int a[], int low, int high) {
    int pivot = a[low]; // pivot可以选择左边界、右边界或者中点

    // 将比pivot小的元素都移动到左端, 比pivot大的都移动到右端
    while (low < high) {
        // 右指针移动到值比pivot小的元素的时候, 将a[high]填到a[low]的位置（a[low]已经作为pivot, 暂存了）
        while (low < high && a[high] >= pivot) --high;
        a[low] = a[high];
        // 左边也是同理
        while (low < high && a[low] <= pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot; // 将pivot放到最终位置
    return low;
}

// 快速排序
void quick_sort(int a[], int low, int high) {   /* NOLINT */
    if (low < high) {   // 递归出口
        // 枢轴的位置
        int pivot_pos = Partition(a, low, high);

        // 递归两个子区间
        quick_sort(a, low, pivot_pos);
        quick_sort(a, pivot_pos + 1, high);

    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    quick_sort(a, 1, 10);

    printf("快排后序列：");
    print_array(a, 10);

    return 0;
}