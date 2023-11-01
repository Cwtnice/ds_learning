/*
 * 冒泡排序
 *
 * 属于交换类的排序
 * 一趟冒泡：从前往后（或从后往前）两两比价相邻元素, 如果是逆序就进行交换
 * 一趟冒泡效果：将未排序序列中最大的元素放到它的正确位置（加入已排序序列）, 已完成排序的元素不参与下一趟冒泡
 *  最多需要n-1趟冒泡将所有元素排序完成
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

// 冒泡排序 将大的冒到后面 从后往前逐渐形成有序序列
void bobble_sort(int a[], int n){
    // 总共n-1趟冒泡 i的位置就是有序序列的开始
    for(int i = n; i > 1; i-- ){
        bool flag = false;  // 本轮是否发生交换的标志
        printf("第%d趟冒泡：", n - i + 1);

        // 一趟冒泡 将未排序序列中的最大元素冒到后面
        for(int j = 1; j <= i - 1; j++ ){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }

        print_array(a, 10);

        if(!flag){
            puts("本轮未发生交换 说明序列已经全部有序, 无需继续, 提前退出");
            return;
        }
    }
}

int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    bobble_sort(a, 10);

    return 0;
}