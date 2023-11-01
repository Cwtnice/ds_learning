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
    for(int i = 2, j; i <= n; i++){
        if(a[i] < a[i - 1]){
            a[0] = a[i];

            for(j = i - 1; j >= 1 && a[j] > a[0]; j--)
                a[j + 1] = a[j];

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