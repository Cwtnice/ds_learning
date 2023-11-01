/*
 * 改进的快速排序
 *
 * 快速排序的关键在于选取基准pivot，当pivot不能处在一个中间位置时（例如当序列基本有序或者逆序，基准选第一个），快排效率会很差
 * 改进的思路：
 *      1.a[l], a[mid], a[r]选择中位数作为pivot
 *      2.划分3部分：小于，等于，大于
 *      3.利用栈消除递归
 *
 *
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

// 返回三个数的中位数 把最大的放到c 最小的放到a
int get_mid(int a, int b, int c){
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);

    return b;
}

// 一趟划分, 返回最终pivot的位置
// 我的理解是, 先将pivot取出来, 序列中始终有一个空位, 利用双指针不断将值和空位进行交换, 最终确定pivot的正确位置将pivot填入
int Partition(int a[], int low, int high) {
    int pivot = get_mid(a[low], a[high], a[(low + high) / 2]); // TODO 区别在这

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

    printf("改进快排后：");
    print_array(a, 10);


    return 0;
}