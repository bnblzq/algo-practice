
#include <stdio.h>

char * consequence[] ={"false" , "true"};
#define TRUE 1
#define FALSE 0

int main(){

    int num;
    scanf("%d",&num);
    int flag;

    long long a ,b ,c;
    for(int i =1; i<= num ;++i){

        scanf("%lld %lld %lld",&a,&b,&c);
        long long res = a+b;

        if(a>0 && b>0 && res <0) //positive overflow
        {
            flag = TRUE;
        }else if(a<0 && b<0 && res>=0) //negative overflow
        {
            flag = FALSE;
        }else if(res > c){  //normal case
            flag = TRUE;
        }else flag = FALSE;  //of course wrong

        printf("Case #%d: %s\n", i ,consequence[flag]);  //format that topic requests
    }

    return  0;
}

//when happened positive or nagative overflow, posi+ posi must equal to nega
//and vice versa. the value range depends on the data type