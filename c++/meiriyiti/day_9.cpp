#include<iostream>
#include<stdio.h>
using namespace std;
void test(){
  int a[4]={1,2,3,4};
  int *ptr=(int*)(&a+1);
  printf("%d\n",*(ptr-1));//4是否 越界?
}
void test1(){
  //const 使用
  //const只要在*之前修饰的是内容
  //const在*之后修饰的是指针变量本身
  int i=10;
  int j=1;
  const int *p1;//p1指向的内容
  int const*p2=&i;//也是p1指向的内容
  p2=&j;
  int *const p3=&i;//修饰的是指针变量本身
  *p3=20;
  //*p2=30;//因为是修饰的是p2指向的内容所以不能改变了
  *p3=j;//
  //p3=&j;
  cout<<*p3<<endl;//1
}
class clas{
  static int n;
  public:
  clas(){n++;}
  ~clas(){n--;}
  static int get_n(){return n;}
};
int clas::n=0;
void test3(){
  clas *p=new clas;
  delete  p;
  cout<<"n="<<clas::get_n()<<endl;//静态变量的值无法改变
}
void test2(){
  int a=21;
  a^=(1<<5)-1;
  cout<<a<<endl;//10
}
void func(char**m){
  ++m;
  cout<<*m<<endl;
}
void test4(){
  static char*a[]={"morning","afternoon","evening"};
  char**p;
  p=a;
  func(p);//afternoon
}
//class MyClass{
//  public:
//    MyClass(int i=0){
//      cout<<1;
//    }
//    MyClass(const MyClass& x){
//      cout<<2;
//    }
//    MyClass& opertator=(const MyClass& x){
//      cout<<3;
//      return *this;
//    }
//    ~MyClass(){
//      cout<<4;
//    }
//};
int addab(int a,int b){
  //实现加法的另一种方式,用异或保存当前位置,与保存当前的进位然后<<1来保证
  //给前面位进位
  int sum=0;
  int carry=0;
  while(b!=0){
    sum=a^b;
    carry=(a&b)<<1;
    a=sum;
    b=carry;
  }
  return sum;
}
void test5(){
int a,b;
cin>>a>>b;
cout<<addab(a,b)<<endl;
}
void test6(){
  int count=0;
  int x;
  while(cin>>x){
    count++;
  x=x&(x-1);
  }
  cout<<count<<endl;
}
int fun(int a){
  if(a==5){
    return 2;
  }
  return 2*fun(a+1);
}
void test7(){
  fun(2);
}
void test8(){
int l=1;
if(l<=0){
  printf("***\n");
}
else{
  printf("%%%\n");
}
}
int main(){
  //test();
  //test1();
//  test2();//10
  //test3();
 // test4();
 test8();
  return 0;
}
