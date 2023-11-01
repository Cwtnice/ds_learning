/*
 * 直接插入排序
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


// 直接插入排序
void insert_sort(int a[], int n) {
    // 从第二位开始
    for (int i = 2, j; i <= n; i++) {
        // 如果比前一位小
        if (a[i] < a[i - 1]) {
            a[0] = a[i];    // 暂存a[i]

            // 找到插入的位置
            for (j = i - 1; j > 0 && a[0] < a[j]; j--)
                a[j + 1] = a[j];  // 依次右移

            // 插入
            a[j + 1] = a[0];
        }
    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};

    puts("原始序列为：");
    print_array(a, 10);

    puts("直接插入排序后：");
    insert_sort(a, 10);
    print_array(a, 10);

    return 0;
}
