#include <iostream>
#include <stdio.h>

int main() {
    int n;
    int count=1;
    scanf("%d",&n);

    while(n!=1){
        if(n%2== 0){
            //even
            n=n/2;
        }else{
            n=(3*n+1)/2;
        }
        count++;
    }

    printf("count:%d",count);
    return 0;
}