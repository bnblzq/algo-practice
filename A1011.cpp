#include "cstdio"

char result[3]={'W','T','L'};


//get the biggest
int compare(float first, float second, float third){
    if( first > second && first > third) return 0;
    else if( second > first && second > third) return 1;
    else if( third> first && third > second) return 2;
}


int main(){
    float num[3];
    float sum= 1.0;

    for (int i = 0; i < 3; ++i) {
        scanf("%f %f %f",&num[0], &num[1],&num[2]);

        //find max
        int index = compare(num[0],num[1],num[2]);
        printf("%c ",result[index]);

        sum *=num[index];
    }

    printf("%.2f", (sum*0.65-1)*2 );

    return 0;
}
