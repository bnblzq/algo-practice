#include "stdio.h"

struct person{
    char name[20];
    int yy;
    int mm;
    int dd;
}oldest,youngest,l_margin,r_margin,temp;

void init(){
    //according to topic,age should between 1814 to 2014
    l_margin.yy=youngest.yy = 1814;
    r_margin.yy = oldest.yy = 2014;

    l_margin.mm = r_margin.mm = youngest.mm=oldest.mm = 9;

    l_margin.dd = r_margin.dd = youngest.dd = oldest.dd = 6;
}



bool left_check(person p ,person left){
    if(p.yy != left.yy) return p.yy <= left.yy;
    else if(p.mm != left.mm) return p.mm <=left.mm;
    else if(p.dd != left.dd) return p.dd <= left.dd;

    //yy mm dd all equal
    return false;

}

bool right_check(person p, person right){
    if(p.yy != right.yy) return p.yy >=right.yy;
    else if(p.mm != right.mm) return p.mm >= right.mm;
    else if(p.dd != right.dd) return p.dd >= right.dd;

    return false;
}

bool judge_pass(person p){

    //left margin check
    if( left_check(p,l_margin)) return false;

    //right margin check
    if( right_check(p,r_margin)) return  false;

    return true ;
}

void update_data(person p){
    if(!left_check(p,youngest)) youngest = p;
    if(!right_check(p,oldest)) oldest = p;
    return;
}

int main(void){
    init();
    int num=0;
    scanf("%d",&num);

    int count=0; //count for the pass people

    for(int i=0;i<num;++i){
        scanf("%s %d/%d/%d",&temp.name, &temp.yy , &temp.mm, &temp.dd);
        if(! judge_pass(temp)) continue;

        //update oldest and youngest
        update_data(temp);
        count ++;
    }

    if(count == 0) printf("0\n"); //in case of nobody matched
    else printf("%d %s %s\n",count,oldest.name,youngest.name);

    return 0;
}

