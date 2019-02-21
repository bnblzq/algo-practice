
//把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错。这个
//工作现在要让计算机来完成，得看你的了。


//input:输入是一个个的三元组，分别是，外筐尺寸 n（n 为满足 0<n<80 的奇整数），
//中心花色字符，外筐花色字符，后二者都为 ASCII 可见字符；
//e.g : 11 B A

//more details check the same photo under picture directory

/*--------------------output   this is bird-eye view,which means a circle spans across multiple lines

 AAAAAAAAA

ABBBBBBBBBA

ABAAAAAAABA

ABABBBBBABA

ABABAAABABA

ABABABABABA

ABABAAABABA

ABABBBBBABA

ABAAAAAAABA

ABBBBBBBBBA

 AAAAAAAAA

  -------------------*/




#include "stdio.h"

int main(){
    char buf[81][81];
    char a,b;
    int n;
    bool firstcase = true;

    while (scanf("%d %c %c",&n,&a,&b) ==3) {
        //control first line
        if (firstcase == true) firstcase = false;
        else printf("\n");

        for (int i = 1, j = 1; i <= n; i += 2, j++) {  //i for measuring line length , j for expanding the square
            //central coordinate
            int x = n / 2 + 1;   //we know n is odd from topic
            int y = n / 2 + 1;

            //upper left coordinate
            x -= j - 1;
            y -= j - 1;

            //choose a or b to fill in
            char c = (j % 2 == 1) ? a : b;

            //start to fill from upper left to lower right
            for (int k = 1; k <= i; k++) {
                buf[x + k - 1][y] = c;  //up line
                buf[x + k - 1][y + i - 1] = c;  //low line
                buf[x][y + k - 1] = c;  //left line
                buf[x + i - 1][y + k - 1] = c;  //right line
            }
        }

        if (n != 1) {
            buf[1][1] = ' ';
            buf[1][n] = ' ';
            buf[n][1] = ' ';
            buf[n][n] = ' ';
        }

        //print
        for (int z = 1; z <= n; z++) {
            for (int q = 1; q <= n; q++)
                printf("%c", buf[z][q]);

            printf("\n");
        }

    }
    return 0;
}