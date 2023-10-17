/*
 * 顺序栈
 * 顺序栈是用顺序存储结构实现的栈, 利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素
 * 不使用STL手动实现
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 20

// 顺序栈
typedef struct{
    char data[MaxSize];	// 存放元素
    int top;	// 栈顶指针
}SqStack;	// 顺序栈

int main(){
    printf("请输入初始字符串：");
    string str;
    // string str = "abcdefghijklmnopqrstuvwxyz"
    cin >> str;

    SqStack st;
    st.top = -1;

    printf("初始栈顶指针为：%d, 栈最大容量为：%d\n", st.top, MaxSize);

    // 入栈
    puts("开始入栈：");
    for(char i : str){
        if(st.top == MaxSize - 1){  // 栈满条件
            puts("栈已满, 停止入栈！");
            break;
        }
        st.data[++st.top] = i;
    }
    printf("入栈结束后栈顶指针为：%d\n", st.top);

    // 出栈
    puts("开始出栈：");
    int n;
    printf("出栈的元素个数为：");
    cin >> n;

    puts("出栈序列依次为：");
    while(n--){
        if(st.top == -1) {    // 栈空条件
            puts("栈已空, 无法出栈！");
            break;
        }
        auto top = st.data[st.top--];
        cout << top << " ";
    }

    return 0;
}