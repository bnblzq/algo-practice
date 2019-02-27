
/*-------------
  FatMouse prepared M pounds of cat food, ready to trade with the cats guarding

the warehouse containing his favorite food, JavaBean.

The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans

and requires F[i] pounds of cat food. FatMouse does not have to trade for all the

JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays

F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this

homework to you: tell him the maximum amount of JavaBeans he can obtain.
 ------------------------*/

//  input
/* The input consists of multiple test cases. Each test case begins with a line

   containing two non-negative integers M and N. Then N lines follow, each contains

   two non-negative integers J[i] and F[i] respectively. The last test case is followed by

   two -1's. All integers are not greater than 1000.

   53 72
   43 52
   20 3
   25 18
   24 15
   15 10
   -1 -1
 */

//output
/*For each test case, print in a single line a real number accurate up to 3 decimal

  places, which is the maximum amount of JavaBeans that FatMouse can obtain.

  13.333

  31.500

  */

#include "algorithm"
#include "stdio.h"

using  namespace std;

struct good{
    double store;
    double value;
    double ppr ; //store/value

    bool operator < (const struct good &A) const {
        return ppr > A.ppr;
    }

}buf[1001];

int main(){

    double money;
    int room;


    while ( scanf("%lf %d",& money,& room) != EOF) {  //many ronuds
        if(money == -1 && room == -1) break;

        for (int i = 0; i < room; ++i) {
            scanf("%lf %lf",&buf[i].store, &buf[i].value);
            buf[i].ppr = buf[i].store / buf[i].value;
        }

        sort(buf,buf+ 1001);

        //purchase
        int index = 0;
        double total = 0;

        while ( money> 0 && index <room ){
            if(money > buf[index].value){
                total += buf[index].store;
                money -= buf[index].value;
            }else{

                total += buf[index].store / buf[index].value * money;
                money =0;
            }
            index ++;
        }
        printf("%.3lf\n",total);

    }


    return  0;
}