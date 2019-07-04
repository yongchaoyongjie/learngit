#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <errno.h>
#include <pthread.h>
void *thr_start(void *argv){
  while(1){
    sleep(1);
    printf("i am child\n");
  }
}
int main(int argc,char *argv[]){
  //int pthread_create(pthread_t*thread, 
  //const pthread_attr_t *attr, 
  //void *(*start_routine)(void *), void *arg);
pthread_t tid;
  int ret=pthread_create(&tid,NULL,thr_start,(void*)"nihao");
    if(ret!=0){
      printf("thread creat error \n");
        return -1;
    }
    while(1){
      printf("helow world\n");
      sleep(1);
    }

  return 0;
}
