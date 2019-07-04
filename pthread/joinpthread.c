//线程等待
#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
//int pthread_join(pthread_t thread,void**retval)
//第一个参数要等待的线程id第二个参数retval:输出型参数用于获取退出
//线程的返回值
void* thr_start(void *arg){
  sleep(3);
  char buf[]="woshi9527";
    return "nihao";
}
int main(int argc,char*argv[]){
  pthread_t tid;
  int ret=pthread_create(&tid,NULL,thr_start,NULL);
  if(ret!=0){
    printf("thread cread errn\n");
    return -1;
  }
  pthread_cancel(tid);//异常退出不具备评判标准,返回值没有任何价值
  char*ptr=NULL;
  pthread_join(tid,(void**)&ptr);//取地址修改自身,定义的为(void* the_start)char*修改它就用char**
  printf("返回值:%d\n",(int)ptr);
}
