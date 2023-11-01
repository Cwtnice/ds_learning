/*
 * 双向冒泡排序
 *
 * 在正反两个方向交替进行扫描
 * 第一趟把最大元素放到最后面，第二趟把最小元素放到最前面，反复进行
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

// 双向冒泡排序
void double_bobble_sort(int a[], int n){
    int low = 1, high = n, i, count = 0;

    while(low < high){
        bool flag = false;

        // 正向冒泡把打的冒到后面
        for(i = low; i < high; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                flag = true;    //标志， 有数据交换
            }
        }

        if(!flag){
            printf("本轮未发生交换 提前退出\n");
            break;
        }


        printf("第%d排序(正向)", ++count);
        print_array(a, 10);
        high--;

        // 反向冒泡 把小的冒到前面
        for(i = high; i > low; i-- ){
            if(a[i] < a[i-1]){
                swap(a[i], a[i-1]);
            }
        }

        printf("第%d排序(逆向)", ++count);
        print_array(a, 10);
        low++;
    }
}



int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    printf("\n双向冒泡排序：\n");
    double_bobble_sort(a, 10);

    return 0;
}