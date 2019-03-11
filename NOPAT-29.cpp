/*某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政
府“畅通工程的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有
直接的公路相连，只要间接通过公路可达即可），并要求铺设的公路总长度为最
小。请计算最小的公路总长度。

测试输入包含若干测试用例。每个测试用例的第 1 行给出村庄数目 N ( <
100 )；随后的 N(N-1)/2 行对应村庄间的距离，每行给出一对正整数，分别是两
个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从 1 到 N 编号。当 N
为 0 时，输入结束，该用例不被处理。

对每个测试用例，在 1 行里输出最小的公路总长度。

 sample in:
 3
 1 2 1
 1 3 2
 2 3 4
 4
 1 2 1
 1 3 4
 1 4
 2 3 3
 2 4 2
 3 4 5
 0

 sample out:
 3
 5

 */


#include "stdio.h"
#include "algorithm"
using namespace std;

int getline( int x){
    return x*(x-1) /2;
}

#define  SIZE 101

struct info{
    int start;
    int end;
    int weight;
}vil[SIZE];


int Tree[SIZE];
int total;

void clear(){
    for (int i = 0; i <SIZE ; ++i) {
        Tree[i] = -1;
    }

    total = 0;

}

bool cmp(info a,info b){
    return a.weight < b.weight;
}

int findroot(int x){
    if( Tree[x]  == -1 ) return x;
    else{
        int root = findroot(Tree[x]);
        Tree[x] = root;
        return root;
    }
}

int main(){

    int in;
    while (scanf("%d", &in) != EOF && in !=0){
        clear();
        int line = getline(in);

        int i=0;
        while (line -- != 0){
            scanf("%d %d %d",&vil[i].start, &vil[i].end,  &vil[i].weight);
            i++;
        }

        //sort by weight
        sort(vil,vil+i , cmp);

        for (int index = 0; index <i ; ++index) {
            int roota = findroot(vil[index].start);
            int rootb = findroot(vil[index].end);

            if(roota != rootb){
                Tree[roota] = rootb;
                total +=vil[index].weight;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
