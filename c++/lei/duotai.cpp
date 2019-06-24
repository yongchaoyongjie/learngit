#include<iostream>
using namespace std;
//class Person{
//  public:
//    virtual void buyticket(){
//      cout<<"卖票全价"<<endl;
//    }
//};
//class Students:public Person{
//virtual  void buyticket(){
//  //子类的虚函数重写了父类虚函数
//    cout<<"卖票半价"<<endl;
//  }
//};
//void function(Person&p){
//p.buyticket();
//}
//void test(){
//Person ps;
//Students st;
//function(ps);
//function(st);
//}
//虚函数重写的两个例外1协变,重写要求函数名返回值参数都是一样的
//协变是函数名参数一样但是返回值不一样,返回值必须是一个继承关系的基类和派生类的指针
//和引用
//class A{};
//class B :public A{};
////class B {};//ab没有继承关系,返回值也没有继承关系则student::f重写虚函数返回类
////型有差异,但是不是来自person的协变
//class Person{
//  public:
//    virtual A *f(){
//      return new A;
//    }
//};
//class Student:public Person{
//  public:
//    virtual B*f(){
//      return new B;
//    }
//};
//void test2(){
//  Person *p=new Person;//调用和对象有关,指向person调person
//  p->f();
//  Student*s=new Student;
//  s->f();//指向person调的是student为什么?-->构成多态跟对象有关,不构成多态跟
// //本身的类型有关 
//  //
//}
//final修饰虚函数表示虚函数不能被继承
//class Car{
//  public:
//    virtual void Drive()final{
//    }
//};
//class benz:public Car{
//  public:
//    virtual void Drive(){
//cout<<"shufu "<<endl;
//    }
//};
//class Car{
//  public:
//    virtual void Drive(){
//      cout<<"che"<<endl;
//    }
//};
//class benz:public Car{
//  public:
//    virtual void Drive(){
//cout<<"shufu "<<endl;
//    }
//};
//void test1(){
//Car c;
//benz d;
//c.Drive();
//d.Drive();
//}
//抽象类
//在虚函数的后面写上 =0 ，则这个函数为纯虚函数。包含纯虚函数的类叫做抽象类（也叫接口类），抽象类
//不能实例化出对象。派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象。纯
//虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承
class Car{
  public:
    virtual void Drive()=0;
};
class benz :public Car{
  public:
    virtual void Drive(){
      cout<<"shufu "<<endl;
    }
};
class bwm :public Car{
  public:
    virtual void Drive(){
      cout<<"bwm-caozuo"<<endl;
    }
};

void test2(){
  benz c;
  c.Drive();
  bwm d;
  d.Drive();
  Car*pbenz=new benz;
  pbenz->Drive();
  Car*pbwm=new bwm;
  pbwm->Drive();
}
class Base{
  public:
    virtual void fun1(){
    }
  private:
    int _b=1;
};
void test3(){
  Base b;
  cout<<sizeof(b)<<endl;
}
int main(){
//test();
//test1();
//test2();
test3();//int 8字节 虚函数8字节(是个指针,函数表指针)
  return 0;
}
