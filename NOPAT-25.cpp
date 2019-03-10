

/* 将 M 进制的数 X 转换为 N 进制的数输出
 * 输入的第一行包括两个整数：M 和 N(2<=M,N<=36)。下的一行输入一个数 X，X 是 M 进制的数，现在要求你将 M 进制的数 X转换成 N 进制的数输出。
 *
 *输出 X 的 N 进制表示的数。
 *
 *sample in:
 * 16 10
 * F
 *
 * sample out:
 * 15
 *
 * */


#include "stdio.h"
#include "string"
#define MAXSIZE 1000
struct  bigInteger {
    int digit[MAXSIZE];
    int size;

    void init(){
        for (int i = 0; i < MAXSIZE; ++i) {
            digit[i] = 0;
        }
        size =0;
    }

    //split up
    void set(int x){
        init();
        do{
            digit[size++] = x % 10000;
            x /=10000;
        }while (x!=0);
    }

    void print(){
        bool isMSB = true;
        for (int i = size -1; i >=0 ; --i) {
            if(isMSB){
                isMSB = false;
                printf("%d",digit[i]);
            }else printf("%04d",digit[i]);

        }
        printf("\n");
    }

    bigInteger operator + (const bigInteger &a) const {
        bigInteger ret;
        ret.init();
        int carry = 0;

        for (int i = 0; i < size || i< a.size; ++i) {
            int tmp = carry + digit[i] + a.digit[i];
            carry = tmp / 10000;
            ret.digit[ret.size++] = tmp % 10000;
        }

        if(carry) ret.digit[ret.size++] = carry;
        return  ret;
    }

    bigInteger operator * (int x) const{
        bigInteger ret;
        ret.init();
        int carry = 0;

        for (int i = 0; i <size ; ++i) {
            int tmp = carry + digit[i] * x;
            carry = tmp / 10000;
            ret.digit[ret.size++] = tmp % 10000;
        }

        if(carry) ret.digit[ret.size++] = carry;
        return ret;
    }


    bigInteger operator / (const int x) const{
        bigInteger ret;
        ret.init();

        int remain=0;
        for (int i = size -1; i >=0; --i) {
            int s = (remain * 10000 + digit[i]) / x;
            int r = (remain * 10000 + digit[i]) % x;
            remain = r;
            ret.digit[i] = s; //we dont use size++ here because i and size change synchronously,also when s reachs 0,we
                              //should exclude it in next round,so we deal with the size below
        }
        //calculate ret.digit 's size
        for (int i = 0; i < MAXSIZE; ++i) {
            if( digit[i]) ret.size=  i; //if we get 0 this round in ret,it will be remove in next round
                                        //like ret=0123,
        }

        ret.size ++; //point to next vacant location
        return ret;
    }

    int operator % (const int x) const {
        int remain =0;
        for (int i = size -1; i >=0 ; --i) {
            int s = (remain * 10000 + digit[i]) / x;
            int r = (remain * 10000 + digit[i]) % x;
            remain = r;
        }
        return remain;
    }
}a,b,c;

int main(){

    int num;
    int m,n;
    char str[MAXSIZE];
    char ans[MAXSIZE];


    while ( scanf("%d %d",&m,&n) != EOF){
        scanf("%s",str);
        int len = strlen(str);
        a.set(0); //m->10
        b.set(1); //weight
        for (int i = len -1; i >=0 ; --i) {
            int t;
            if(str[i] >= '0' && str[i] <= '9'){
                t = str[i] -'0';
            }else t = str[i] - 'A' + 10;

            a = a + b*t;
            b = b * m;
        }

        int size =0;
        do{
            int t = a % n;
            if(t >= 10) ans[size++] = 'a' + t -10;
            else ans[size++] = t + '0';
            a = a / n;
        }while (a.digit[0] !=0 || a.size !=1); //during the calculation ,we may encounter the digit[0]=0,but it means
                                            //nothing.only if the same as the a.size,we can infer the whole a = 0

        for (int j = size-1; j >=0 ; --j) {
            printf("%c",ans[j]);
        }
        printf("\n");
    }

    return 0;
}
