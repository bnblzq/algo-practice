#include <iostream>
#include <stdio.h>

#define  CLK_TCK 100
int main() {

    //as is illustrated in the topic, the number wont be larger than 10
    //^7,so int type is big enough
    int c1,c2;
    scanf("%d%d",&c1,&c2);

    int min = c2-c1;
    if(min % CLK_TCK >= 50) min = min /100 +1;
    else min = min /100;

    printf("%02d:%02d:%02d\n", min/3600, min%3600/60, min%60);


    return 0;
}
