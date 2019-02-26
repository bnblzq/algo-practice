
/*----------
 输入数据包含多个测试实例， 每个测试实例的第一行只有一个整数

n(n<=100)，表示你喜欢看的节目的总数，然后是 n 行数据，每行包括两个数据

Ti_s,Ti_e (1<=i<=n)，分别表示第 i 个节目的开始和结束时间，为了简化问题，每

个时间都用一个正整数表示。n=0 表示输入结束，不做处理。
 -----------------*/

//output
//对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。

//sample input
/*-------
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

the output should be 5
---------*/

#include "stdio.h"
#include "algorithm"

using namespace std;

struct show{
    int start;
    int end;
    bool exist;

    //reload <
    bool operator < (const show & A) const {
        if( !exist || !A.exist) return exist > A.exist;
        else return end < A.end;
    }
}buf[101];

int main(){
    int count;

    for (int k = 0; k <101; ++k) {
        buf[k].exist = false;
    }

    //read in
    while(scanf("%d", &count) != EOF) {

        if(count == 0) break;

        for (int i = 0; i < count; ++i) {
            scanf("%d %d", &buf[i].start, &buf[i].end);
            buf[i].exist = true;
        }

        //sort
        sort(buf, buf + 101);

        //pick
        int index = 0; //0 o'clock
        int total = 0;
        for (int j = 0; j < count; ++j) {
            if (index <= buf[j].start) {
                //watch it
                total++;
                index = buf[j].end;
            }
        }
        printf("%d", total);
    }
    return 0;
}
