#include<iostream>
using namespace std;
//class Data{
//  public:
//    Data(int year=1900,int month=1,int day=1){
//      cout<<"Data()"<<endl;
//    _year=year;
//    _month=month;
//    _day=day;
//    }
//    //Data copy(d1);this 就是copy, d 就是d1
//    Data(Data& d){//拷贝构造-->拷贝构造是构造函数的重载只不过参数是固定了为日期类的对象
////但是编译不通过,访问限定符锁的是外面的人但是不锁类里面的对象
////必须得给引用否则编译不通过,不加引用会引发无穷递归-->调用拷贝构造先传参但是传参是拷贝构造所以无穷递归-->所以必须用引用
////用了传引用必须定义别名(调用拷贝构造要先传参d是d1的别名),则传参构造拷贝构造这个过程就断了
////引用在传参的时候不改变d的值尽量把const加上因为只是将d1的值给copy,不会改变d-->
////如果没有写拷贝构造会生成默认的拷贝构造,-->深浅拷贝默认拷贝为浅拷贝字节序完成拷贝-->Data copy(d1);--->memcpy (&copy,&d1,sizeof(Data))-->涉及到动态开辟内存就有问题了
////运算符重载的意义在于-->日期类也希望可以比较大小d1(2019,5,12)>到d2(2018,1,2);
//      _year=d._year;//d给this就是把d1给copy
//      _month=d._month;
//      _day=d._day;
//    }
//    //bool  operator==(const Data d1,const Data d2){//opertaator参数太多-->多了一个this
//       //而且this一定是左边那个操作数-->所以此种方法不对,因为在类里面有this指针
////比较两个值但是不改变值所以加const &提高效率
////d1.operator==(&d1,d2);-->d1给了thisd2给了d
//bool operator==(const Data d){//两个操作数为bool operator(Data*this,const Data& d);
//return this->_year==d._year
//  &&this->_month==d._month
//  &&this-> _day==d._day;
//    }
////d2=d1
//Data& operator=(const Data &d){
//_year=d._year;
//_month=d._month;
//_day=d._day;
//return *this;
//}
////void operator=(const Data d){
//////与上面相比多调了一次拷贝构造
////_year=d._year;
////_month=d._month;
////_day=d._day;
////}
//    void pprint(){
//      cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//    }
//    ~Data(){
//      cout<<"Data()"<<endl;
//    }
//    int Getyear(){
//      return _year;//只读不能写-->法1,运算符的重载在类里面
//    }
//  private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main(){
////Data d1(2019,5,12);
//////有个对象和d1值一模一样
//////Data copy(2019,5,12);-->可以但是不方便因为d1数变这个也变了
////Data copy(d1);//还是构造函数同时拷贝了
//Data d1(2019,5,12);
//Data d2;
////d1==d2;//看到运算符的重载先去全局找在到类里找转换为(1)d1==d2(2)d1.operator==(d2);(3)d1 operator==(&d1,d2);
////d1.operator==(d2);
//d2=d1;
//Data d3(d1);
//d2.pprint();//都是2019 5 12
//d3.pprint();
//Data d4;
//d4=d2=d1;//需要返回值
//return 0;
//}
class Data{
  public:
    Data(int year=1900,int month=1,int day=1){
      cout<<"Data()"<<endl;
    _year=year;
    _month=month;
    _day=day;
    }
    void pprint()const {
      cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    Data*operator &(){//取地址运算符的重载
      return this;
    }
   const  Data*operator &()const
   {//取地址运算符的重载-->取const对象
      return this;
    }
  private:
    int _year;
    int _month;
    int _day;
};
int main(){
Data d1(2019,5,12);
Data d2(d1);
const Data d3(d1);
d2.pprint();
d3.pprint();//d3为const 调不动print
cout<<&d2<<endl;
cout<<&d3<<endl;
return 0;
}
