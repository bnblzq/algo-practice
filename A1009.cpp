

#include <stdio.h>

struct  Poly{
    int exp;
    double cof;
};

Poly poly[1001];    //store input
double ans[2001]; //store consequence

int main(){

    int num,num2;
    scanf("%d",&num);
    for(int i =0;i<num;++i){
        scanf("%d %lf",&poly[i].exp, &poly[i].cof);
    }

    //second input
    scanf("%d",&num2);
    for(int i =0; i< num2; ++i){
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof);
        for(int j=0;j< num;++j){
            ans[ exp + poly[j].exp] += cof * poly[j].cof ; //use += in case of the same exp shown in different item
        }
    }

    int count=0;
    for(int i =0;i<=2000;++i){
        if(ans[i] != 0.0) count++;
    }
    printf("%d",count);

    for(int i=2000; i>=0;--i){
        if(ans[i] != 0.0){
            printf(" %d %.1f",i,ans[i]);
        }
    }

    return  0;
}
