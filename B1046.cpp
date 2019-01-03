#include <iostream>
#include <stdio.h>

typedef  struct  combine{
    int shout;
    int row;
}combine;

int main() {


    int count;
    int i =0;

    scanf("%d",&count);

    combine A,B;
    int sumA=0;
    int sumB =0;

    while (count--){
        scanf("%d%d%d%d",&A.shout,&A.row,&B.shout,&B.row);

        if(A.shout + B.shout == A.row && A.shout + B.shout != B.row){ sumB++;} //careful about the equal
        else if(A.shout + B.shout == B.row && A.shout + B.shout != A.row){ sumA++;}

    }

    printf("A lost:%d B lost:%d\n",sumA,sumB);

    return 0;
}
