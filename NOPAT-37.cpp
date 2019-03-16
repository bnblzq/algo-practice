/*The input consists of multiple test cases. The first line of each test case contains
three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the
maze and the time at which the door will open, respectively. The next N lines give the
maze layout, with each line containing M characters. A character is one of the

following:
'X': a block of wall, which the doggie cannot enter;
'S': the start point of the doggie;
'D': the Door; or
'.': an empty block.
The input is terminated with three 0's. This test case is not to be processed.


For each test case, print in one line "YES" if the doggie can survive, or "NO"
otherwise.

sample in:
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
0 0 0

sample out:
NO
YES*/


#include "stdio.h"

int n,m,t;
char maze[8][8];
bool success;
int go[][2]={  //doesnt include hypotenuse
        -1,0,
        1,0,
        0,1,
        0,-1,

};

void DFS(int x,int y,int time){
    for (int i = 0; i < 4; ++i) {
        int nx = x+ go[i][0];
        int ny = y+ go[i][1];

        if(nx < 1|| nx> n || ny<1 ||ny>m) continue;
        if(maze[nx][ny] == 'X') continue;
        if(maze[nx][ny] == 'D'){
            if(time +1 ==t){
                success = true;
                return;
            }else continue;
        }

        //already walk through
        maze[nx][ny] = 'X';
        DFS(nx,ny,time+1);
        maze[nx][ny] = '.';
        if(success) return;
    }
    return;
}

int main(){
    while ( scanf("%d %d %d",&n,&m,&t) != EOF){
        if( n==0 && m==0 & t==0) break;

        for (int i = 1; i <=n ; ++i) {
            scanf("%s", maze[i]+1);
        }

        success = false;

        int sx,sy;
        //destination
        for (int i = 1; i <=n ; ++i)
            for (int j = 1; j <=m ; ++j)
                if(maze[i][j] == 'D'){
                    sx = i; sy = j;
                }
        //start
        for (int i = 1; i <=n ; ++i) {
            for (int j = 1; j <=m ; ++j) {
                if( maze[i][j] == 'S' ) { //this branch will only run once
                    maze[i][j] = 'X';
                    DFS(i,j,0);
                }
            }

        }
        puts(success == true? "YES": "NO");
    }
    return 0;
}

