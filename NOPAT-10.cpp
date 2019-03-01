//输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历
//输入第一行包括一个整数 n(1<=n<=100)。接下来的一行包括 n 个整数

//output
//可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，
//并对二叉排序树进行前序、中序和后序遍历。每种遍历结果输出一行。每行最后一个数据之后有一个空格。

//sample input
//5
//1 6 5 9 8

//sample output
/*----
 16598
 15689
 58961
 ------*/


#include "stdio.h"
#include "queue"

struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}Tree[101];

int loc =0;
Node * create(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void pre(Node * T){
    printf("%d ",T->data);

    if(T->lchild) pre(T->lchild );

    if(T->rchild) pre(T->rchild);
}
void in(Node * T){

    if(T->lchild) in(T->lchild );
    printf("%d ",T->data);
    if(T->rchild) in(T->rchild);
}
void post(Node * T){

    if(T->lchild != NULL) post(T->lchild );
    if(T->rchild != NULL) post(T->rchild);
    printf("%d ",T->data);
}

Node * insert(Node * T,int x){

    //encounter NUll pointer
    if(T == NULL){
        T=create();
        T->data = x;
        return T;
    }else if(T->data > x){
        //recurse compare until finding a proper location
        T->lchild = insert(T->lchild,x);
    }else if(T->data < x)
        T->rchild = insert(T->rchild,x);


    return T;
}

int main(){

    Node * T = NULL;
    int num;
    scanf("%d",&num);

    for(int i=0; i<num; ++i) {
        int temp;
        scanf("%d", &temp);

        T = insert(T, temp);

    }
    //pre
    pre(T);
    printf("\n");

    //in
    in(T);
    printf("\n");

    //post
    post(T);
    printf("\n");

    return 0;
}