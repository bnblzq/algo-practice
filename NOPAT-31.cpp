
/*输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），
N 表示成都的大街上有几个路口，标号为 1 的路口是商店所在地，标号为 N 的
路口是赛场所在地，M 则表示在成都有几条路。N=M=0 表示输入结束。接下来M 行，
        每行包括 3 个整数 A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口 A
与路口 B 之间有一条路，我们的工作人员需要 C 分钟的时间走过这条路。输入
保证至少存在 1 条商店到赛场的路线。
当输入为两个 0 时，输入结束。

对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间。

sample in:
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0

sample out:
3
2

1.读入vector模拟的邻接表，转换为邻接矩阵
2.对矩阵采用djistra算法找最短路径*/


//#define Debug_printf

#ifdef DEBUG
#define Debug_printf printf
#else
#define Debug_printf
#endif


#include "stdio.h"
#include "vector"
#define INF 100001
using  namespace std;

struct E{
    int next;
    int cost;
};
vector<E> edge[101];  //two -dimension array
bool mark[101];
int dist[101];

//approach transform imitate linklist to adjacent matrix
void transform(int n,int m){
    // num x num array
    int temp[n][n];


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            temp[k][i] = -1;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < edge[i].size(); ++j) {
            int start = i-1;
            int end  = edge[i][j].next -1;

            temp[start][end] = edge[i][j].cost;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            Debug_printf("%d ",temp[k][i]);
        }
        Debug_printf("\n");
    }

    //dijistra
    int distance[n];
    bool set[n];
    for (int l = 0; l < n; ++l) {
        distance[l] = temp[0][l];
    }

    //print distance
    Debug_printf("===========\n");
    for (int i = 0; i < n; ++i) Debug_printf("%d ",distance[i]);
    Debug_printf("\n");
    fflush(stdout);


    for(int i =0; i<n ;i++) set[i] = false;
    set[0] = true;
    int min ;
    int relay;

    for (int i = 0; i < n - 1; ++i) {
        min = INF;
        for (int j = 0; j < n; ++j) {  //find the nearest point by 0
            if( set[j] == false && distance[j] < min){
                min = distance[j];
                relay = j;
            }
        }
        set[relay] = true;

        //lets see if we can get shorter distance via ultimate
        for(int v =0; v<n ;v++){
            if(temp[relay][v] < INF && temp[relay][v] != -1){
                if( distance[relay] + temp[relay][v] < distance[v])  distance[v] = distance[relay] + temp[relay][v];
            }
        }
    }

    Debug_printf("===========\n");
    for (int i = 0; i < n; ++i) Debug_printf("%d ",distance[i]);
    Debug_printf("\n");
    fflush(stdout);

    printf("%d\n",distance[n-1]);
}


int main(){
    int n,m;
    while ( scanf("%d%d", &n, &m) != EOF){
        int line = m;
        if( n ==0 && m ==0) break;
        for (int i = 0; i < n; ++i) edge[i].clear();

        while (m--){
            int a,b ,c;
            scanf("%d %d %d", &a, &b, &c);
            E tmp;
            tmp.cost = c;
            tmp.next = b;
            edge[a].push_back(tmp);

            tmp.next = a;
            edge[b].push_back(tmp);
        }

        for(int i =0;i<n; i++){
            dist[i] = -1;
            mark[i] = false;
        }

       transform(n,line);

    }
    return 0;
}