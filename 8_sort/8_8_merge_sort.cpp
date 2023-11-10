/*
 * 二路归并排序
 *
 * 是基于比较的排序
 * 将2个有序表组合成一个新的有序表，也是基于分治的
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

// 临时数组
int tmp[11];

// 二路归并排序
void merge_sort(int a[], int l, int r) {    /* NOLINT */
    // 递归出口
    if (l >= r) return;

    int mid = (l + r) / 2;

    // 递归两个子区间
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);

    // k是辅助数组的下标 ij是双指针
    int k = 0, i = l, j = mid + 1;

    // 每次选两个数组中当前更小的元素加入tmp中
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }

    // 扫尾 两个数组只会有一个剩下的
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    // 将元素从tmp中拿回来
    for (int i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];

}

int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    merge_sort(a, 1, 10);
    printf("排序后序列：");
    print_array(a, 10);

    return 0;
}