/*
Mr Wang wants some boys to help him with a project. Because the project is
rather complex, the more boys come, the better it will be. Of course there are certain
requirements.Mr Wang selected a room big enough to hold the boys. The boy who are
not been chosen has to leave the room immediately. There are 10000000 boys in the
room numbered from 1 to 10000000 at the very beginning. After Mr Wang's selection
any two of them who are still in this room should be friends (direct or indirect), or
there is only one boy left. Given all the direct friend-pairs, you should decide the best way

The first line of the input contains an integer n (0 ≤ n ≤ 100 000) - the number of
direct friend-pairs. The following n lines each contains a pair of numbers A and B
separated by a single space that suggests A and B are direct friends. (A ≠ B, 1 ≤ A, B
≤ 10000000)


The output in one line contains exactly one integer equals to the maximum

number of boys Mr Wang may keep. (maximun connexted branch)

 sample in:
 4
 1 2
 3 4
 5 6
 1 6
 4
 1 2
 3 4
 5 6
 7 8

 sample out:
 4
 2

 */



#include "stdio.h"
#define SIZE 10000001

int Tree[SIZE];
int sum[SIZE];

void clear(){
    for (int i = 0; i <10000001 ; ++i) {
        Tree[i] = -1;
        sum[i] = 1;  //itself
    }
}

int findroot( int x){
    if( Tree[x] == -1) return x;
    else{
        int root = findroot(Tree[x]);
        Tree[x] = root;
        return root;
    }
}


int main(){

    int line;
    while ( scanf("%d", &line) != EOF) {

        clear();

        //read in relation
        int a, b;
        while (line-- != 0) {
            scanf("%d %d", &a, &b);

            int roota = findroot(a);
            int rootb = findroot(b);

            if(roota != rootb){
                //join and sum up factors
                Tree[roota] = rootb;
                sum[rootb] += sum[roota]; //roota's topper is rootb,so the total roota should be added up tp rootb
            }
        }

        int ans = 1;
        for (int i = 0; i <SIZE ; ++i) {
            if(Tree[i] == -1 && sum[i] > ans) {
                ans = sum[i];
               // printf("this time: %d\n",Tree[i]);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
