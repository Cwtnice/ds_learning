/*
 * 栈的应用：中缀表达式转后缀表达式
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE=10000;
int comparePriority(char ,char );

//默认输入是正确的中缀表达式
int main(){
    int top=-1;
    string input;
    char stack[MAX_SIZE];
    cin>>input;
    for (int i=0;i<input[i]!='\0';i++){
        //获取输入的每个字符
        char ch=input[i];
        //判断字符
        //操作数
        if (ch>='0'&&ch<='9'){
            cout<<ch;//输出
        }
            //操作符
        else if (ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            //栈空或者为左括号则直接入栈
            if (top==-1) stack[++top]=ch;
            else
                while (true){
                    //若栈顶为左括号--------------------之前犯错点
                    if (top==-1||stack[top]=='(') {
                        stack[++top]=ch;
                        break;
                    }
                    //ch优先级 > 栈顶操作符
                    if (comparePriority(ch,stack[top])==1){
                        stack[++top]=ch;//入栈
                        break;//不再比较
                    }
                        //ch优先级 <= 栈顶操作符
                    else {
                        cout<<stack[top--];//出栈
                        continue;
                    }
                }
        }
            //括号
            //左括号
        else if (ch=='(')
            stack[++top]=ch;//入栈
            //右括号
        else if (ch==')'){
            //栈顶到左括号全出栈
            while (top!=-1&&stack[top]!='('){
                cout<<stack[top--];
            }
            if (top!=-1) {
                top--;//删除多余的左括号--------------------之前犯错点
            }
        }
    }
    while (top!=-1){
        cout<<stack[top--];
    }
}

/*
比较优先级 (不判断操作符正确性，默认为+-/*之二
	前>后 为 1
	后>前 为 -1
   前==后 为0
*/
int comparePriority(char former,char latter){
    if (former=='+'||former=='-'){
        if (latter=='*'||latter=='/')
            return -1;//前+-后*/
        else return 0;//前+-后+-
    }
    else {
        if (latter=='+'||latter=='-')
            return 1;//前*/后+-
        else return 0;//前*-后*-
    }
}
