/*求正整数 N(N>1)的质因数的个数。相同的质因数需要重复计算。如 120=2*2*2*3*5，共有 5 个质因数。
  可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)
  可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)

  sample in  :120
  sample out : 5

 注意：1 不是 N 的质因数；若 N 为质数，N 是 N 的质因数。

 */

#include "stdio.h"

bool mark[100001];
int primeNumber[100001];
int size =0;

void init() { //find out all prime number

    for(int i =0;i<= 100001;++i) mark[i] = false;

    for(int i=2; i<100001;++i){
        if(mark[i] == true) continue;

        primeNumber[size++] = i;

        if( i> 1000) continue; //overflow .when i reachs to 1000,i square has been to 10^6
        for (int j = i*i; j <100001 ; j+=i) {
            mark[j] = true;
        }
    }
}

int ansexp[30];

int ansPrime[30];
int ansPrimesize = 0;

void clear(){
    for (int i = 0; i < ansPrimesize; ++i) {
        ansPrime[i]=0;
        ansexp[i] = 0;
    }
}

int main(){
    init();
    int num;
    while (scanf("%d", &num) != EOF){

        //clear last record
        clear();

        for(int i =0;i< size; ++i){
            if( num %primeNumber[i] == 0){
                ansPrime[ansPrimesize] = primeNumber[i];

                while ( num % primeNumber[i] ==0){
                    ansexp[ansPrimesize] ++;
                    num /= primeNumber[i];
                }
                ansPrimesize ++;
                if(num == 1) break;

            }
        }

        if( num !=1) {
            ansPrime[ ansPrimesize] = num;
            ansexp[ansPrimesize++] = 1;
        }

        int total=0;
        for (int j = 0; j < ansPrimesize; ++j) {
            total += ansexp[j];
        }
        printf("%d\n",total);
    }
    return 0;
}
