
#include "stdio.h"

struct pNode{
    char name[16];
    int hh;
    int mm;
    int ss;
}temp,morning,evening;

bool greater(pNode a,pNode b){
    if(a.hh!=b.hh) return a.hh>b.hh;
    else if(a.mm!=b.mm) return a.mm>b.mm;
    else return a.ss>b.ss;
}

int main(){
    int count;
    scanf("%d",&count);

    morning.hh=24;
    morning.mm=60;
    morning.ss=60;

    evening.hh=0;
    evening.mm=0;
    evening.ss=0;

    for (int i = 0; i <count; ++i) {
        scanf("%s %d:%d:%d", &temp.name, &temp.hh, &temp.mm, &temp.ss);

        //some stuff about finding bigget and evening
        if(greater(temp,morning) == false) morning = temp;

        scanf("%d:%d:%d",  &temp.hh, &temp.mm, &temp.ss);
        if(greater(temp, evening)== true) evening = temp;
    }

    printf("%s %s",morning.name, evening.name);
    return 0;
}
