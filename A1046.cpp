
#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main()
{

    int point_num;
    scanf("%d",&point_num);

    int A[point_num +1];
    int sum=0; //a cycle
    int distane[point_num+1]={0};

    for(int i=1;i < point_num+1 ; ++i){
        scanf("%d",&A[i]);  //input distance between near point
        sum +=A[i];
        distane[i] = sum;
    }

    int round;
    scanf("%d",&round);
    for(int i =0;i< round;++i){
        int l,r;
        scanf("%d %d",&l,&r); //left point and right point accord with clockwise

        //swap
        if(l >  r) {int temp=l; l=r;r=temp;}

        int dist = distane[r-1] - distane[l-1];
        printf("%d\n", MIN(dist,sum-dist));
    }
    return 0;

}
