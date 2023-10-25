/*
 * 栈的应用：（中缀）表达式求值
 * AcWing 3302. 表达式求值
 *
 * (2+2)*(1+1) 8
 *
 */

#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};    /* NOLINT */
stack<int> nums;    // 存数       /* NOLINT */
stack<char> ops;    // 存操作      /* NOLINT */

// 执行操作栈栈顶的操作 处理数字栈栈顶两个数
void eval(){
    // a、b的顺序不能还
    auto b = nums.top(); nums.pop();
    auto a = nums.top(); nums.pop();
    auto c = ops.top(); ops.pop();
    int x = 0;

    if(c == '+') x = a + b;
    else if(c == '-') x = a - b;
    else if(c == '*') x = a * b;
    else x = a / b;

    nums.push(x);
}

int main(){
    printf("请输入表达式：");

    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i ++ ){
        auto c = str[i];

        // 是数字
        if(isdigit(c)){
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j])){
                x = x * 10 + str[j] - '0';
                j++;
            }
            i = j - 1;  // i回到j的位置
            nums.push(x);
        }

        else if(c == '(') ops.push(c);
        else if(c == ')'){
            while(ops.top() != '(') eval();
            ops.pop();  //去掉左括号
        }

            // 普通符号
        else{
            // 当前符号优先级小于等于栈顶操作 执行栈顶操作 当前操作入栈
            while(ops.size() && pr[c] <= pr[ops.top()]) eval();     /* NOLINT */
            ops.push(c);
        }

    }

    // 剩余操作都执行完
    while(ops.size()) eval();       /* NOLINT */

    cout << nums.top() << endl;

    return 0;
}