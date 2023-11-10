/*
 * 计数排序
 *
 * 对于每个元素 统计其他比它小的元素的个数 假如数组中有3个元素比a小 那么a的正确位置就是第4个
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

// 计数排序
// 实际上每两个元素会比较2次 比较次数n(n-1)
void count_sort(int a[], int n){
    int b[11];  // b用来暂存

    for(int i = 1; i <= n; i++){

        // 找到比a[i]小的元素个数
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            if(a[j] < a[i])
                cnt++;
        }
        b[cnt + 1] = a[i];
    }

    // 放回到a
    for(int i = 1; i <= n; i++)
        a[i] = b[i];
}


// 改进的计数排序
// 任意两个元素只要比较一次 比较次数降为n(n-1)/2
int count[11];
void count_sort_2(int a[], int n){
    int b[11];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(a[j] < a[i])
                count[i]++;
            if(a[j] > a[i])
                count[j]++;
        }
    }

    for(int i = 1; i <= n; i++)
        b[count[i] + 1] = a[i];

    for(int i = 1; i <= n; i++)
        a[i] = b[i];
}

int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    count_sort(a, 10);
    printf("计数排序后：");
    print_array(a, 10);

    int b[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    count_sort_2(b, 10);
    printf("改进计排后：");
    print_array(b, 10);
    printf("count数组：");
    print_array(count, 10);

    return 0;
}