//线程分离
#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
//int pthread_detach(pthread_t thread);
//线程分离,一般在线程创建出来就对线程进行分离,在线程里面调用
//线程的分离对于一个线程来说任意线程在任意位置调用都可以
void* thr_start(void *arg){
//  pthread_detach(pthread_self());//自己分离自己
  sleep(3);

    return "nihao";
}
int main(int argc,char*argv[]){
  pthread_t tid;
  int ret=pthread_create(&tid,NULL,thr_start,NULL);
  if(ret!=0){
    printf("thread cread errn\n");
    return -1;
  }
  pthread_detach(tid);
  char*ptr=NULL;
  int ret1=pthread_join(tid,(void**)&ptr);//取地址修改自身
  if(ret1==EINVAL){
    printf("this thread can not be wait\n");
  }
//  printf("返回值:%d---%d\n",ret1,(int)ptr);
  return 0;
}
