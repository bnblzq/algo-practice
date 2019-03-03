/*---------------------
 * 输入两个不超过整型定义的非负 10 进制整数 A 和 B(<=231-1)，输出 A+B的 m (1 <m <10)进制数。
 *输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出 m 和A，B的值。当m为 0 时输入结束。
 *
 * sample in
 * 8 1300 48
 * 2 1 7
 * 0
 *
 *
 * sample out
 *
 * 2504
 * 1000
 *
 */
#include "stdio.h"

int main(){
    int decimal;
    long long a,b;  //in case of overflow
    int buf[50];
    int size;
    while( scanf("%d",&decimal) != EOF && decimal !=0){

        size=0;
        scanf("%lld %lld", &a,&b);

        a= a+b;

        do{
            buf[size++] = a % decimal;
            a /=decimal;
        }while (a !=0 );

        for (int i = size-1; i >=0 ; --i) {
            printf("%d",buf[i]);
        }
        printf("\n");

    }
    return 0;
}
