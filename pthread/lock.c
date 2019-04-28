#include <stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <stdio.h>
#include<stdint.h>
int main(){
  int i=0;
  uint64_t a=0;//无符号64位整型数据
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex,NULL);
  while(a++<1000000){
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
  }
    return 0;
}
