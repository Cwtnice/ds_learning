/*
 * 栈的应用：中缀表达式转后缀表达式
 *
 * （后缀表达式中没有括号）
 *
 * 步骤：
 *      依次遍历中缀表达式的每一个字符：
 *          1.是数：直接加入后缀表达式
 *          2.是左括号：直接入栈，左括号优先级最低
 *          3.是右括号：栈顶元素出栈加入后缀表达式，直到遇到左括号为止。左括号出栈但不加入后缀表达式，也就是说当栈顶是左括号时多出栈一次
 *          4.是运算符：
 *              只有 栈非空 且 当前运算符优先级小于栈顶运算符 时，出栈加入后缀表达式
 *              其余情况当前元素入栈
 *      最后要扫尾
 *
 *
 *
 * 输入:5+(3-2)*4/2 输出:532-4*2/+
 * 输入:2*(3+5)+7/1-4 输出:235+*71/+4-
 */

#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>
using namespace std;

const int maxn = 10000;

// 中缀转后缀
string infix_to_postfix(string infix){  /* NOLINT */
    stack<char> op_s;
    string postfix;

    unordered_map<char, int> priority;  // 左括号的优先级就是0
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;

    for(char c : infix){
        if(isalnum(c))  // 如果是数字
            postfix += c;
        else if(c == '(')   // 左括号入栈
            op_s.push(c);
        else if(c == ')'){  // 右括号
            while(!op_s.empty() && op_s.top() != '('){
                postfix += op_s.top();
                op_s.pop();
            }
            if(!op_s.empty() && op_s.top() == '(')
                op_s.pop();
        }
        else{   // 运算符
            while(!op_s.empty() && priority[c] <= priority[op_s.top()]){    // 栈非空且当前运算符优先级小于栈顶元素优先级
                postfix += op_s.top();
                op_s.pop();
            }
            op_s.push(c);   // 当前运算符入栈
        }

    }

    // 将栈中剩余的运算符都加入后缀表达式 5+(3-2)*4/2
    while(!op_s.empty()){
        postfix += op_s.top();
        op_s.pop();
    }

    return postfix;
}

int main(){
    cout << "请输入前缀表达式：" <<  endl;
    string infix;
    cin >> infix;
    cout << "前缀表达式为：" << infix << endl;
    cout << "后缀表达式为：" << infix_to_postfix(infix) << endl;

    return 0;
}

