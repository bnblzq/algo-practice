
/*
实现一个加法器，使其能够输出 a+b 的值
输入包括两个数 a 和 b，其中 a 和 b 的位数不超过 1000 位。

可能有多组测试数据，对于每组数据，输出 a+b 的值。

 sample in:
 2 6
 10000000000000000000 10000000000000000000000000000000

 sample out:
 8
 10000000000010000000000000000000

 */

#include "stdio.h"
#include "string.h"

using  namespace std;
struct bigInterger{
    int digit[1002];
    int size;

    void clear(){
        for (int i = 0; i < 1002; ++i) {
            digit[i] = 0;
        }
        size = 0;
    }

    void set(char str[]){
        clear(); //for last record;
        int len = strlen(str);

        for (int i = len -1,weight = 1,tmp=0,count =0;  i >=0 ; --i) {

            tmp += (str[i]-'0') * weight; //accumulate
            weight *= 10;
            count ++;
            if(count ==4 || i ==0){
                count = 0;
                weight =1;

                digit[size++] = tmp;

                tmp = 0;
            }
        }

    }

    bigInterger operator + (const bigInterger & A) const {
        bigInterger ret;
        ret.clear();

        //deal with + logic
        int carry=0;
        for (int i = 0; i < size || i< A.size; ++i) {
            int temp = digit[i] + A.digit[i] + carry;
            carry = temp /10000;
            temp %= 10000;

            ret.digit[ret.size++] = temp;
        }

        return ret;
    }

    void output(){
        for (int i = size-1; i >=0; --i) {
            if(i == size-1) printf("%d",digit[i]);
            else printf("%04d",digit[i]);
        }
        printf("\n");
    }


}a,b,c;
int main(){
    char str1[1002],str2[1002];

    while (scanf("%s %s",str1,str2) != EOF){
        a.set(str1);
        b.set(str2);//change string into digit

        c= a + b ;
        c.output();

    }
    return 0;
}