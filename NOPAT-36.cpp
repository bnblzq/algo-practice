/*

The GeoSurvComp geologic survey company is responsible for detecting
underground oil deposits. GeoSurvComp works with one large rectangular region of
land at a time, and creates a grid that divides the land into numerous square plots. It
then analyzes each plot separately, using sensing equipment to determine whether or
not the plot contains oil. A plot containing oil is called a pocket. If two pockets are
adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and
may contain numerous pockets. Your job is to determine how many different oil
deposits are contained in a grid.


The input file contains one or more grids. Each grid begins with a line containing
m and n, the number of rows and columns in the grid, separated by a single space. If
m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100.
Following this are m lines of n characters each (not counting the end-of-line
characters). Each character corresponds to one plot, and is either `*', representing the
absence of oil, or `@', representing an oil pocket.



For each grid, output the number of distinct oil deposits. Two different pockets
        are part of the same oil deposit if they are adjacent horizontally, vertically, or
diagonally. An oil deposit will not contain more than 100 pockets.


sample in:
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

sample out:
0
1
2
2*/


#include "stdio.h"

char maze[101][101];
bool mark[101][101];

int g_row,g_col;

int path[][2]={
        1, 0,
        -1,0,
        0, 1,
        0, -1,
        1,  1,
        -1, 1,
        1,  -1,
        -1, -1
};

void DFS(int row,int col){

    //8 directions
    int nx;
    int ny;
    for (int i = 0; i < 8; ++i) {
        nx = row + path[i][0];
        ny = col + path[i][1];

        if(mark[nx][ny] == true) continue;
        if( nx<1 || nx > g_row || ny <1 || ny > g_col) continue;  //nx is not like a coordinate in xoy system,
                                                                    // nx+1 means walk a line from verical direction,
                                                                    // ofcourse it shouldn't larger than row.so is the ny
        if(maze[nx][ny] == '*') continue;

        mark[nx][ny] = true;
        DFS(nx, ny);

    }
    return;
}
int main(){


    while (scanf("%d %d", &g_row,&g_col) != EOF){
        if ( g_row ==0 && g_col==0) break;

        for (int i = 1; i <=g_row ; ++i) {
            scanf("%s", maze[i]+1);
        }

        for (int i = 1; i <= g_row; ++i)
            for (int j = 1; j <= g_col; ++j)
                mark[i][j] = false;

        int ans =0;
        //recursion
        for (int i = 1; i <= g_row; ++i) {
            for (int j = 1; j <= g_col; ++j) {
                if(mark[i][j] == true) continue;
                if(maze[i][j] == '*') continue;
                DFS(i,j);  //when jumping out from here, it has confirm a series of @
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
