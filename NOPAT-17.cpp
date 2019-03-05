//是否是素数？


#include "stdio.h"
#include "math.h"
int main(){
    int m;
    int i;
    while ( scanf("%d", &m)!= EOF){
        int bound = (int)sqrt(m) +1; //pre calculate for saving time
        for( i=2;i< bound ; ++i){
            if( m % i ==0) printf("no\n");

        }
        if(i >= bound) printf("yes\n");
    }
    return 0;

}