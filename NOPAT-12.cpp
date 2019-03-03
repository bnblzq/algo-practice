/*-----------------------
 *
 * 写个算法，对 2 个小于 1000000000 的输入，求结果。特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
 *
 * input:两个小于 1000000000 的数
 * sample in : 123 45
 *
 *output:输入可能有多组数据，对于每一组数据，输出 Input 中的两个数按照题目要求的方法进行运算后得到的结果。
 *
 *sample out:54
 *
 *
 *
 *
 *
 *
 */
#include "stdio.h"

int main(){

    int a,b;
    int bufA[20],bufB[20];
    int indexA,indexB;
    int total = 0;

    while ( scanf("%d %d", &a,&b) != EOF){
        indexA = indexB = 0;
        total = 0;

        while (a >0){
            bufA[indexA ++] = a%10;
            a /=10;
        }

        while (b > 0){
            bufB[indexB ++] = b %10;
            b /=10;
        }

        for (int i = 0; i < indexA; ++i) {
            for (int j = 0; j < indexB; ++j) {
                total += bufA[i] * bufB[j];
            }
        }

        printf("%d\n",total);
    }
    return 0;
}
