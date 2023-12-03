/*
 * 输出变量的类型
 *
 * */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int *p[3], a[3];

    cout << "a的类型：" << typeid(a).name() << endl;
    cout << "a[0]的类型：" << typeid(a[0]).name() << endl;
    cout << "p的类型：" << typeid(p).name() << endl;
    cout << "*p的类型：" << typeid(*p).name() << endl;
}