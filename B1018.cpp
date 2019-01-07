

#include <stdio.h>

int transform(char hand){
    if(hand == 'B') return 0;
    if(hand == 'C') return 1;
    if(hand == 'J') return 2;
}

char verse_transform(int hand){
    if(hand == 0) return 'B';
    if(hand == 1) return 'C';
    if(hand == 2) return 'J';
}

int main(){

    int num;
    char fistA,fistB;

    int winA[3]={0};
    int winB[3]={0};
    int handA[3]={0};
    int handB[3]={0};

    scanf("%d",&num); //how many lines

    for(int i=0;i<num; ++i){

        getchar(); //deal with the \n from num input

        scanf("%c %c",&fistA,&fistB);

        int _handA = transform(fistA);
        int _handB = transform(fistB);

        if( (_handA+1)%3 == _handB){  // A win
            winA[0]++ ; //0 win 1 equal 2 lose
            winB[2]++;
            handA[_handA] ++;


        }else if( (_handB+1)%3 == _handA){  //B win
            winB[0]++;
            winA[2]++;
            handB[_handB]++;
        }else{                      //equal
            winA[1]++;
            winB[1]++;
        }


    }

    printf("%d %d %d\n",winA[0],winA[1],winA[2]);
    printf("%d %d %d\n",winB[0],winB[1],winB[2]);

    //calculate which combine wins most
    int mostA =0 ;
    int mostB = 0;

    for(int i =0;i<3;++i){
        if(handA[i] > handA[mostA]) mostA = i;
    }
    for(int i =0;i<3;++i){
        if(handB[i] > handB[mostB]) mostB = i;
    }
    printf("%c %c",verse_transform(mostA), verse_transform(mostB));

    return 0;

}