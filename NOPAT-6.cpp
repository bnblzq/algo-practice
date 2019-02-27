
/*在某个字符串（长度不超过 100）中有左括号、右括号和大小写字母；规定
（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的
 右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，
 并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括
 号用"?"标注.*/


//input
//输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大
//小写字母，字符串长度不超过 100

//sample input : )(rttyy())sss)(

//sample output :
//)(rttyy())sss)(
//?            ?$


#include "stdio.h"
#include "stack"
using namespace std;


int main(){
    stack<int> s;

    char input[100];
    char output[100]={0};

    while(scanf("%s",&input) != EOF){

        //every loop
        for(int i =0; input[i] != '\0';++i){
            if(input[i] == '('){
                s.push(i);
                output[i]=' ';
            }else if ( input[i] == ')'){
                if( ! s.empty()){
                    output[i] = ' ';
                    s.pop();  //match and drop out
                } else { //empty stack
                    //left bracket mismatch
                    output[i] = '?';
                }
            } else { //normal character
                output[i] = ' ';
            }
        }

        //if we left behind sth in stack?
        while ( ! s.empty()){ // right bracket mismatch
            output[s.top()] = '$';
            s.pop();
        }

        puts(input);
        puts(output);

    }
    return 0;
}