/*
 * 求任意两个不同进制非负整数的转换（2 进制～16 进制），所给整数在 long所能表达的范围之内。
 * 不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。
 *
 * 输入只有一行，包含三个整数 a，n，b。a 表示其后的 n 是 a 进制整数，b
   表示欲将a 进制整数 n 转换成 b 进制整数。a，b 是十进制整数，2 =< a，b <= 16


   可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转
   换后的b 进制数。输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）

   sample in:
   15 Aab3

   sample out:
   210306
 */

#include "stdio.h"
#include "string.h"

int main(){

    int in_decimal,out_decimal;
    char input[20];
    int weight =1;
    long long temp;

    while (scanf("%d %s %d",&in_decimal,input, &out_decimal) != EOF){

        temp =0;  //remember to clear
        weight =1;
        int length = strlen(input);
        //change to 10 decimal
        for (int i = length-1; i >=0 ; --i) { //lower to upper

            int x;
            if(input[i] >='0' && input[i] <='9'){
                x = (input[i] - '0') ;

            }else if ( input[i] >='a' && input[i] <='f'){

                x = (input[i] - 'a' + 10) ;
            } else if ( input[i] >='A' && input[i] <='F'){

                x = (input[i] -'A' + 10) ;
            }
            temp += x * weight;
            weight *=in_decimal;

        }

        //change to out decimal
        char output[20]={0};
        int j=0;
        do{
            int lower = temp % out_decimal;
            output[j++] =lower < 10 ? lower+'0': lower-10+ 'a';
            temp /= out_decimal;

        }while (temp != 0);

        //print
        for (int k = j-1; k >=0 ; --k) {
            printf("%c",output[k]);

        }
        printf("\n");

    }
    return 0;
}