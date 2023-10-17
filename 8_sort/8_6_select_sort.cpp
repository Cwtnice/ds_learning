/*
 * 简单选择排序
 * 属于选择类的排序
 * 描述：每次从未排序序列中选择最小的元素和未排序序列的第一个元素交换
 * 每趟排序使得一个元素确定其最终位置, 进行n-1趟后完成排序
 * 从前往后逐渐形成有序序列
 */

#include <iostream>
using namespace std;


// 打印数组
void print_array(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        if(i == 1) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
}

// 简单选择排序
void select_sort(int a[], int n) {
    // 循环n-1次
    for (int i = 1; i <= n - 1; i++) {

        // 找到未排序序列中的最小元素的下表
        int min = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        // 将最小元素和第一个元素交换
        if (min != i) swap(a[i], a[min]);

        printf("第%d趟排序的结果：", i);
        print_array(a, 10);
    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    puts("开始简单选择排序：");
    select_sort(a, 10);

    return 0;
}
