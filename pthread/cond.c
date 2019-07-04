#include<unistd.h>
#include<stdio.h>
#include <errno.h>
#include<stdlib.h>
#include<pthread.h>
//面馆吃面程序-->有人卖面有人吃面-->如果没有现成的面等待老板做面老板做出来面
//唤醒顾客吃面
//老板不会做太多的面-->老板只会提前做一碗面如果已经有面做出来但是没人吃不会
//再做(等待),顾客吃完面只会,老板再来一碗(唤醒老板的等待)
//条件变量实现同步
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//结构体赋值方式初始化
//int pthread_cond_init(pthread_cond_t *restrict cond,
//const pthread_condattr_t *restrict attr);
pthread_cond_t cond;//定义cond类型变量,创建线程前初始化条件变量
int is_have_noodle=0;
pthread_mutex_t mutex;
void* the_sale(void*arg){
  while(1){
      //int pthread_cond_wait(pthread_cond_t *restrict cond,
      //pthread_mutex_t *restrict mutex);
      //第一个参数是条件变量第二个为互斥锁cond:条件变量
//为什么要互斥锁?is_have_noodle是全局变量,它的操作要受保护,条件变量
//的使用势必会涉及外部条件的判断,外部条件的判断通常是全局数据的操作
//对全局数据操作就要加锁mutex:互斥锁
    pthread_mutex_lock(&mutex);//加锁
    //有面没人吃等待
    if(is_have_noodle!=0){
      pthread_cond_wait(&cond,&mutex);//wait实现了原子操作先解锁后休眠的操作,有可能还没来得及挂起就已经唤醒等于白唤醒导致死等
      //prhread_cond_wait 集合了解锁等待加锁
    }
    printf("sale---make noodles\n");
    is_have_noodle +=1;
//int pthread_cond_broadcast(pthread_cond_t *cond);
//唤醒所有等待的线程广播唤醒,唤醒所有等待的人
//int pthread_cond_signal(pthread_cond_t *cond);
//唤醒至少一个等待的线程
pthread_cond_signal(&cond);//做完面唤醒吃面的人,吃面
    pthread_mutex_unlock(&mutex);
  }
return NULL;
}
void* the_buy(void*arg){
  while(1){
    //没有面则休眠等待
    pthread_mutex_lock(&mutex);
    if(is_have_noodle==0){
      pthread_cond_wait(&cond,&mutex);
    }
    //吃面
    printf("buy---the noodles is delicious\n");
    is_have_noodle -=1;
    //吃完面太好吃唤醒老板再来一碗
    pthread_cond_signal(&cond);//唤醒做面的人
    pthread_mutex_unlock(&mutex);
  }
return NULL;
}
int main(int argc,char*argv[]){
pthread_t tid1,tid2;
int ret;
//int pthread_cond_init(pthread_cond_t *restrict cond,
//const pthread_condattr_t *restrict attr);
//参数1条件变量的变量,参数2一般置空
pthread_cond_init(&cond,NULL);
pthread_mutex_init(&mutex,NULL);
ret=pthread_create(&tid1,NULL,the_sale,NULL);
if(ret!=0){
  printf("thread1 create erro\n");
  return -1;
}
ret=pthread_create(&tid2,NULL,the_buy,NULL);
if(ret!=0){
  printf("thread2 create erro\n");
  return -1;
}
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
//销毁条件变量
//int pthread_cond_destroy(pthread_cond_t*cond);
//参数为条件变量
pthread_cond_destroy(&cond);
pthread_mutex_destroy(&mutex);
return 0;
}
