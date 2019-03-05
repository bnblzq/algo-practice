//求最大公倍数，利用欧几里得算法先求出最大公约数，
// 然后a*b/公约数即可



#include "stdio.h"

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int a,b;

    while (scanf("%d %d", & a,& b) !=EOF){
        printf("%d\n",a*b /gcd(a,b));
    }
    return 0;
}

/* 欧几里得非递归
 int gcd(int a,int b){
    if ( a==0 || b==0) return a==0? b:a;

    else {
        while(b !=0){
            a=b;
            b= a%b
        }
        return a;
    }
 }*/