
/*
 * 有一群人，打乒乓球比赛，两两捉对撕杀，每两个人之间最多打一场比赛。
球赛的规则如下：如果 A 打败了 B，B 又打败了 C，而 A 与 C 之间没有进
行过比赛，那么就认定，A 一定能打败 C。
如果 A 打败了 B，B 又打败了 C，而且，C 又打败了 A，那么 A、B、C 三
者都不可能成为冠军。
根据这个规则，无需循环较量，或许就能确定冠军。你的任务就是面对一群
比赛选手，在经过了若干场撕杀之后，确定是否已经实际上产生了冠军。

输入含有一些选手群，每群选手都以一个整数 n(n<1000)开头，后跟 n 对选
手的比赛结果，比赛结果以一对选手名字（中间隔一空格）表示，前者战胜后者。
如果 n 为 0，则表示输入结束。


对于每个选手群，若你判断出产生了冠军，则在一行中输出“Yes”，否则在
一行中输出“No”。

 sample in:

    3
    Alice Bob
    Smith John
    Alice Smith
    5
    ac
    cd
    de
    be
    ad
    0

sample out:
    Yes
    NO
 */

#include "stdio.h"
#include "string"
#include "map"

int in [2002];
using namespace std;
map<string,int> M;

void clear(){
    for (int i = 0; i < 2002; ++i) {
        in[i] = 0;
    }
    M.clear();
}


int main(){

    int num;
    char s1[10],s2[10];

    while (scanf("%d",&num) !=EOF && num !=0){
        clear();
        int idx =0;

        for (int i = 0; i < num; ++i){

            scanf("%s %s", s1, s2);
            string str1 = s1;
            string str2 = s2;

           if(M.find(str1) == M.end()){
               //not exist
               M[str1] = idx ++;

           }

           int idx2 = 0;

           if(M.find(str2) == M.end()){
               idx2 = idx;
               M[str2] = idx++;

           }else idx2 = M[str2];

           in[idx2] ++;  //DAG 's end point means lose. so ++ means lost to someone ,number means times

        }

        int count = 0;
        for (int j = 0; j < idx; ++j) {
            if( !in[j]) count ++;  //if the factor =0,it is always the winner,but we wannan to find the unique
        }

        printf("%s", count==1? "YES":"NO");
        printf("\n");

    }
    return 0;
}

