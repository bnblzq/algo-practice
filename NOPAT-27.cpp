/*省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通
（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路

测试输入包含若干测试用例。每个测试用例的第 1 行给出两个正整数，分别
是城镇数目 N ( < 1000 )和道路数目 M；随后的 M 行对应 M 条道路，每行给出
一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从
1 到 N 编号。当 N 为 0 时，输入结束，该用例不被处理。

对每个测试用例，在 1 行里输出最少还需要建设的道路数目。 (本质上就是求把n个联通分支连起来需要的边数，即n-1

 sample in:
 4 2
 1 3
 4 3

 3 3
 1 2
 1 3
 2 3

 5 2
 1 2
 3 5

 999 0

 0

 sample out:
 1
 0
 2
 998

 */





#include "stdio.h"

int tree[1001];
void clear(){
    for (int i = 0; i < 1001; ++i) {
        tree[i] = -1;
    }
    return;
}

//find root
int findpath(int x){
    if( tree[x] == -1) return  x;
    else{
        int tmp = findpath(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}
int main(){

    int city,path = 0;

    while (scanf("%d", &city)!= EOF && city !=0){
        scanf("%d",&path);

        clear();

        for (int i = 0; i < path; ++i) {
            int citya,cityb;
            scanf("%d %d",&citya, &cityb);

            int roota = findpath(citya);
            int rootb = findpath(cityb);

            //not the same root
            if(roota != rootb){
                //join
                tree[roota] = rootb;
            }
        }

        //sum up
        int count =0;
        for (int i = 1; i <= city ; ++i) {
            if(tree[i] == -1) count ++;
        }
        printf("%d\n",count-1);

    }
    return 0;
}