/*//topology
The input consists of several test cases. For each case, the first line contains two
        integers, N (members to be tested) and M (relationships to be tested)(2 <= N, M <=
100). Then M lines follow, each contains a pair of (x, y) which means x is y's master
and y is x's prentice. The input is terminated by N = 0.TO MAKE IT SIMPLE, we
give every one a number (0, 1, 2,..., N-1). We use their numbers instead of their names.


For each test case, print in one line
the judgement of the messy relationship.If it
is legal, output "YES", otherwise "NO".

sample in:
3 2
0 1
1 2
2 2
0 1
1 0
0 0

sample out:
YES
NO

 */



#include "stdio.h"
#include "vector"
#include "queue"

using namespace std;

vector<int> edge[101];
int indegree[101];
queue<int> q;

void clear(){
    for (int i = 0; i < 101; ++i) {
        edge[i].clear();
        indegree[i]= 0;

    }
    while (!q.empty()) q.pop();


}

int main() {

    int num,line;

    while ( scanf("%d %d", &num,&line) != EOF ){
        if( num ==0 && line ==0) break;

        clear();

        while (line --){
            int a,b;
            scanf("%d %d",&a,&b);

            indegree[b]++;
            edge[a].push_back(b);
        }

        for (int i = 0; i < num; ++i) {
            if(indegree[i] ==0) q.push(i);

        }

        int count = 0;
        while (!q.empty()){
            int head = q.front();
            q.pop();
            count ++;

            for (int i = 0; i <edge[head].size() ; ++i) {
                indegree[ edge[ head][i] ] --;
                if(indegree[ edge[head][i] ] == 0)
                    q.push(edge[head][i]);
            }
        }

        if(count == num) printf("YES\n");
        else printf("NO\n");

    }



    return 0;
}
