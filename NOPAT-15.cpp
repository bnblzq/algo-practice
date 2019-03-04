//求最大公约数，利用欧几里得算法即可



#include "stdio.h"

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int a,b;

    while (scanf("%d %d", & a,& b) !=EOF){
        printf("%d\n",gcd(a,b));
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