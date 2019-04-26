#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int ticket_cout=100;
pthread_mutex_t mutex;//一定要在没有创建线程之前初始化互斥锁
void*thr_start(void*arg){
  while(1){
    //加锁
    //int pthread_mutex_lock(pthread_mutex_t *mutex);
    //加锁的时候锁为0加不上锁已近被别人获取到锁了它会阻塞-->阻塞加锁
    // int pthread_mutex_trylock(pthread_mutex_t *mutex);
    // 尝试加锁加不到就不加了,不阻塞直接报错返回,通过返回值判断
    // -->非阻塞加锁
    //法3 定义一个宏 _USE_XOPEN2K
    // extern int pthread_mutex_timelock(
    // pthread_mutex_t* _restrict _mutex,//传互斥锁变量
    // const struct timespec *_restrict_abstime)
    // //传了时间(结构体类型的时间
    // timespec{ _time_t sec//秒,_syscall_slong_t tv_nsec;//纳秒 })
    // _THROWNL _nonnull((1,2))
    // 表示如果能直接加锁就直接加锁,如果不能加锁传一段时间折段时间
    // 尝试加锁如果折段时间能加到加这段时间中还加不到则返回-->限时
    //等待加锁
    pthread_mutex_lock(&mutex);
    if(ticket_cout>0){//临界资源访问之前加锁
      usleep(1000);
printf("yellow bull---%d-%p get ticket:%d\n",
 (int*)arg,pthread_self() ,ticket_cout);//获取自己的线程id
ticket_cout--;
    }else{
pthread_mutex_unlock(&mutex);//最后一个卖票的人直接退出但是没有解锁
//->加锁之后再任意一个有可能退出线程的地方都要加锁-->不然其他线程
//无法操作了
      return NULL; 
    }
//解锁
//int pthread_mutex_unlock(pthread_mutex_t *mutex);
pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
int main(int argc,char*argv[]){
pthread_t tid[4];
int i,ret;
//1初始化互斥锁
//int pthread_mutex_init(pthread_mutex_t *restrict mutex,
//const pthread_mutexattr_t *restrict attr);
//mutex是互斥锁变量
//attr互斥锁属性一般置空
pthread_mutex_init(&mutex,NULL);
pthread_mutex_t mutex;//一定要在没有创建线程之前初始化互斥锁
for(i=0;i<4;i++){
ret=pthread_create(&tid[i],NULL,thr_start,(void*)i);
}
if(ret!=0){
  printf("thread create erron");
return -1;
}
for(i=0;i<4;i++){
pthread_join(tid[i],NULL);//主线程退出
}
//互斥锁销毁.互斥锁的销毁一定不能放在互斥锁join之前,等待之前就销毁了
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//mutex互斥锁销毁
pthread_mutex_destroy(&mutex);
  return 0;
  }
