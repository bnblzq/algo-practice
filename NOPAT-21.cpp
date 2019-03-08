
//简单的文件IO的练习


#include "stdio.h"
#include "string"
using namespace std;
FILE * ins;

struct stuinfo{
    char firstname[20];
    char lastname[20];
    int age;
    char birth[20];
}stu[10];

void writest(FILE * out){
    fprintf(out,"%s %s %d %s","aaa","bbb" ,24, "930724");
}
void printout(int count){

    for (int i = 0; i < count; ++i) {
        printf("%s %s %d %s\n", stu[i].firstname, stu[i].lastname,stu[i].age, stu[i].birth);
    }
}

bool cmp(stuinfo a,stuinfo b){
   // if( !a || !b) return a.firstname > b.firstname;
    return a.firstname > b.firstname;
}

int main(){

    ins =  fopen("/Users/liusijian/test","r+");
    if(ins == NULL) printf("fail\n");
    else printf("done\n");


  /*  int index =0;
    while ( fscanf(ins,"%s %s %d %s",&stu[index].firstname,stu[index].lastname,&stu[index].age,stu[index].birth) !=EOF){
        index++;
    }

    sort(stu,stu+index,cmp);
    printout(index);*/

  char line[25];

  while (fgets(line,25,ins) != NULL){
      fputs(line,stdout); //line contains a \n,and puts also appends a \n
  }

    if(!fclose(ins)) printf("close done \n");
    return 0;
}