
/*虚继承
 construt A
 construt A2
 construt A1  注意这里，并没有2次调用A的构造函数
 constuct C

 destuct C
 destrut A1
 destrut A2
 destrut A


 */

#include "stdio.h"
#include "iostream"
using namespace std;

class A{
public:

    A(){cout <<" construt A"<<endl;}
    ~A(){cout <<" destrut A"<<endl;}
};

class A1: public virtual A{
public:

    A1(){cout <<" construt A1"<<endl;}
    ~A1(){cout <<" destrut A1"<<endl;}
};

class A2 : public virtual A{
public:

    A2(){cout <<" construt A2" <<endl;}
    ~A2(){cout <<" destrut A2" <<endl;}
};

class C: public A2,public A1{
public:
    C(){ cout<< "constuct C"<<endl; }
    ~C(){ cout<< "destuct C"<<endl; }

};

int main(){
    C c;

    return 0;
}
