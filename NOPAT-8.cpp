//哈夫曼树，第一行输入一个数 n，表示叶结点的个数。需要用这些叶结点生
//成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即 weight，题目需要输出
//所有结点的值与权值的乘积之和。

//input
//输入有多组数据。每组第一行输入一个数 n，接着输入 n 个叶节点（叶节点权值不超过 100，2<=n<=1000）
//sample input:
//5
//1 2 2 5 9

//sample output
//37

#include "stdio.h"
#include "queue"

using namespace std;
priority_queue<int,vector<int>, greater<int> > q;

int main(){
    int temp;
    int num;

    while( scanf("%d",&num) != EOF){

        //clear last record
        while(!q.empty()) q.pop();
        int total = 0;


        while(num > 0){
            scanf("%d",&temp);
            q.push(temp);
            num--;
        }

        while (q.size() > 1){
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();

            total += a+b;
            q.push(a+b);
        }
        printf("%d\n",total);
    }

    return 0;
}