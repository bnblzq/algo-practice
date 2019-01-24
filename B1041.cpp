
#include <stdio.h>

struct student{
    long  long id;
    int test;
    int exam;
}stu[1024];

int main(){
    int num;
    scanf("%d",&num);

    for(int i=0;i< num;++i){
        long long id;
        int test;
        int exam;
        scanf("%lld %d %d",&id, & test, &exam);

        stu[test].id    = id;
        stu[test].exam  = exam;

    }

    //number to check
    int check;
    scanf("%d",&check);
    for(int i =0;i<check;++i){
        int _check;
        scanf("%d",&_check);
        printf("%lld %d\n",stu[_check].id, stu[_check].exam);
    }
    return 0;
}
