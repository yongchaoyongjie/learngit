#include <unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//pthread_t _pthread_self(void);//获取线程id
//返回一个调用线程的id
void* thr_start(void*arg){
  pthread_t tid=pthread_self();
  while(1){
    printf("i am a child--%s--%d\n",(char*)arg,(int)tid);
    sleep(1);
  }
return NULL;
}
int main(int argc ,char*argv[]){
pthread_t tid;
int ret=pthread_create(&tid,NULL,thr_start,(void*)"nihao");
if(ret!=0){
  printf("thread create error\n");
  return -1;
}
printf("main tid %p\n",pthread_self());//获取自己的tid
printf("child tid:%p\n",tid);
while(1){
  printf("hello world\n");
  sleep(1);
}
  return 0;
}
