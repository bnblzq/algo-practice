//读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
//测试输入包含若干测试用例，每个测试用例占一行，每行不超过 200 个字符，
//整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有 0 时输入结
//束，相应的结果不要输出

//output
//对每个测试用例输出 1 行，即该表达式的值，精确到小数点后 2 位

//sample input
/*-----------
 1+2
 4 + 2 * 5 - 7 / 11
 0
 ---------------*/

/* ----------
 output
 3.00
 13.36
 -----------*/

//#define  DEBUG
#ifdef DEBUG
#define _printf printf
#else
#define _printf
#endif


#include "stdio.h"
#include "stack"
#include "queue"
#include "string"
#include "map"
#include "iostream"

using namespace std;

struct  node{
    double  num;
    char op;
    bool flag;
};
string str;
map<char,int> op;
stack<node> s;
queue<node> q;


//change ,whose function is to change infix expression to suffix expression
void change(){
    node temp;
    for(int i =0;i<str.length();){
        if( str[i]>='0' && str[i]<='9'){ //numerical
               temp.flag = true;
               temp.num = str[i]-'0';
               i++;
               while(i < str.length() && str[i]>='0' && str[i] <='9'){ //continul number
                   temp.num = temp.num *10 + (str[i]- '0');
                   i++;
               }
               q.push(temp);
        }
        else{  //operation
            temp.flag =false;
            temp.op = str[i];
            while (!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    _printf("queue size %d\n",q.size());
}

double cal(){
    node temp;
    node temp1,temp2;

    while (!q.empty()){
        temp = q.front();
        q.pop();

        if(temp.flag == true) s.push(temp);
        else { //operator
            _printf("stack size: %d\n",s.size());
            temp.flag = true;
            temp2 = s.top(); s.pop();
            temp1 = s.top(); s.pop();

            if(temp.op == '+')      temp.num = temp1.num + temp2.num;
            else if(temp.op == '-') temp.num = temp1.num - temp2.num;
            else if(temp.op == '*') temp.num = temp1.num * temp2.num;
            else if(temp.op == '/') temp.num = temp1.num / temp2.num;
            s.push(temp);
        }
    }
    return  s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;

    while(getline(std::cin,str) ,str != "0"){

        //remove space
        for(string::iterator it = str.begin(); it != str.end(); ++it){
            if(*it == ' ') str.erase(it);
        }

        //remove last record
        while (!s.empty()) s.pop();

        //infix to suufix
        change();


        printf("%.2f\n",cal());
    }


    return 0;
}
