#include <unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//int pthread_create(pthread_t *thread,
//const pthread_attr_t *attr,
//void *(*start_routine) (void *), void *arg);
//thread:输出型参数,获取新创建的线程id
//attr:设置线程属性(一般置空)
//star_routine:线程入口函数
//arg:通过线程入口函数传递给线程的参数
//返回值:成功返回0,失败返回一个错误编号(errno>0)非0值
void* thr_start(void*arg){//线程入口函数
  while(1){
    printf("i am a child--%s\n",(char*)arg);//线程之间没有父子线程之说
    //,最多有主线程和普通线程区别
    sleep(1);
  }
return NULL;
}
int main(int argc ,char*argv[]){
pthread_t tid;//定义一个pthread_t类型的变量用于接收线程id
int ret=pthread_create(&tid,NULL,thr_start,(void*)"nihao");
if(ret!=0){
  printf("thread create error\n");
  return -1;
}
while(1){
  printf("hello world\n");
  sleep(1);
}
  return 0;
}
