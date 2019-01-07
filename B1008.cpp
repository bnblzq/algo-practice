

#include <stdio.h>

int main()
{

    int space=0;
    int count;
    int rotate;
    int i,j;
    scanf("%d%d",&count,&rotate);
    int temp[count];

    rotate = rotate % count; //significant ,for it cannot rotate longer then array size

    for( i =0;i<count;++i){
        scanf("%d",&temp[i]);}


    for( j=count-rotate; j<count;++j) {

        printf("%d", temp[j]);
        if (++space < count) printf(" ");
    }

    for( j=0; j< (count - rotate) ;++j)
    {
        printf("%d", temp[j]);
        if (++space < count) printf(" ");
    }
    return 0;

}

