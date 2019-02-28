
/*两个字符串，其长度 n 均小于等于 26。
  第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表示：A，B，C....最多 26 个结点

  输入样例可能有多组，对于每组测试样例，输出一行，为后序遍历的字符串
  ------*/

/*sample input
ABC
BAC
FDXEAG
XDEFAG
 ---------*/

/* sample output
 BCA
 XEDGAF
 ---------*/


#include "stdio.h"
#include "cstring"

#ifdef DEBUG
#define _printf printf
#else
#define _printf
#endif

char str1[30],str2[30];
int loc=0;

struct Node{
    struct Node * lchild;
    struct Node * rchild;
    char c;
}Tree[50];

void postOrder(Node * T){
    if(T->lchild) postOrder(T->lchild);
    if(T->rchild) postOrder(T->rchild);
    printf("%c",T->c);
}

Node * create(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return & Tree[loc++];
}

Node * build( int s1,int e1,int s2,int e2){ //pre  in
    _printf("now loc:%d\n",loc);
    Node * ret = create();
    ret->c= str1[s1];   //root node

    //confirm root node's location in inorder sequence
    int index=0;
    for(int i =s2;i<=e2;i++){ //not from 0,because the recuring string would not start from 0
        if(str2[i] == str1[s1]){
            index =i; break;
        }
    }

    //confirm left & right subtree
    // |s1= index----------e1|
    // |s2---------index--------e2|
    if( index != s2){
        _printf("left part,index %d\n",index);
        ret->lchild = build(s1+1, s1+(index-s2), s2,index-1);
    }
    if(index != e2){
        ret->rchild = build(s1+(index-s2)+1, e1, index+1, e2);
    }
    return ret;

}
int main(){
    while (scanf("%s",str1) != EOF){
        scanf("%s",str2);

        loc= 0;

        int len1= strlen(str1);
        int len2= strlen(str2);

        Node * T = build(0,len1-1,0, len2-1);
        postOrder(T);
        printf("\n");
    }
}