
#include <stdio.h>

#define NUM 54

char suit[5] = {'S','H','C','D','J'};

int main()
{

    int round;
    scanf("%d",&round);

    int start[NUM+1];
    int end[NUM+1];
    int temp[NUM+1];

    //initialize 1-54
    for(int i=1;i<=NUM;++i) start[i] = i;

    //read new  location
    for(int j=1;j<=NUM;++j) scanf("%d",&temp[j]);

    //loop round
    for(int j=0;j<round;++j) {

        //relocate
        for (int i = 1; i <= NUM; ++i) end[temp[i]] = start[i];

        //overlapse
        for (int i = 1; i <= NUM; ++i) start[i] = end[i];
    }

    //output
    int count=0;
    for(int i=1;i<=NUM;++i){

        //for suit array is indexed from 0
        start[i] --;
        printf("%c%d",suit[start[i]/13] , (start[i]%13) +1);


        //controm the space output
        count++;
        if(count<NUM) printf(" ");

    }

    return 0;

}

