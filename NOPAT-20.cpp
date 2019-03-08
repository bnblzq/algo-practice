/*给定 n，a 求最大的 k，使 n！可以被 a^k 整除但不能被 a^(k+1)整除。
两个整数 n(2<=n<=1000)，a(2<=a<=1000)

  sample in: 6 10
  sample out:1

*/


#include "stdio.h"


bool mark[1010];
int prime[1010];
int primeSize;

void init(){
    for (int i = 0; i < 1010; ++i) {
        mark[i] = false;
    }

    //find prime
    for (int j = 2; j <=1000  ; ++j) {
        if(mark[j] == true) continue;

        prime[primeSize ++] = j;

        for (int k = j*j; k <=1000 ; k+=j) {
            mark[k] = true;
        }
    }
}

int cnt1[1010];
int cnt2[1010];

int main(){
    init();

    int n,a;
    while ( scanf("%d %d",&n,&a) != EOF){
        //clear last record
        for (int i = 0; i < primeSize; ++i) {
            cnt1[i] = cnt2[i] = 0;
        }

        //find prime factor for n

        //see explanation below
        for (int i = 0; i < primeSize; ++i) {
            int save = n;
            while (save){
                cnt1[i] += save / prime[i];
                save /= prime[i];
            }
        }
        
        //find prime factor for a
        int min = 123123123; //i dont think exp value can reach to such a big value
        for (int i = 0; i < primeSize; ++i) {
            while ( a % prime[i] == 0){
                cnt2[i] ++;
                a /=prime[i];
            }

            //this prime number doesnt exist in a
            if( cnt2[i] == 0) continue;

            //calculate the gap and save the miniumn
            if( cnt1[i] / cnt2[i] < min) min = cnt1[i] / cnt2[i];
        }

        printf("%d",min);
    }

    return 0;
}

/*==========explanation

 求m!分解质因数后因子n的个数。
 这道题涉及到了大数问题，如果相乘直接求的话会超出数据类型的范围。
 下面给出一种效率比较高的算法，我们一步一步来。
 m!=1*2*3*……*(m-2)*(m-1)*m
 可以表示成所有和n倍数有关的乘积再乘以其他和n没有关系的
    =(n*2n*3n*......*kn)*other     other是不含n因子的数的乘积 , 因为 k*n<=m 而k肯定是最大值  所以k=m/n(其实是向下取整)
    =n^k*(1*2*......*k)*other
    =n^k * k! * other　　　　　
 从这个表达式中可以提取出k个n，然后按照相同的方法循环下去可以求出k!中因子n的个数。
 即剩下的数是（k！*other），重复以上算法。

 每次求出n的个数的和就是m!中因子n的总个数。

 */