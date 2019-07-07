#include<iostream>
#include<stdio.h>
using namespace std;
void test(){
//c语言类型转换
int i=1;
double d=i;
printf("%d,%2f\n",i,d);
int *p=&i;
int address=p;
printf("%x,%d\n",p,address);
}
//c++
//static_cast用于非多态类型的转换(静态转换),但是不能用于两个不相关类型
//的转换
void test2(){
double d=12.34;
int a=static_cast<int> (d);
cout<<a<<endl;
}
//reinterpret_cast操作符通常为操作数的位模式提供较低层次的重新解释，用于将
//一种类型转换为另一种不同的类型
typedef void(*FUNC)();
int dosomething(int i){
cout<<"do dosomething"<<endl;
return 0;
}
void test3(){
FUNC( ) f=reinterpret_cast<FUNC>(dosomething);
f();
}
//const_cast
//删除变量的const属性方便赋值
void test4(){
const int a=3;
int *p=const_cast<int*>(&a);
*p=3;
cout<<a<<endl;
}
//dynamic_cast用于将一个父类对象的指针转换为子类对象的指针或引用(动态转换)
//向上转型：子类对象指针->父类指针/引用(不需要转换，赋值兼容规则) 向下转型：
//父类对象指针->子类指针/引用(用dynamic_cast转型是安全的)
// dynamic_cast只能用于含有虚函数的类 2. dynamic_cast会先检查是否能转换成功
// ，能成功则转 换，不能则返回0
class A{
public:
virtual void fuc(){
}
};
class B:public A{
  void fuc(A*pa){
B*pb1=static_cast<B*>(pa);
B*pb2=dynamic_cast<B*>(pa);
cout<<"pb1:"<pb1<<"\n";
cout<<"pb2:"<pb2<<"\n";
  }
};
void test5(){
  A a;
  B b;
  func(&a);
  func(&b);
}
int main(){
  return 0;
}
