
#include "vector"
#include "stdio.h"
#include "algorithm"
struct info{
    char name[20];
    char id[20];
    int score;
}temp;

using namespace std;

bool compare(info first,info second){
    return first.score>second.score;
}
int main()
{
    int num;
    scanf("%d",&num);
    vector<info> test;

    for(int i=0; i<num; ++i){
        scanf("%s %s %d",&temp.name,&temp.id,&temp.score);
        test.push_back(temp);
    }

    //sort out
    sort(test.begin(),test.end(),compare);
    printf("%s %s\n",test.front().name,test.front().id);
    printf("%s %s\n",test.back().name,test.back().id);
    return 0;
}

