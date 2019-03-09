/*输入一个正整数 N，输出N 的阶乘。
 *
 *正整数 N(0<=N<=1000)
 *输入可能包括多组数据，对于每一组输入数据，输出 N 的阶乘
 *
 * sample in:
 * 4
 * 5
 * 15
 *
 * sample out:
 * 24
 * 120
 * 1307674368000
 *
 *
 *
 * */

#include "stdio.h"

struct  bigInteger{
    int digit[1000];
    int size;

    void init(){
        for (int i = 0; i < 1000; ++i) digit[i] = 0;
        size = 0;
    }

    //split up into 4bits
    void set(int x){
        init();

        do{
            digit[size ++] = x %10000;
            x /= 10000;
        }while ( x!=0);
    }

    bigInteger operator * (const  int x) const {
        bigInteger ret;
        ret.init();
        int carry =0;

        for (int i = 0; i < size; ++i) {
            int tmp = digit[i] * x + carry;
            carry = tmp / 10000;
            tmp = tmp % 10000;

            ret.digit[ret.size ++] = tmp;
        }

        //handle the MSB
        if( carry) ret.digit[ret.size ++] = carry;
        return ret;
    }

    void print(){ //we store the MSB at the lowest of digit array
        bool isfirst = true;

        for (int i = size -1; i >=0; --i) {
            if(isfirst) {
                isfirst = false;
                printf("%d",digit[i]);
            }
            else printf("%04d",digit[i]);
        }
        printf("\n");
    }


};
int main(){

    int num;
    bigInteger a;

    while ( scanf("%d", &num) != EOF){


        a.set(1);
        for (int i = 1; i <= num ; ++i) {
            a = a *  i;
        }

        a.print();
        fflush(stdout);
    }

    return 0;
}
