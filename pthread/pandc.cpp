#pragma GCC diagnostic error "-std=c++11"  
#include <iostream>
#include<queue>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>
#include<cstdbool>
//封装类
class BlockQueue
{
  private:
    std::queue<int> _list;//队列
    int _cap;//容量
  pthread_mutex_t _mutex;//互斥锁
  pthread_cond_t _product;//条件变量
  pthread_cond_t _consumer;
  bool QueueIsFull(){
  return (_list.size()==_cap ? true : false);//等于容量则满了,不相等没有满
  }
  bool QueueIsEmpty(){
    return(_list.size()==0 ? true:false);//队列为空
  }
  public:
  BlockQueue(int cap=10): _cap(cap)
  {//构造函数,默认不传参数为10,给cap值为10里面int cap不能为_cap形参后面_cap才是成员变量:后面为初始化的参数列表
    pthread_mutex_init(&_mutex,NULL);
    pthread_cond_init(&_product,NULL);
    pthread_cond_init(&_consumer,NULL);
  }
  ~BlockQueue()
  {//析构函数-->退出时候调用-->对象释放时候调用
  pthread_mutex_destroy(&_mutex);
  pthread_cond_destroy(&_product);
  pthread_cond_destroy(&_consumer);
  }
  bool QueuePush(int data)
  {
    pthread_mutex_lock(&_mutex);
    while(QueueIsFull()){
      printf("queue is full\n");
      pthread_cond_wait(&_product,&_mutex);//入队
    }
    _list.push(data);
    pthread_mutex_unlock(&_mutex);
    pthread_cond_signal(&_consumer);//通知消费者,唤醒消费者
  }
  bool Queuepop(int *data){
    pthread_mutex_lock(&_mutex);
    while(QueueIsEmpty()){
      printf("queue is empty\n");
      pthread_cond_wait(&_consumer,&_mutex);//为空等待
    }
    *data=_list.front();//获取头结点但是不会出队
_list.pop();//出队//为什么获取结点和出队不封装在一起->为了让使用场景更广泛,有时候获取结点看一下是什么但是并不想出队不是线程安全的,所以要锁
pthread_mutex_unlock(&_mutex);
pthread_cond_signal(&_product);//唤醒生产者
  }
};
void* thr_consumer(void *arg){
  BlockQueue *q=(BlockQueue*)arg;//强转
  while(1){
    //消费者
    int data;
   if(q->Queuepop(&data)){
      printf("get data :%d\n",data);
   }
  }
  return NULL;
}
void* thr_product(void *arg){
  BlockQueue *q=(BlockQueue*)arg;//强转
  while(1){
    int i=0;//生产者放数据
    printf("put data:%d\n",i);
  q->QueuePush(i);//i++先使用,打印多少代表放了多少
  i++;
  usleep(100000);
  }  
  return NULL;
}
int main(){
  //创建4个生产者4个消费者进行争抢
  BlockQueue q;
  int i,ret;
  pthread_t consutmertid[4],producttid[4];
  
  for(i=0;i<4;i++){
    ret=pthread_create(&consutmertid[i],NULL,thr_consumer,(void*)&q);
  if(ret!=0){
    printf("create thread is errno\n");
    return -1;
}
}
  for(i=0;i<4;i++){
    ret=pthread_create(&producttid[i],NULL,thr_product,(void*)&q);
  if(ret!=0){
    printf("create thread is errno\n");
    return -1;
}
}
for(i=0;i<4;i++){
  pthread_join(producttid[i],NULL);
  pthread_join(consutmertid[i],NULL);
}
return 0;
}
