/*
 * 栈的应用：括号匹配
 * AcWing 3693. 括号匹配
 *
 * (){} yes
 * (()[{]}) no
 * ( no
 */

#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;    /* NOLINT */
string str;

int main(){
    printf("请输入表达式：");
    cin >> str;

    for(char op : str){
        // 当前是左括号就入栈
        if(op == '<' || op == '(' || op == '{' || op == '[')
            stk.push(op);
        else{
            if(stk.empty()){
                cout << "no" << endl;
                return 0;
            }
            if(op == '>' && stk.top() == '<') stk.pop();    /* NOLINT */
            else if(op == ')' && stk.top() == '(') stk.pop();
            else if(op == '}' && stk.top() == '{') stk.pop();
            else if(op == ']' && stk.top() == '[') stk.pop();
            else{
                cout << "no" << endl;
                return 0;
            }
        }
    }

    // 最后要看栈是否为空
    if(stk.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

