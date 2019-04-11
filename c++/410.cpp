#include <stdio.h>
using namespace std;
//namespace N
//{
//  //命名空间N
//  //命名空间定义变量成员函数,如果不定义则是全局变量,定义了则在N这个命名空间
//  //类似于局部作用域,命名空间也可以嵌套
//  int a;
//  int b;
//  void fun()
//  {
//        printf("fun(nkongjiandayin )\n");
//  }
//  namespace NN{
//    //另一个命名空间NN嵌套的
//    int a;
//    int b;
//      void fun()
//      {
//        printf("fun(NNkongjiandayin)\n");
//      }
//  }
//}
//namespace  M {
//  int a;
//  int b;
//  void fun(){
//   printf("Mkongjian:daying\n");
//  }
//}
////全局变量
//int a;
//int b;
//void fun1  ()
//{
//        printf("全局变量函数fun1()\n");
//
//}
//namespace  N{//命名空间可以合并和上面那个N合并了
//  int c;
//  double d;
//}
//int main(){
//  N::a=10;
//  N::b=20;
//  a=30;//全局变量的a
// N::fun();
// N::NN::fun();
//  M::fun();
//  fun1();
//  return 0;
//}
#include <iostream>
using namespace std;
//int fun1(int a,int b){
//  return a+b;
//}
////全缺省,每一个形参都定义了一个默认值即是不传任何参数这个函数还可以调用j
//int funcpp(int a=100,int b=200){
//  //缺省函数:缺省参数是声明或定义函数是为函数的参数指定一个默认值,在调用
//  //该函数时,如果没有指定实参则采用该默认值否则使用指定的实参
//  return a+b;
//}
////半缺省,有些参数有默认值有些参数没有默认值
//int funcpp2(int a,int b,int c=50){
//  //int funcpp2(int a=10;int b,int c=50)//这样定义不行
//  //int funcpp2(int a,int b=1,int c=2)//这样可以,从右向左一次给
//  return a+b+c;
//}
////函数声明
//int funcpp3(int a);//里面a默认值的给定要么在声明要么在定义不可以都给为什么呢?
////如果声明时候给了一个默认值定义给了另一个默认值则编译器不知道处理哪个
////函数定义
//int funcpp3(int a=10){
//  return a;
//}
//int main(){
////int a=10;
////std::cout<<a;
////int a;
////double d;
////char c;
////std::cin>>a>>d>>c;
////std::cout<<a<<d<<c<<"\n";
//cout<<fun1(1,2)<<endl;//3
//cout<<funcpp()<<endl;//300
//cout<<funcpp(1)<<endl;//201
//cout<<funcpp(1,9)<<endl;//10
//cout<<funcpp2(1,2)<<endl;//结果为53传一个不行参数个数不够
//cout<<funcpp2(1,2,3)<<endl;//6
//return 0;
//}
//函数重载一词多意,函数名相同,但是参数列表不同(个数,顺序,类型)
//int add(int a,int b){
//  return a+b;
//}
//int add(double a,double b){
//  return a+b;
//}
////double add(int a,int b){//返回值类型不同所以不是函数重载只与参数个数顺序类型有关和返回值类型没有关系
////  return a+b;
////}
////int add(int b,int a){//顺序是参数的类型顺序不同顺序是一样的所以构不成重载
////
////  return a+b;
////}
////int add(double a,int b){//这才是函数的类型顺序不同是函数重载
////  return a+b;
////}
////int add (int a){//函数的个数不同一个是一个参数一个是两个参数也是函数重载
////  return a;
////}
////objdump -S a.out 会把编译出来的汇编打开
//
//int main(){
//add (2,3);
//add(2.1,4.2);
//
//  return 0;
//}
//extern "c"有时候c++工程可能需要按照c风格来编译在函数前加extern "C"意思告诉
//编译器将该函数按照c语言规则来编译
//extern "C" int add(doubule a,double b){
//  return a+b;
//}
//extern "C"{//里面全部是用c语言编译规则
//  int add();
//  int addc();
//}
//int add(int a,int b){
//return a+b;
//}
//int main(){
//  add(3.2,4.8);
//  add(1,2);
//}
//引用给当前变量起了个别名编译器不会为引用变量开辟内存空间,而他和引用用变量
//共用同一块内存空间,引用必须初始化

//int main(){
//  int a=10;
//  int b=a;
//  int& ra=a;
//  cout<<ra<<endl;
//  ra=b;//赋值操作不是引用
//  return 0;//定义一个引用类型
//  const int a=1;
//  const int & ra=a;//常量引用
// const int & ri=10;//也是常量引用
// float f=3.4;
// float &rf=f;//如果int &rrf=f,不行一个为int类型引用一个为float不行
// const int&rrf=f;//3.4中的3这个结果类似于c语言的隐式类型转换,这个临时变量3
//// 赋值给应用rrf,转换为类似于常量必须加const
// //
//}
//void swap(int *pa,int *pb){
//  int tmp=*pa;
//  *pa=*pb;
//  *pb=tmp;
//}
//void swap1(int& ra,int& rb){//引用
//  int tmp=ra;
//  ra=rb;
//  rb=tmp;
//}
//int main(){
//int a=3;
//int b=10;
//swap(&a,&b);//指针传地址
//swap(a,b);//引用
//}

//int& fun(int& a){//int&fun 和int fun是函数重载
////引用做返回值
//a-=5;
//return a;
//}
//int fun(int a){
//  a-=5;
//return a;
//}
//int& add(int a,int b){
//  int c=a+b;
//  return c;//返回引用,你返回的变量的生命周期一定要大于函数的生命周期,不然返回的值会成为意向不到的值
//判断指针和引用执行的效率
//#include<time.h>
//void funref(int&a){}
//void fun (int a){}
//void testvalueref(){
//  int n=100000;
//  int a=1;
//  int i;
//    size_t begin1=clock();
//    size_t end1;
//  for(i=0;i<n;i++)
//    fun(a);
//    end1=clock();
//  
//    size_t begin2=clock();
//    size_t end2;
//  for(i=0;i<n;i++)
//    funref(a);
//    end2=clock();
//  cout<<"fun(int&)cost time:"<< (end2-begin2)/CLOCKS_PER_SEC<<endl;
//  cout<<"fun(int)cost time:"<<( end1-begin1)/CLOCKS_PER_SEC<<endl;
//}
//int main(){
// testvalueref() ;
//  return 0;
//}//是有问题的
int main(){
//auto用法
int a;
auto b="jasdf";
cout<<typeid(b).name(b)<<endl;
  return 0;
}
