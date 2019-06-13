#include<iostream>
using namespace std;
//int n=0;
////设计一个类统计程序中创建了多少个这个类型的对象
//class A
//{
//  public:
//    A(int a=10)
//      :_a(a)
//    {
//      ++n;
//    }
//
//A(const A& a){
//++n; 
//}
//private:
//int _a;
//};
//A f(A a){
//  return a;//aa1传给f拷贝构造一个,返回要拷贝构造一个
//}
//int main(){
// A aa1(1);//1
// A aa2=10;//1
//f(aa1);//2
//cout<<n<<endl;//4
//  return 0;
//}
//int n=0;
////设计一个类统计程序中创建了多少个这个类型的对象
//class A
//{
//  public:
//    A(int a=10)
//      :_a(a)
//    {
//      ++n;
//    }
//
//A(const A& a){
//++n; 
//}
//private:
//int _a;
//};
//A f(A a){
//  return a;//,返回要拷贝构造一个
//}
//int main(){
//// A aa1(1);//1
//// A aa2=10;//1
//// A aa3=f(aa1);//aa1给f会拷贝构造一个然后return a 拷贝构造一个临时对象 
//// //然后拿临时对象又会拷贝构造aa3所以应该是五个,但是编译器会优化,直接拿return a
//// //构造的临时对象构造在aa3-->变成4个了,中间产生了临时对象编译器会消除
//// A();//1-->匿名对象-->没有名字,想调掉成员函数-->仅仅为了传参
// f(A(20));//匿名对象传参,对象传过去其他地方不用这个对象的时候就用匿名对象
// //本来应该是三个对象A()+A a+ a-->优化成2个对象构造+拷贝构造-->直接两个对象合二为一
// n=10;//全局变量放在外面n可更改不想改变n的值从而统计对象-->static
//cout<<n<<endl;
//  return 0;
//}
//int n=0;
//class A
//{
//  public:
//    A(int a=10)
//      :_a(a)
//    {
//      ++n;
//    }
//A(const A& a){
//++n; 
//}
//int GetN(){
//  return _n;//通过接口访问静态变量
//}
//private:
//int _a;
//static int _n;//_n不属于某个对象属于所有对象,属于整个类,存储在数据段的静态区
////不能随便改变_n-->访问通过接口-->静态变量封装到类里,受到类域和访问限定符的约束
////此处只是声明了静态成员变量但是还没有申明,静态成员变量的定义在类外
////可以进行封装管理
//};
//int A::_n=0;//静态成员变量在类外声明和初始化,初始化不受访问限定符限制,直接在
////全局初始化-->此处只是初始化
//A f(A a){
//  return a;
//}
//int main(){
//f(A(20));
//cout<<A().GetN()<<endl;//封装_n后必须借助对象才能进行调用-->匿名对象调用封装好的静态变量
////不用对象去调用
//return 0;
//}
////不用对象去调用
//把成员函数定义成静态,
//int n=0;//全局变量
//class A
//{
//  public:
//    A(int a=10)
//      :_a(a)
//    {
//      ++n;
//    }
//A(const A& a){
//++n; 
//}
//static int GetN(){//静态函数没有this指针-->不需要对象都可以调用
//  return _n;
//}
//private:
//int _a;
//static int _n;
//};
//int A::_n=0;//静态成员变量初始化
//A f(A a){
//  return a;
//}
//int main(){
//f(A(20));
//cout<<A::GetN()<<endl;//用静态函数实现调用但是要突破类域所以需要用::
////如果静态成员定义成公有则cout<<A::_n<<endl;cout<<aa1._n<<endl就可以调用了
////cout<<aa1.getN()-->定义成公有调用方式多因为属于所有对象
//return 0;
//}
//静态变量和静态函数属于所有对象整个类-->体现封装-->全局变量没有封装
//静态变量在类里面不能赋值因为没有this指针
//静态成员函数为所有类对象所共享,在类里声明在类外定义
//static 1.局部变量改变生命周期2.修饰全局函数,全局变量,改变链接属性(只在当前
//文件可见),3修饰成员函数成员函数没有this指针属于整个类所有对象
//使用类名就可以调用4可以修饰成员变量,变量属于整个类所有对象,使用类名就 可以访问

