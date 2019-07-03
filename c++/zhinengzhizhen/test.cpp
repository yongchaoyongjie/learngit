#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
using namespace std;
template<class T>
//一个智能指针
class Smartptr{
  public:
    Smartptr(T*ptr):_ptr(ptr){}

    ~Smartptr(){
      cout<<"delete"<<_ptr<<endl;
      delete _ptr;
    }

    T& operator*(){
return *_ptr; 
    }
    T* operator->(){
return _ptr; 
    }
    T*Get(){
      return _ptr;
    }
  private:
T* _ptr;
};
struct A{
int _a;
int _b;
};
void fun(){
  Smartptr<int>sp(new int);//交给了sp这个对象
 int *p=sp.Get(); 
 *p=20;
 cout<<*p<<endl;
}
//int main(){
//  try{
//fun();
//  }
//  catch(exception& e){
//e.what();
//  }
//  return 0;
//}
//一个异常程序
double Div(int a,int b){
  if(b==0){
throw" Division by zero condition!";
  }else{
    return( (double)a/(double)b);
  }
}
void func(){
  int *p=new(int [10]);
  int len,time;
  cin>>len>>time;//5 0
  Div(len,time);
  delete[]  p;
}
//int main(){
//  try{
//    func();
//  }
//  catch(int err){
//    cout<<__LINE__<<err<<endl;
//  }
//  catch(const string&err){
//    cout<<__LINE__<<err<<endl;
//  }
//  catch(const char* err){
//    cout<<__LINE__<<err<<endl;
//    //选择的是这个显示为54行,异常被这个捕获了
//  }
//  catch(...){
//    cout<<__LINE__<<"未知异常"<<endl;
//  }
//
//return 0;
//}

//int main(){
//  try{
//    vector<int> v(10,5);
//    v.reserve(1000000000);//越界
////v.at(10);//异常-->vector::_M_range_check
//
//  }
//  catch(const std::exception & e){//捕获父类的对象就可以了 
//cout<<e.what()<<endl;//what 是一个虚函数-->多态
//  }
//  catch(...){
//cout<<"unkonw exception"<<endl;
//  }
//  return 0;
//}
namespace  chenyongjei{
  template<class T>
    class atuo_ptr{
      public:
atuo_ptr(T*ptr):_ptr(ptr)
      {}
~atuo_ptr(){
  cout<<"delete"<<_ptr<<endl;
  delete  _ptr;
}
//管理权限转移chenyongjie::auto_ptr<int>ap2(ap1);
atuo_ptr(auto_ptr<T> &ap):_ptr(ap._ptr){
  ap._ptr=nullptr;
  ////但是有问题,给它传参后自己置空了自己的值没有了,所以严禁使用auto_ptr,会导致悬空的问题,有缺陷
}
//ap1=ap3;
auto_ptr<T>&operator=(atuo_ptr<T>&ap){
  if(this!=&ap){
//;自己等于自己的除外
    if(_ptr){
      //// 释放当前对象中资源
      delete  _ptr;
    }   
    _ptr=ap._ptr;
    ap._ptr=nullptr;
//// 转移ap中资源到当前对象中
  } 
  return *this;
}
T& operator*(){
  return *_ptr;
}
T* operator->(){
  return _ptr;
}
private:
T*_ptr;
    };
void test_auto_ptr(){
  chenyongjei::atuo_ptr<int>ap1(new int);
  chenyongjei::atuo_ptr<int>ap2(ap1);
  chenyongjei::atuo_ptr<int>ap3(ap2);
}
//uniqueptr
template<class T>
class unique_ptr{
  public:
unique_ptr(T*ptr):_ptr(ptr){
}
~unique_ptr(){
cout<<"delete :"<<_ptr<<endl;
}
unique_ptr(const unique_ptr<T>&ap)=delete;
unique_ptr<T>operator=(const unique_ptr<T>&ap)=delete;
T& operator*(){
  return *_ptr;
}
T* operator->(){
  return _ptr;
  //返回值*ptr,返回是指针指向那块区域的别名,进行一次寻址
}
private:
T* _ptr;
};
void test_unique_ptr(){
  chenyongjei::unique_ptr<int> ap1(new int);
//chenyongjei::unique_ptr<int> ap2(ap1);//没有实现
}
template<class T>
//引用计数sp1   计数1次
//sp2(sp1)   计数两次
class shared_ptr1{
  public:
  //加计时器
shared_ptr1(T*ptr):_ptr(ptr),_pcount(new int(1))
  {}
//拷贝构造
//sp2(sp1)
int getcount(){
  return *_pcount;
}
shared_ptr1(const shared_ptr<T>&sp):_ptr(sp._ptr),_pcount(sp._pcount){
  *(_pcount)++;
}
shared_ptr1 & operator=(const shared_ptr1<T>&sp){
  if(this!=&sp){
    if(--*_pcount==0){
      delete _ptr;
      delete _pcount;
    }
    _ptr=sp._ptr;
    _pcount=sp._pcount;
    delete sp._ptr;
    delete sp._pcount;
  }
  return *this;
}
T&operator*(){
return *_ptr;
}
T* operator->(){
return _ptr;
}
  ~shared_ptr1(){
    if(--(*_pcount)==0){
      delete  _ptr;
      delete  _pcount;
    }
  }
private:
T* _ptr;
int *_pcount;
};
void test_share_ptr1(){
  chenyongjei::shared_ptr1<int>sp1(new int(1));
  cout<<sp1.getcount()<<endl;
  chenyongjei::shared_ptr1<int>sp2(sp1);
  sp2=sp1;
  chenyongjei::shared_ptr1<int>sp3(new int(3));
  sp3=sp1;
}
}
int main(){
  chenyongjei::test_share_ptr1();
  chenyongjei::test_auto_ptr();
  chenyongjei::test_unique_ptr();
  return 0;
}

