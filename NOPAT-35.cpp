/*
A ring is compose of n circles as shown in diagram. Put natural number 1, 2, ..., n
into each circle separately, and the sum of numbers in two adjacent circles should be a prime.

Note: the number of first circle should always be 1.

n (1 < n < 17).

The output format is shown as sample below. Each row represents a series of

circle numbers in the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy
the above requirements. Print solutions in lexicographical order.
You are to write a program that completes above process. Print a blank line after each case.

sample in:
6
8

sample out:
case: 1
1 4 3 2 5 6
1 6 5 2 3 4
case: 2
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2

 */

#include "stdio.h"
int n;
bool hash[22];
int ans[22];

int prime[13]= {2,3,5,7,11,13,17,19,23,29,31}; //13 numbers

bool judge( int a){
    for (int i = 0; i < 13 ; ++i) {
        if( a == prime[i]) return  true;
    }
    return  false;
}

void check(){
    if( judge( ans[n] + ans[1]) == false) return;

    for (int i = 1; i <= n; ++i) {
        if( i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

void DFS(int num){
    if( num > 1){
        //check prime
        if( judge(ans[num] + ans[num-1]) == false) return; //abadon the num, return to previous level and switch another
    }
    
    if( num == n) {
        // recurse to bottom level
        check();
        return;
    }

    for (int i = 2; i <=n ; ++i) {  //n should involved into the circle
        if(hash[i] == false){
            hash[i] = true;
            ans[num+1] = i;
            DFS(num+1);
            hash[i] = false; //this loop travels from i~n, which means when you returned from DFS, the "i" must be a wrong answer,so we try "i+1" until the scale of recursion
                             //reachs n,then check ans[n] and ans[1]
        }
    }
}


int main(){
    int _case =0;

    while ( scanf("%d", &n) != EOF){
        _case ++;

        for (int i = 0; i < 22; ++i)  hash[i] = false;

        ans[1] = 1;
        printf("case: %d\n",_case);
        hash[1] = true;

        DFS(1) ; //which means there is one number inside
        printf("\n");
    }
    return 0;
}