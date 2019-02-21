
//输入一个高度 h，输出一个高为 h，上底边为 h 的梯形。
//in: 一个整数 h(1<=h<=1000)。
//out:
/*--------------  right margin
        ****

      ******

    ********

  **********
 ------------------*/


#include "stdio.h"

int main(){
    int h;
    scanf("%d",&h);

    for (int i = 1; i <= h; ++i) { //1 ~ h row
        int max = h+ (h-1)*2;

        for (int j = 1; j <max ; ++j) { //1 ~ max column
            int gap;
            if(j < max - h - (i-1)*2) //of course related about row number
                printf(" "); //space
            else printf("*");  // **
        }
        printf("\n");

    }
    printf("\n");

    return 0;
}