#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
//线程安全--->卖票程序
//写一个卖票程序,有4个黄牛抢票直到完为止;
//互斥锁的基本使用
int ticket_cout=100;
//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;默认初始化
//pthread_mutex_t mutex;//一定要在没有创建线程之前初始化互斥锁

void*thr_start(void*arg){
//  printf("i am a yellow pull---%d\n",(int)arg);
  while(1){
    if(ticket_cout>0){
      usleep(1000);//1000微妙过程(抢票的过程)
printf("i am a yellow pull---%d get ticket:%d\n",(int)arg,ticket_cout);
ticket_cout--;
    }else{
  //    printf("have no ticket exit!\n");
      return NULL;
    }
  }
  return NULL;
}
int main(int argc,char*argv[]){
pthread_t tid[4];
int i,ret;
//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;默认初始化
//放在全局和线程开始之前都可以
pthread_mutex_t mutex;//一定要在没有创建线程之前初始化互斥锁

for(i=0;i<4;i++){
ret=pthread_create(&tid[i],NULL,thr_start,(void*)&mutex);
//互斥锁访问的是同一个线程,只要保证访问的是同一个互斥锁就能保证互斥
if(ret!=0){
  printf("thread create erron");
return -1;
}
}
for(i=0;i<4;i++){
pthread_join(tid[i],NULL);//主线程退出
}
  return 0;
}
