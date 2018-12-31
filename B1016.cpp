#include <iostream>
#include <stdio.h>

int main() {
    int numA ,Da,pa=0;
    int numB, Db,pb=0;
    printf("numA,Da\n");
    scanf("%d %d",&numA,&Da);
    printf("numB,Db\n");
    scanf("%d %d",&numB,&Db);

    while(numA!=0){
        if(numA % 10 == Da){
            pa = Da + pa*10;
        }
        numA=numA / 10;
    }
    while(numB!=0){
        if(numB % 10 == Db){
            pb = Db + pb*10;
        }
        numB=numB / 10;
    }
    printf("sum of pa + pb:%d\n",pa+pb);

    return 0;
}
