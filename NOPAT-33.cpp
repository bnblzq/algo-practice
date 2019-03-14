

/*Ignatius 被魔王抓走了,有一天魔王出差去了,这可是 Ignatius 逃亡的好机会.
魔王住在一个城堡里,城堡是一个 A*B*C 的立方体,可以被表示成 A 个 B*C 的矩
阵,刚开始 Ignatius 被关在(0,0,0)的位置,离开城堡的门在(A-1,B-1,C-1)的位置,现
在知道魔王将在 T 分钟后回到城堡,Ignatius 每分钟能从一个坐标走到相邻的六个
坐标中的其中一个.现在给你城堡的地图,请你计算出 Ignatius 能否在魔王回来前
离开城堡(只要走到出口就算离开城堡,如果走到出口的时候魔王刚好回来也算逃
亡成功),如果可以请输出需要多少分钟才能离开,如果不能则输出-1。

输入数据的第一行是一个正整数 K,表明测试数据的数量.每组测试数据的第
一行是四个正整数 A,B,C 和 T(1<=A,B,C<=50,1<=T<=1000),它们分别代表城堡的
大小和魔王回来的时间.然后是 A 块输入数据(先是第 0 块,然后是第 1 块,第 2
块......),每块输入数据有 B 行,每行有 C 个正整数,代表迷宫的布局,其中 0 代表路,1
代表墙。


对于每组测试数据,如果 Ignatius 能够在魔王回来前离开城堡,那么请输出他
最少需要多少分钟,否则输出-1.

1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0*/

#include "stdio.h"
#include "queue"

using namespace std;

struct Vertex{
    int x;
    int y;
    int z;
    int cost;
};

bool mark[50][50][50];
int triangle[50][50][50];

queue<Vertex> q;

int path[][3]={
        1,0,0,
        -1,0,0,
        0,1,0,
        0,-1,0,
        0,0,1,
        0,0,-1
};

int bfs(int a,int b, int c){
    while (!q.empty()){
        Vertex now = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {  //3 dimension ,6 directions,each time it may insert 6 points into queue, for next round
            int nx  = now.x + path[i][0];
            int ny  = now.y + path[i][1];
            int nz  = now.z + path[i][2];

            if( nx<0 || nx >=a || ny<0 || ny>=b || nz<0 || nz>=c ) continue;
            if(mark[nx][ny][nz] == true) continue;
            if(triangle[nx][ny][nz] == 1)continue;

            Vertex tmp;
            tmp.x = nx; tmp.y = ny; tmp.z = nz; tmp.cost = now.cost +1;
            q.push(tmp);
            mark[nx][ny][nz] = true;
            if(nx== a-1 && ny == b-1 && nz == c-1) return tmp.cost; //this line must here,because we should return the next point rather than now,so the cost should +1
        }
    }
    return -1;
}


int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int x, y, z, time;
        scanf("%d %d %d %d", &x, &y, &z, &time);

        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                for (int k = 0; k < z; ++k) {
                    scanf("%d", &triangle[i][j][k]);
                    mark[i][j][k] = false;
                }
        while (!q.empty()) q.pop();

        mark[0][0][0] = true;
        Vertex tmp;
        tmp.x = tmp.y = tmp.z = tmp.cost = 0;
        q.push(tmp);

        int rec = bfs(x, y, z);
        if (rec <= time) printf("%d\n", rec);
        else printf("-1\n");
    }
    return 0;
}