//class A{
//public:
//  A():_a2(10){}//如果没有10则会显示2,类似于函数参数的缺省值,没有给用2给了
//  //就变成10
//  private:
//    int _a1;//随机值
//    int _a2=2;//声明,不是初始化相当于给缺省值-->c++11支持--->但是静态
//    //static int _n=10;-->c++11支持在申明时候给缺省值但是对于静态变量不行必须在
//    //类外
//    int *_p=new int;//c++11支持也给了缺省值,允许这样
//};
//class B{
//  public:
//    B(int b=0):_b(b){}
//    int _b;
//};
//class A{
//  public:
//  A():_a2(10),_b(30)//此处给了30那么之前在private里面的缺省值就没有作用了
//  {}//如果没有10则会显示2,类似于函数参数的缺省值,没有给用2给了
//  private:
//    int _a1;//随机值
//    int _a2=2;//声明,不是初始化相当于给缺省值-->c++11支持--->但是静态
//    int *_p=new int;//c++11支持也给了缺省值,允许这样
//    B _b=10;//_b类型的隐式类型转换构造了_b对象然后10拷贝构造给_b--->申明+缺省值
//   //针对内置类型成员默认初始化 
//};
//int main(){
//  A aa;
//  return 0;
//}
//有缘函数+有缘类-->突破封装
//class Data{
//  public:
//    Data(int year=1900,int month=1,int day=1):_year(year),_month(month),
//    _day(day){}
//    //cout-->是ostream对象
//   void  operator<<(ostream& _cout)
//   {
//_cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//    }
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main(){
//  Data d1(2019,5,20);
////cout<<d1<<endl;自定义类型重载输出
//d1<<cout;//调用这样调用,一个具有两个操作数的运算符有一个左操作数和右操作数
////规定第一个参数是左操作数第二个参数是右操作数  this->d1<<cout--->如何把cout
////变成第一个参数--cout 是第二个参数日期类是第一个参数因为this指针
//  return 0;
//}
///必须在类外才能抢过this指针
//class Data{
//  public:
//    Data(int year=1900,int month=1,int day=1):_year(year),_month(month),
//    _day(day){}
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//   void  operator<<(ostream& _cout,const Data &d )
//   {
//_cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;//但是私有访问不到
//    }
//引用有缘开特例,让其优先级大于this
//class Data{
//  friend  void  operator<<(ostream& _cout,const Data &d );//加申明放到类最前面
//  //在友元函数里可以任意用日期类对象访问成员不受访问限定符限制赋予函数突破封装的
//  //权利-->开了特例
//  public:
//    Data(int year=1900,int month=1,int day=1):_year(year),_month(month),
//    _day(day){}
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//   void  operator<<(ostream& _cout,const Data &d )
//   {
//_cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;//但是私有访问不到
//    }
//
//int main(){
//Data d1(2019,5,2);
//cout<<d1;//等价调用operator<<(cout,d1);
////如果还想支持cout<<d1<<d2<<endl;
//}
////如何支持连续<<<<
class Data{
  friend  ostream& operator<<(ostream& _cout,const Data &d );//加申明放到类最前面
  friend istream & operator>>(istream& _cin,const Data &d );
  //从控制台输入数据放到
  public:
  Data(int year=1900,int month=1,int day=1):_year(year),_month(month),
  _day(day){}
  private:
  int _year;
  int _month;
  int _day;
};
ostream & operator<<(ostream& _cout,const Data &d )
{
  _cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;//但是私有访问不到
  return _cout;//出了作用域对象还在加&
}
//还要支持oprator>>
istream& operator>>(istream& _cin,const Data &d )//从控制台输入数据放到
  //日期类对象d中,要修改它拿到它所以data后必须为引用
{
  _cin>>d._year;
  _cin>>d._month;
  _cin>>d._day;
  return _cin;//出了作用域对象还在加&
}
//int main(){
//Data d1(2019,5,2);
//Data d2(1019,5,3);
//cin>>d1>>d2;
////d1=d2=d3;是d3赋值给d2,然后d1=(d2=d3),表达式的值给d1  cout<<d1<<d2<<endl-->
////从左往右cout<<d1的返回值然后<<d2--->然后--><<endl-->多个函数调用
////cout<<d1;//等价调用operator<<(cout,d1);
////如果还想支持cout<<d1<<d2<<endl;
//cout<<d1<<d2<<endl;
//return 0;
//}
//求1+2+3+..+n不能用乘除法for while if case实现
//class CountN{
//  public:
//    CountN(){
//      ret+=i;
//      i++;
//    }
//  private:
//static int _ret;
//int _i=1;
//};
//countN array[N];
//定义对象就会调用构造函数定义n个对象调用了N次构造函数构成了1+n的结果,可以借助
//静态完成,n次构造函数第一次0+1+2...,如果N是变长数组就有问题了有些编译器支持
//法2 new 开空间同时调用构造函数初始化  
//new countN [N]
class solution{
  public:
    class Sum{//内部类是外部类的有元
      public:
        Sum(){
          _sum+=_i;
          _i++;
        }
    };
    int Sum_soulution(int n){
      //Sum array[n];
      _sum=0;//_sum=0_i=0如果不置位=成0 只能保证一次可
      _i=0;
      Sum*p=new Sum[n];
      delete []p;
      return _sum;
    }
    static size_t _sum;
    static size_t _i;
};
size_t solution::_sum=0;
size_t solution::_i=1;
//int main(){
//cout<<solution().Sum_soulution(5)<<endl ;//每次计算保证sum和i从0开始
//cout<<solution().Sum_soulution(5)<<endl ;
//return 0;
//}
//如果是有元类就是在类里面定义一个类,要在前面进行申明
//内部类
class A{
  private:
    static int k;
    int h;
  public:
    class B{
      public:
        void foo(const A& a){
          cout<<k<<endl;
          cout<<a.h<<endl;
          //就是在B里面直接可以访问K
        }
    };
};
int A::k=1;
int main(){
  A a;
  A::B b;//定义要这样定义如果是内部类,而且内部类必须是在外部类的公如果是私有
  //则调用不动-->但是是可以定义成私有-->如果定义成私有则属于自己独有的类
  //内部类可以访问外部类中的static 枚举 不需要外部类的对象/类名
  //就是在B类里面直接可以访问k,因为B是A的有元,内部类是外部类的有元,k是静态,属于整个
  //类,不属于某个对象,非静态成员可以通过对象进行访问-->b是a的有元,内部类是外部类
  //的有元
  cout<<sizeof(A)<<endl;//4,不算K只算h,k属于所有对象放在静态区,sizeof算类的对象占
  //多大不包含B
  return 0;
}
