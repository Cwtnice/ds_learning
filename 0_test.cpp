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

int partition(int a[], int l, int r){
    int pivot = a[l];

    while(l < r){
        while(l < r && a[r] >= pivot) r--;
        a[l] = a[r];
        while(l < r && a[l] < pivot) l++;
        a[r] = a[l];
    }

    a[l] = pivot;
    return l;
}

void quick_sort(int a[], int l, int r){
    if(l < r){
        int pivot_pos = partition(a, l, r);

        quick_sort(a, l, pivot_pos);
        quick_sort(a, pivot_pos + 1, r);
    }

}


int main(){
    int a[11] = {0, 6, 7, 3, 5, 1, 4, 9, 8, 2, 10};
    printf("原始序列为：");
    print_array(a, 10);

    quick_sort(a, 1, 10);

    printf("快排后序列：");
    print_array(a, 10);

    return 0;
}