
/*求 A^B 的最后三位数表示的整数。说明：A^B 的含义是“A 的 B 次方”
输入数据包含多个测试实例，每个实例占一行，由两个正整数 A 和 B 组成
如果 A=0, B=0，则表示输入数据的结束，不做处理

 sample in:
 2 3
 12 6
 6789 10000
 0 0

 sample out:
 8
 984 1

 显然int也没办法存的了6789的10000次方，此类题基本都是求后几位数的
 */

#include "stdio.h"

int main(){
    int bot,exp;
    int ans=1;

    while ( scanf("%d %d", &bot,&exp) !=NULL ){
        ans =1;
        if( bot ==0 && exp == 0) break;

        while (exp !=0){
            if(exp % 2 ==1 ){ //exist
                ans *= bot;
                ans %=1000;
            }
            exp = exp>>1;
            bot = bot*bot;
            bot %=1000; //not ans,because we just care abot the lower 3bit
        }
        printf("%d\n",ans);

    }
    return 0;
}
