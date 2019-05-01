#include<iostream>
#include<queue>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<time.h>
#include<cstdbool>
//创建大量线程然后创建线程安全队列然后向安全队列添加任务
class MyTask{
  private:
    //void *data;
    int _data;
  public:
    MyTask(int data): _data(data){}
    //初始化
   // void SetData(int data){ _data=data;
   // }
void Run(){//数据的处理方式,virtual虚函数
   // 自己定义时候再说
      srand(time(NULL));
      int s=rand()%5;//rand取余5保证随机数在0-4之间
      printf("thread %p get data %d--sleep---%d\n",pthread_self(),
          _data,s);//区分线程第二个获得的数据第三个睡了几秒钟后
      //才能再次处理任务
      sleep(s);
    }
};

class ThreadPool{
  private:
    std::queue<MyTask *> _list;
int _cap;
pthread_mutex_t _mutex;//锁
pthread_cond_t _full;//条件变量
pthread_cond_t _empty;
int _max_thr;//最大成员变量线程池的最大线程数量
bool QueuePopIsEmpty(){

  return( _list.size()==0);
}
bool QueueIsFull(){
  return (_list.size()==_cap);
}
bool QueuePush(MyTask*t){
  _list.push(t);
}
bool QueuePop(MyTask**t){
*t=_list.front();//获取队首结点
_list.pop();//出队
}
static void* thr_start(void*arg){
//在类里面定义thr_start会发现入口函数不匹配为什么?类的成员函数有多个参数,默认
//会有一个参数这个参数是this指针,现在入口函数有*arg一个参数但是它做为类的成员
//函数默认前面有个参数是this现在变成两个参数了所以和底下那个start参数不匹配
//将其变成静态函数,或者将start定义到类的外面这两者都会导致没有this指针了意味着
//函数没办法操作类的成员类的变量了,所以需要将this指针通过thr_start函数传进来
//才能操作类的对象,所以在创建线程时候需要传一个参数(void*)this,谁实例化这个
//对象传的就是谁
while(1){//循环获取任务
ThreadPool *p=(ThreadPool*)arg;//强转
pthread_mutex_lock(&p->_mutex);//私有成员函数可以访问到私有成员
MyTask*task;
while(p->QueuePopIsEmpty()){//队列为为空则等待(没有任务,工作线程则等待)
  //此处为while循环不能是if如果是if会唤醒多个,取到相同的就出问题
  pthread_cond_wait(&p->_empty,&p->_mutex);
}
p->QueuePop(&task);//把任务获取出来
//task->Run();//运行task里面方法run函数有可能处理很长时间导致锁一直加着,其他的
//线程获取不到任务导致同一时间只有一个线程来处理任务-->taskrun应该放在锁
//的外边
pthread_mutex_unlock(&p->_mutex);
pthread_cond_signal(&p->_full);//唤醒
task->Run();
delete task;
  return NULL;
}
}
  public:
ThreadPool(int thr=5,int q=10)://构造函数
 //thr最大线程数量,q缓冲队列结点数量
_max_thr(thr),_cap(q) 
{
pthread_mutex_init(&_mutex,NULL);
pthread_cond_init(&_full,NULL);
pthread_cond_init(&_empty,NULL);
}
~ThreadPool(){
  //析构函数
  pthread_mutex_destroy(&_mutex);
  pthread_cond_destroy(&_full);
  pthread_cond_destroy(&_empty);
}
bool Init(){
  pthread_t tid;
  for(int i=0;i<_max_thr;i++){
    int ret=pthread_create(&tid,NULL,thr_start,(void*)this);

      if(ret!=0){
        printf("pthread create errno\n");
        return false;
      } 
      pthread_detach(tid);
    }
  return true;
  }
bool AddTask(MyTask*task){//添加任务队列满了也等待,添加任务就是向队列添加数据
 pthread_mutex_lock(&_mutex);
 if(QueueIsFull()){
   pthread_cond_wait(&_full,&_mutex);
 }
QueuePush(task);
 pthread_mutex_unlock(&_mutex);
 pthread_cond_signal(&_empty);//满了唤醒一下empty
  return true;
}
};
int main(){
ThreadPool p;
MyTask*t;
p.Init();
int i=0;
while(1){
  printf("add task data :%d\n",i);
  t=new MyTask(i++);
 p.AddTask(t);
 
}
  return 0;
}
