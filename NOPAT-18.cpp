//输出1-n素数的个数，不包括1和n

#include "stdio.h"

bool mark[10001];
int stock[10000];
int size = 0;

void init(){ //find out all prime number
    for (int i = 0; i < 10001; ++i) {
        mark[i] = false;
    }

    for (int i = 2; i <10001; ++i) {
        if(mark[i] == true) continue; //not prime number

        stock[size ++] = i;

        //mark all multiple number
        for(int j = i*i; j<10001; j+=i){ //square i here is the same theory as finding gcd
            mark[j] = true;
        }
    }
}

bool isfirst;

int main(){
    init();
    int num;
    while (scanf("%d", & num) != EOF){
        isfirst =true;

        for(int i =0; i< size ; ++i){
            if( stock[i]< num && stock[i]%10 ==1){
                if(isfirst){
                    isfirst = false;
                    printf("%d",stock[i]);
                }else{
                    printf(" %d",stock[i]);
                }

            }
        }

        if(isfirst){// nothing printed
            printf("-1\n");
        }else printf("\n");
    }
    return 0;
}
