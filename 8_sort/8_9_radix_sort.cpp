/*
 * 基数排序（桶排序）
 * 基于关键字各位的大小
 *
 *
 */

#include <iostream>
using namespace std;

// 临时数组
int tmp[11];

// 打印数组
void print_array(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        if(i == 1) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
}


// 求数组中最大值元素的位数d d决定排序次数
int MaxBit(int a[], int n) {
    int d = 1;
    int p = 10;
    for (int i = 1; i <= n; i++) {
        while (a[i] >= p) {
            p *= 10;
            d++;
        }
    }
    return d;
}

//基数排序 下标从1到10
void radix_sort(int data[], int n) {
    int d = MaxBit(data, n);    // 计算排序次数
    int count[10];  //计数器
    int i, j, k;
    int radix = 1;

    // 进行d次排序
    for (i = 1; i <= d; i++) {
        // 每次分配前清空计数器
        for (j = 0; j < 10; j++)
            count[j] = 0;

        // 十个桶0~9 桶里面装的不是数据本身 而是每一轮（十、百、千...）排序对应位的个数
        for (j = 0; j < n; j++) {
            k = (data[j + 1] / radix) % 10;
            count[k]++;
        }

        // 将桶里面的元素依次累加起来，就可以知道元素存放在临时数组中的位置
        for (j = 0; j < 10; j++)
            count[j] = count[j - 1] + count[j];

        // 将所有桶中记录依次收集到tmp中
        // 例如14 count[4] = 6 说明了在本轮排序中 14前面有5个元素 他的下标是6
        for (j = n - 1; j >= 0; j--) {
            k = (data[j + 1] / radix) % 10;
            tmp[count[k]] = data[j + 1];
            count[k]--;     // 处理同一个桶中的不同元素
        }
        for (j = 1; j <= n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;

        printf("第%d趟排序的结果：", i);
        print_array(data, 10);
    }
}


int main(){
    int a[11] = {0, 73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    printf("原始序列为：");
    print_array(a, 10);

    radix_sort(a, 10);

    return 0;
}