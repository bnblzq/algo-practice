
//输入 N 个学生的信息，然后进行查询。
/*----------
 * 输入的第一行为 N，即学生的个数(N<=1000)

接下来的 N 行包括 N 个学生的信息，信息格式如下：

01 李江 男 21

02 刘唐 男 23

03 张军 男 19

04 王娜 女 19

然后输入一个 M(M<=10000),接下来会有 M 行，代表 M 次查询，每行输入

一个学号，格式如下：

02

03

01

04
 --------------*/

/*---------
 输出 M 行，每行包括一个对应于查询的学生的信息。

 如果没有对应的学生信息，则输出“No Answer!”
 ---------*/






#include "algorithm"
#include "stdio.h"

using  namespace std;

struct  stu{
    int id;
    char name[20];
    char sex[5];
    int age;
    bool exist;
}buf[1001];

bool cmp(stu A, stu B){
    if( !A.exist || !B.exist) return A.exist > B.exist;
    return  A.id < B.id;
}

int main(){
    int input_num;
    scanf("%d",&input_num);

    for(int i=0;i< 1001; ++i) buf[i].exist = false;

    for(int i =0;i<input_num;++i){
        scanf("%d %s %s %d",&buf[i].id, &buf[i].name, &buf[i].sex, &buf[i].age );
        buf[i].exist = true;
    }

    sort(buf,buf+1001,cmp);

    //search num
    int output_num;
    scanf("%d",&output_num);

    int count =0;

    for (int j = 0; j <output_num ; ++j) {

        int target;
        scanf("%d",&target);

        //binary search
        int base= 0;
        int top = input_num -1;

        while( base <= top){
            int mid = (base + top) /2;
            if(buf[mid].id ==  target ){
                //print and break;
                printf("%d %s %s %d\n",buf[mid].id, buf[mid].name, buf[mid].sex, buf[mid].age);
               // count ++;
                break;
            }

            if( buf[mid].id < target){
                base = mid+1;

            }else { // >
                top = mid -1;
            }
        }

        if(base > top){printf("No Answer!\n");}


    }

    //printf("total %d\n",count );


    return 0;
}