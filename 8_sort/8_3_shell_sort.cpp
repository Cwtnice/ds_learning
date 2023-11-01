/*
 * 希尔排序
 * 分组进行直接插入排序
 *
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

// 希尔排序
void shell_sort(int a[], int n) {
    // 步长一般初始为n/2
    for (int dk = n / 2; dk >= 1; dk /= 2) {
        // 组内做直接插入排序
        for (int i = 1 + dk, j; i <= n; i++) {
            // 如果比同组前一个小
            if (a[i] < a[i - dk]) {
                a[0] = a[i];

                // 找到插入的位置
                for (j = i - dk; j > 0 && a[0] < a[j]; j -= dk) {
                    a[j + dk] = a[j];   // 依次右移
                }

                // 插入
                a[j + dk] = a[0];
            }
        }
    }
}

// 希尔排序分步展示
void shell_sort_step(int a[], int n) {
    puts("希尔排序分步开始");
    printf("原始字符串为   : ");
    print_array(a, 10);

    int i = 0;
    // 步长
    for (int dk = n / 2; dk >= 1; dk /= 2) {
        printf("第%d步, 步长为%d : ", ++i, dk);
        // 里面做直接插入排序
        for (int i = 1 + dk, j; i <= n; i++) {
            // 如果比同组前一个小
            if (a[i] < a[i - dk]) {
                a[0] = a[i];

                for (j = i - dk; j > 0 && a[0] < a[j]; j -= dk) {
                    a[j + dk] = a[j];
                }

                // 插入
                a[j + dk] = a[0];
            }
        }
        print_array(a, 10);
    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};


    puts("原始序列为：");
    print_array(a, 10);

    puts("希尔排序后：");
    shell_sort(a, 10);
    print_array(a, 10);


    puts("--------------------");
    int b[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    shell_sort_step(b, 10);


    return 0;
}
