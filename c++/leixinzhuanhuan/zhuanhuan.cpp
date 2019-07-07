#include<iostream>
using namespace std;
typedef void(*func)();
int dosomething(int i){
  cout<<"dosomething"<<endl;
  return 0;
}
void test1(){
  func f;
 f=reinterpret_cast<func>(dosomething);
//reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//  // 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
f();
(*f)();
}
void Test ()
{
 double d=1.11;
 int i=d;
 int i2=static_cast<int> (d);//对隐式类型的转换是相近类型的转换同c
 int *p=reinterpret_cast<int*> (i2);//reinterpret两种不相关类型的转换

const int x=10;
const int*cp1=&x;
//int *px=&x;//权限放大不可以
int *p1x=const_cast<int*>(cp1);//去掉const属性
*p1x=20;
cout<<x<<endl;//10
cout<<*p1x<<endl;//20
//此处是10 20是编译器的过度优化
volatile const int x1=10;
volatile const int *cp2=&x1;
int *p2x=const_cast<int*>(cp2);
*p2x=20;
cout<<x1<<endl;//20
cout<<*p2x<<endl;//20
}
class A{
  public:
    void f(){}
protected:
int _a;
};
class B:public A{
  public:
int _b;
};
//dynamic_cast动态转换--->继承关系的转换,必须构成多态
void test2(){
A *pa1=new A;//错误如果指向父类会越界
B* pb=(B*)pa1;//
A* pa2=new B;//子类可以切片
B* pb2=(B*)pa2;
}
class A1{
  public:
   virtual  void f(){}
protected:
int _a;
};
class B1:public A1{
  public:
    void f(){}
  protected:
int _b;
};
void test3(){
  A1* pa1=new A1;
  B1* pb1=dynamic_cast<B1*>(pa1);
  cout<<pb1<<endl;//0
  A1* pa2=new B1;
  B1*pb2=dynamic_cast<B1*>(pa2);
  cout<<pb2<<endl;//0x1536c40
}
//自己实现dynamic_cast-->造轮子
//可看成是拷贝构造,但是不行拷贝构造的返回值无法确定,可以考虑函数魔板
class A3{
  public:
    virtual void f(){}
    virtual bool is_base(){
      return true;
    }
  protected:
    int _a;
};
class B3:public A3{
  public:
    virtual bool is_base(){
return  false;
}
protected:
int _b;
};
//dynamic_case-->本质实现父类指针指向子类指针,那么只需要保证一个指针,在指向父
//类的时候为对的指向子类时候为错,则定义形成一个多态,然后在指向父类的中的函数
//为空子类则返回p就可以实现轮子
template<class PDiver,class Base>
PDiver my_dynamic_cast(Base*p){
  if(p->is_base()){
    return NULL;
  }
  else{
    return PDiver(p);
  }
}
void test4(){
  A3* pa1=new A3;
  B3* pb1=my_dynamic_cast<B3*>(pa1);
  cout<<pb1<<endl;//0
  A3* pa2=new B3;
  B3*pb2=my_dynamic_cast<B3*>(pa2);
  cout<<pb2<<endl;//0x1536c40
//cout<<typeid(pb2).name()<<endl;
}
//explicit关键字阻止经过转换构造函数进行的隐式转换的发生
class A4{
  public:
    explicit A4(int a){
      cout<<"A4(int a)"<<endl;
    }
    A4(const A4&a){
      cout<<"A(const A&a)"<<endl;
    }
  private:
    int _a;
}; 
void test5(){
  A a1(1);
//隐式转换-> A tmp(1);
//A a2(tmp);
  A a2=1;
}
int main(){
Test();
test1();
test3();
test4();
return 0;
}

