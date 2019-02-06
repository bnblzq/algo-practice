
#include "stdio.h"
#include "cstring"

struct student{
    char name[20];
    char gender;
    char id[20];
    int score;
}temp,high_female,low_male;


int main(){
    int count;
    scanf("%d",&count);

    high_female.gender='F';
    high_female.score=0; //set to 0
    strcpy(high_female.name, "none");

    low_male.gender='M';
    low_male.score=100; //set to max
    strcpy(low_male.name, "none");

    for (int i = 0; i < count; ++i) {
        scanf("%s %c %s %d",& temp.name, & temp.gender, & temp.id, & temp.score);

        //find low and high?
        if(temp.gender == 'F')
            if(temp.score >= high_female.score) high_female = temp;
        if(temp.gender == 'M')
            if(temp.score <= low_male.score) low_male = temp;

    }
    //handle some sort of absence
    if(strcmp(high_female.name, "none") == 0) //absence of female
        printf("Absent\n");
    else printf("%s %s\n",high_female.name,high_female.id);

    if(strcmp(low_male.name, "none") == 0) //absence of male
        printf("Absent\n");
    else printf("%s %s\n",low_male.name,low_male.id);

    //print gap score
    if(strcmp(high_female.name,"none") ==0 ||
        strcmp(low_male.name,"none") ==0 )
        printf("NA\n");
    else printf("%d", high_female.score-low_male.score);

    return 0;
}
