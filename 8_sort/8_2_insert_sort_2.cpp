/*
 * 二分插入排序
 * 和直接插的区别就是在找位置这一步, 从顺序查找变为二分查找
 *
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

// 折半插入排序
void insert_sort_2(int a[], int n) {
    for (int i = 2, j; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            a[0] = a[i];    // 暂存a[i]

            // 找到插入的位置
            int low = 1, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[0] < a[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            for (j = i - 1; j >= high + 1; --j) {
                a[j + 1] = a[j];
            }

            a[high + 1] = a[0];
        }
    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};


    puts("原始序列为：");
    print_array(a, 10);

    puts("二分插入排序后：");
    insert_sort_2(a, 10);
    print_array(a, 10);

    return 0;
}
