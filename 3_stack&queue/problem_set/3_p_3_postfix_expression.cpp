/*
 * 后缀表达式（逆波兰表达式）求值
 * 比较简单
 *
 * 步骤：
 *      依次遍历后缀表达式的每一个字符：
 *          1.是数：直接入栈
 *          2.是操作符：数栈连续出栈2次 并进行计算（a、b的顺序不能搞错） 结果入栈
 *
 * 输入：532-4*2/+ 输出：7
 * 输入：235+*71/+4- 输出：19
 *
 */

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<int> num_s; // 数    /* NOLINT */

// 后缀表达式计算
int eval(string s){ /* NOLINT */
    for(auto c : s){
        if(isdigit(c))
            num_s.push(c - '0');// 如果是数字的话
        else{
            // 取出操作数和两个数
            auto op = c;
            int b = num_s.top(); num_s.pop();
            int a = num_s.top(); num_s.pop();

            if(op == '+') num_s.push(a+b);
            if(op == '-') num_s.push(a-b);
            if(op == '*') num_s.push(a*b);
            if(op == '/') num_s.push(a/b);
        }
    }

    return num_s.top();
}

int main(){
    cout << "请输入后缀表达式：" <<  endl;
    string postfix;
    cin >> postfix;
    cout << "后缀表达式为：" << postfix << endl;
    cout << "结果为：" << eval(postfix) << endl;

    return 0;
}