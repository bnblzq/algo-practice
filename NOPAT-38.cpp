/*
N 阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。（要求 采用非递归）
输入包括一个整数 N,(1<=N<90)。

可能有多组测试数据，对于每组数据，输出当楼梯阶数是 N 时的上楼方式 个数。

sample in:
4

sample out:
5

 */

#include"stdio.h"

long long f[91];

int main() {

    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <=90; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    int num;
    scanf("%d", &num);
    printf("%lld", f[num]);

    return 0;
}