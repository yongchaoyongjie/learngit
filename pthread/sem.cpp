//基于c++中的vector容器实现线程安全的环形队列
//vector是一个线性表(数组)
#include <vector>
#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<stdio.h>
#include<cstdbool>
//私有成员以前命名为my_list--->演变成  _list,主要是区分类成员和形参成员
class RingQueue{
  private:
std::vector<int> _list;
int _cap;
pthread_mutex_t _mutex;
sem_t _space;
sem_t _data;//多少数据可以获取
int _pro_step;
int _cons_step;
  public:
//公有的第一个为构造函数
RingQueue(int cap=10):  _list(cap),_cap(cap),
  _pro_step(0), _cons_step(0){
    sem_init(&_space,0,cap);//初始化为线程间同步与互斥空闲空间大小是数组大小
    //所以初值为cap
    sem_init(&_data,0,0);//没有数据写入为0
    pthread_mutex_init(&_mutex,NULL);
  }
~RingQueue(){
  //析构函数
  sem_destroy(&_space);
  sem_destroy(&_data);
}
bool QueuePush(int data){//传值想数组添加一个数就好不用传地址
  //记住queuepush不是原子操作
  sem_wait(&_space);//生产者有空闲空间才能向下走没有空闲空间不能放数据,判
  //断队列是否满了,sapce能走保证肯定有空闲空间 
  pthread_mutex_lock(&_mutex);//上锁
  _list[_pro_step]=data;//生产者
  _pro_step++;
 //法1 if(_pro_step==_cap){//放满了
  //  _pro_step=0;
  //}
  //法2
  _pro_step%=_cap;//等于cap取余为0
  pthread_mutex_unlock(&_mutex);
  sem_post(&_data);//唤醒data放了一个数据代表现在已经有一个空间可用,有资源
  //可以操作给data里面加1
  return true;
}
//如果cpu切换调度的时候先运行的queuepop,那么一开始一定没有数据会陷入休眠,不是
//条件变量并不会解锁代表push获取不到锁就没办法放数据了,就没办法读数据了卡死了
//pthread_mutex_lock保护的是wait的资源,信号量的计数不需要保护,所以应该将,保证的是脚步
//lock放在wait下,如果sem_wait进来代表有资源然后进行加锁获取数据然后解锁space+1
//所以代表其他的消费者也能获取,如果自己获取不到代表其他消费者依然会走到wait
//使用条件变量把加锁放在外面,因为条件判断本身就是临界资源所以要保护它,但是对于
//信号量来说本身内部计数不需要保护为原子操作所以就不需要把加锁放在sem_wait外部
//不需要保护它,只需要保护数组的操作就可以了
bool QueuePop(int *data){//传地址是为了获取这个数据,用int*,如果获取的是地址用
  //int**;
 sem_wait(&_data);//判断data有数据代表有数据可以读
 pthread_mutex_lock(&_mutex);
  *data=_list[_cons_step];
  _cons_step++;
  _cons_step%=_cap;
  pthread_mutex_unlock(&_mutex);
  sem_post(&_space);//data取了一个数据就代表space空出来一个空间
  return true;
}
};
void *thr_con(void*arg){
RingQueue*q=(RingQueue*)arg;
while(1){
//获取数据
int data;
q->QueuePop(&data);
printf("consumer get data %d\n",data);
}
return NULL;
}
void *thr_pro(void*arg){
  RingQueue*q=(RingQueue*)arg;
int* i=0;//*i
  while(1){
    sleep(1);
printf("the producter has space %d\n",i);
q->QueuePop(i++);
  }
  return NULL;
}
//所以queueisempt和queueisfull没必要存在,因为space和used本来就是计数计数为0代
//表没有资源,
int main(){
pthread_t ctid[4],ptid[4];//4个生产者4个消费者
int ret,i=0;
RingQueue q;
for(;i<4;i++){
  ret=pthread_create(&ctid[i],NULL,thr_con,(void*)&q);
  if(ret!=0){
    printf("create pthread errno\n");
    return -1;
  }
}
for(;i<4;i++){
  ret=pthread_create(&ptid[i],NULL,thr_pro,(void*)&q);
  if(ret!=0){
    printf("create pthread errno\n");
    return -1;
  }
}
for(;i<4;i++){
pthread_join(ctid[i],NULL);
pthread_join(ptid[i],NULL);
}
  return 0;
}
