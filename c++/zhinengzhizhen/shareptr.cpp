#include<iostream>
#include <thread>
#include<mutex>
using namespace std;
template <class T>
class shareptr{
  //加成原子操作
  public:
    shareptr(T*ptr):_ptr(ptr),_pcount(new int(1)),_pmutex(new mutex)
  {
    }
    ~shareptr(){
Release();
    }
    //拷贝构造
    shareptr(const shareptr<T> &sp):_ptr(sp._ptr),
    _pcount(sp._pcount),_pmutex(sp._pmutex)
    {
add_pcount();
    }
//sp1=sp2;=号的重载
shared_ptr<T*>&operator=(const shared_ptr<T>&sp)
{
  //自己给自己赋值除外
  if(_ptr!=sp._ptr){
    //释放管理的旧资源
Release();
//共享管理新资源,并增加引用计数
_ptr=sp._ptr;
_pcount=sp._pcount;
_pmutex=sp._pmutex;
add_pcount();
  }
  return *this;
}

    T& operator*(){
      return *_ptr;
    }
    T* operator&(){
      return _ptr;
    }
    int usecount(){
      return *_pcount;
    }
    T* getptr(){
      return _ptr;
    }
    void add_pcount(){
//加锁或者使用原子操作+1
_pmutex->lock();
++(*_pcount);
_pmutex->unlock();
    }
  private:
    void Release(){
      bool deleteflag(false);
_pmutex->lock();
if(--(*_pcount)==0){
 delete _ptr;
 delete _pcount;
deleteflag=true;
}
_pmutex->unlock();
    }
  private:
    T* _ptr;
int* _pcount;//引用计数
mutex* _pmutex;
};
//int main(){
//  shareptr<int>sp1(new int(10));
//  shareptr<int>sp2(sp1);
//  *sp2=10;
//  cout<<sp1.usecount()<<endl;
//  cout<<sp2.usecount()<<endl;
//  shareptr<int>sp3(new int(10));
//  sp2=sp3;
//  cout<<sp1.usecount()<<endl;
//  cout<<sp2.usecount()<<endl;
//  cout<<sp3.usecount()<<endl;
// sp1=sp3; 
//  cout<<sp1.usecount()<<endl;
//  cout<<sp2.usecount()<<endl;
//  cout<<sp3.usecount()<<endl;
//}
//RAII设计守卫锁lock_guard
template<class Mutex1>
class Lock_Guard{
  public:
  Lock_Guard(Mutex1& mtx):_mutex(mtx){
_mutex.lock();
  }
  ~Lock_Guard(){
    _mutex.unlock();
  }
  Lock_Guard(const Lock_Guard<Mutex1>&)=delete;
  private:
    Mutex1& _mutex;//必须是引用否则就不是互斥锁对象
};
mutex mtx;
static int n=0;
void func(){
  for(size_t i=0;i<100000;++i){
    Lock_Guard<mutex>lock(mtx);
    ++n;
  }
}
int main(){
  int begin=clock();
  thread t1(func);
  thread t2(func);
  t1.join();
  t2.join();
  int end=clock();
  cout<<n<<endl;
  cout<<"cost time"<<end-begin<<endl;
}
