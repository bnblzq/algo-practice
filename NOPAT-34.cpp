/*
大家一定觉的运动以后喝可乐是一件很惬意的事情，但是 seeyou 却不这么
认为。因为每次当 seeyou 买了可乐以后，阿牛就要求和 seeyou 一起分享这一瓶
可乐，而且一定要喝的和 seeyou 一样多。但 seeyou 的手中只有两个杯子，它们
的容量分别是 N 毫升和 M 毫升 可乐的体积为 S （S<101）毫升(正好装满一
瓶) ，它们三个之间可以相互倒可乐 (都是没有刻度的，且 S==N+M，101＞S
＞0，N＞0，M＞0) 。聪明的 ACMER 你们说他们能平分吗？如果能请输出倒可
乐的最少的次数，如果不能输出"NO"。

三个整数 : S 可乐的体积 , N 和 M 是两个杯子的容量，以"0 0 0"结束。

如果能平分的话请输出最少要倒的次数，否则输出"NO".

sample in:
7 4 3
4 1 3
0 0 0

sample out:
NO
3*/

#include "stdio.h"
#include "queue"
using namespace std;

bool mark[101][101][101];
struct status{
    int a,b,c;
    int times;
};

queue<status> q;

void AtoB(int &a, int vola,int &b,int volb){  //a->b
    if( volb - b >= a){
        b +=a;  //not fullfill volb one time, we may miss some statue ?
        a=0;
    }
    else{
        a = a- (volb-b);
        b= volb;
    }
    return;
}

int bfs(int vol, int n,int m){
    while ( !q.empty()){
        status tmp = q.front(); q.pop();
        int a,b,c;
        a=tmp.a;
        b=tmp.b;
        c=tmp.c;

        AtoB(a,vol,b,n);  //a->b
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

        a= tmp.a;
        b= tmp.b;
        c=tmp.c;
        AtoB(b,n,a,vol); //b->a
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

        a= tmp.a;
        b= tmp.b;
        c=tmp.c;
        AtoB(a,vol,c,m); //a->c
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

        a= tmp.a;
        b= tmp.b;
        c=tmp.c;
        AtoB(c,m,a,vol);  //c->a
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

        a= tmp.a;
        b= tmp.b;
        c=tmp.c;
        AtoB(b,n,c,m);//b->c
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

        a= tmp.a;
        b= tmp.b;
        c=tmp.c;
        AtoB(c,m,b,n); //c->b
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;

            status now;
            now.a = a;
            now.b =b;
            now.c =c;
            now.times = tmp.times +1;  //suffer through AtoB
            if(a == vol/2 && b== vol/2) return now.times;
            if(a == vol/2 && c== vol/2) return now.times;
            if(b == vol/2 && c== vol/2) return now.times;

            //another status
            q.push(now);
        }

    }
    return  -1;
}


int main(){
    int vol,n,m;
    while( scanf("%d %d %d", &vol, &n, &m) !=EOF){
        if(vol ==0 ) break;
        if( vol % 2 ==1){puts("NO");continue;}

        for (int i = 0; i <= vol  ; ++i)
            for (int j = 0; j <= n ; ++j)
                for (int k = 0; k <=m ; ++k)
                    mark[i][j][k] = false;

        status tmp;
        tmp.a = vol;
        tmp.b = 0;
        tmp.c = 0;
        tmp.times = 0;

        while (!q.empty()) q.pop();

        q.push(tmp);
        mark[vol][0][0] = true;

        int ret = bfs(vol,n,m);
        if(ret == -1) printf("NO\n");
        else printf("%d\n",ret);
    }
    return 0;
}