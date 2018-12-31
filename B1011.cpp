#include <iostream>
#include <stdio.h>

int main() {

    int time;
    scanf("%d",&time);
    int tcase=0;

    while(time--){
        long long a ,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a+b > c){
            printf("case #%d true\n",tcase++);
        }else
            printf("case #%d false\n",tcase++);
    }
    return 0;
}