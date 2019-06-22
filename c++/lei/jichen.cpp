#include <iostream>
#include<string>
using namespace std;
//class Person
//{
//  protected :
//    string _name = "小李子"; // 姓名
//    int _num = 111; // 身份证号
//
//};
//class Student : public Person
//{
//  public:
//    void Print()
//    {
//      cout<<" 姓名:"<<_name<< endl;
//      cout<<" 身份证号:"<<Person::_num<< endl;
//      cout<<" 学号:"<<_num<<endl;
//
//    }
//  protected:
//    int _num = 999; // 学号
//
//};
//void Test()
//{
//  Student s1;
//  s1.Print();
//
//};
//int main(){
//  Test();
//  return 0;
//}
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// // B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
  public:
    void fun()
    {
      cout << "func()" << endl;
    }
};
class B : public A
{
  public:
    void fun(int i){
      A::fun();
      cout << "func(int i)->" <<i<<endl;
    }
};
void test2(){
  B b;
  b.fun(10);
}
class Person {
  public:
Person(const char* name = "peter")
: _name(name )
{
  cout<<"Person()" <<endl;

}
Person(const Person& p)
: _name(p._name)
{
  cout<<"Person(const Person& p)" <<endl;

}
Person& operator=(const Person& p )
{
  cout<<"Person operator=(const Person& p)"<< endl;
  if (this!=&p)
    _name=p._name;
  return *this;

}
~Person()
{
  cout<<"~Person()" <<endl;
}
protected :
string _name; // 姓名
};
class Student: public Person
{
  public:
    Student(const char* name, int num)
      : Person(name)
        , _num(num)
  {
    cout<<"Student()" <<endl;

  }
    Student(const Student& s)
      : Person(s)
        , _num(s ._num)
  {
    cout<<"Student(const Student& s)" <<endl ;

  }
    Student& operator=(const Student& s)
    {
      cout<<"Student& operator= (const Student& s)"<< endl;
      if (this != &s)
      {
        Person::operator =(s);
      _num=s._num;
      }
      return *this ;
    }
    ~Student()
    {
      cout<<"~Student()" <<endl;

    }
  protected :
    int _num ; //学号
};
void test3 ()
{
  Student s1 ("jack", 18);
  Student s2 (s1);
  Student s3 ("rose", 17);
}
int main(){
  //test2();
  test3();
  return 0;
}
