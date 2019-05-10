#include<iostream>
#include<queue>
#include<semaphore.h>
#include<pthread.h>
//posix下的信号量的应用-->实现一个环形队列
class RingQueue{
  public:
    RingQueue(int cap=10 ):_queue(10),_write_m(0),_read_m(0),
    _capty(cap){
      //sem_init( sem_t *__sem, int __pshared, unsigned int __value  )
      sem_init(&sem_data,0,0);//队列中已经有的数据
      sem_init(&sem_leftdata,0,cap);//队列中空的格子可以剩下存的数据
      sem_init(&sem_lock,0,1);//锁
    }
    ~RingQueue(){
      sem_destroy(&sem_data);
      sem_destroy(&sem_leftdata);
      sem_destroy(&sem_lock);
    }
    bool Queuepush(int data){//入队
      ProductorWait();
      Queuelock();
      _queue[_write_m]=data;
      _write_m=(_write_m+1)%_capty;
      Queueunlock();
      Wakeupcustomer();
      return true;
    }
    bool Queuepop(int *data){
      CustomerWaite();
      Queuelock();
      *data=_queue[_read_m];
      _read_m=(_read_m+1)%_capty;
      Queueunlock();
      Wakeupproductor();
      return true;
    }
  private:
    void Queuelock(){
      //计数减1等待
      sem_wait(&sem_lock);
    }
    void Queueunlock(){
      sem_post(&sem_lock);
    }
    void ProductorWait(){
      sem_wait(&sem_leftdata);
    }
    void Wakeupproductor(){
      sem_post(&sem_leftdata);
    }
    void CustomerWaite() {
      sem_wait(&sem_data);
    }
    void Wakeupcustomer(){
      sem_post(&sem_data);
    }

  private:
    std::vector<int>_queue;
    int _capty;
    int data;
    sem_t sem_data;
    sem_t sem_leftdata;
    sem_t sem_lock;
    int _read_m;
    int _write_m;
};
void *thr_cstart(void*argv){
  RingQueue*q=(RingQueue*)argv;
  while(1){
    int data;
    q->Queuepop(&data);
    std::cout<<"消费者拿数据为"<<data<<std::endl;
  }
  return NULL;
}
void *thr_pstart(void*argv){
  RingQueue*q=(RingQueue*)argv;
  int i=0;
  while(1){
    q->Queuepush(i);
    std::cout<<"生产者拿到的数据为:"<<i<<std::endl;
    i++;
  }

}
int main(int argc,char*argv[]){
  int i;
  int ret;
  RingQueue q;
  pthread_t ctid[5];
  pthread_t ptid[5];
  for(i=0;i<=4;i++){
   ret=pthread_create(&ctid[i],NULL,thr_cstart,(void*)&q);
    if(ret!=0){
      std::cout<<"create pthread errno\n" ;
      return -1;
    }
  }
  for(i=0;i<=4;i++){
   ret=pthread_create(&ptid[i],NULL,thr_pstart,(void*)&q);
   if(ret!=0){
    std::cout<<"create pthread errno\n";
    return -1;
  }
  }
  for(i=0;i<=4;i++){
    pthread_join(ptid[i],NULL);
  }
  for(i=0;i<=4;i++){
    pthread_join(ctid[i],NULL);
  }
  return 0;
}
