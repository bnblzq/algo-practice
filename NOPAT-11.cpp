/*判断两序列是否为同一二叉搜索树序列
开始一个数 n，(1<=n<=20) 表示有 n 个需要判断，n= 0 的时候输入结束。
接下去一行是一个序列，序列长度小于 10，包含(0~9)的数字，没有重复数字，
根据这个序列可以构造出一颗二叉搜索树。
接下去的 n 行有 n 个序列，每个序列格式跟第一个序列一样，请判断这两个
序列是否能组成同一颗二叉搜索树。

 如果序列相同则输出 YES，否则输出 NO
 */

/* sample input
 2
 567432
 543267
 576342
 0

 */

//sample output
//YES
//NO



#include "stdio.h"
#include "string.h"

struct  Node{
    struct Node *lchild;
    struct Node * rchild;
    int data;
}Tree[21];

int loc=0;//used to index static tree

char tmp[12];
char str1[25],str2[25];
int size1,size2;
char *str;
int * size;


Node* create(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node * insert(Node * T,int x){
    if(T == NULL){
        T=create();
        T->data =x;
    }
    else if(T->data > x) T->lchild = insert(T->lchild,x);
    else if(T->data < x) T->rchild = insert(T->rchild,x);

    return T;
}

void preOrder(Node * T){
    str[(*size) ++] = T->data;

    if(T->lchild) preOrder(T->lchild);
    if(T->rchild) preOrder(T->rchild);
}

void inOrder(Node * T){
    if(T->lchild) inOrder(T->lchild);
    str[ (*size) ++] = T->data;
    if(T->rchild) inOrder(T->rchild);
}



int main(){
    int num;

    while( scanf("%d",&num)!= EOF && num !=0){
        //mother pattern
        loc =0;

        Node *T = NULL;
        scanf("%s",tmp);

        for(int i =0;tmp[i] != '\0';++i){
            T=insert(T, tmp[i]-'0');
        }

        size1 = 0; //dont forget this. for removing last record
        size = &size1;
        str = str1;
        preOrder(T);
        inOrder(T);
        str[*size]= 0;

        //sub sequence
        while(num-- > 0){
            scanf("%s",tmp);
            Node * T2= NULL;

            for(int i=0; tmp[i] != '\0'; ++i){
                T2=insert(T2,tmp[i]-'0');
            }


            size2 = 0;
            size = &size2;
            str = str2;
            preOrder(T2);
            inOrder(T2);
            str[*size] = 0;

            printf("%s\n",strcmp(str1,str2) ==0 ? "YES":"NO");

        }
    }


    return 0;

}