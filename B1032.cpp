

#include "stdio.h"

int main(void){
    int num=0;
    scanf("%d",&num);

    //alloc an array to store score,search by index
    int array[num+1];
    for (int i = 1; i <= num; ++i) {
        array[i]= 0;
    }

    for (int i = 1; i <= num; ++i) {
        int temp_school,temp_score;
        scanf("%d %d",&temp_school, &temp_score);

        array[temp_school]+= temp_score;
    }

    //search for maximum
    int max= array[1];
    int index =1;
    for (int i = 1; i <= num; ++i) {
        if(array[i] > max) { max = array[i]; index = i;}
    }

    //output the max
    printf("%d %d\n",index,max);
    return 0;
}
