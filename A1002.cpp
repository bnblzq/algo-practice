

#include <stdio.h>

#define  MAX 1111

int main()
{
    int k;
    int exp;
    double cof;
    int count=0;

    scanf("%d",&k);
    double p[MAX]={};

    for(int i=0;i<k;++i){
        scanf("%d %lf", &exp, &cof);
        p[exp] += cof;
    }

    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d %lf", &exp, &cof);
        p[exp] += cof;
    }

    for(int i=0;i< MAX ;++i){
        if(p[i] != 0) count ++;
    }

    printf("%d",count);

    for(int i=MAX-1 ;i>=0;--i){
        if(p[i] !=0){
            printf(" %d %.1f",i, p[i]);  //exp cof
        }
    }

    return  0;
}

//input of k in 2 times may be different, so use the first k to define the length of array
//could cause inaccurate

//output from last to first, because we need high exp item to be outputed first