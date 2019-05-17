#include<iostream>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<queue>
using std::cout;
using std::endl;
#define MAX_thr 5
#define MAX_QUE 10
#define MAX_TASK 10
typedef bool(*the_ways_task)(int data);
bool dealdata(int data){
  srand(time(NULL));
  int n=rand()%5;
  cout<<"thread:----"<<pthread_self()<<endl;
  cout<<"deal with data"<<data<<endl;
  cout<<"sleep times"<<n<<endl;
  sleep(n);
  return true;
}
class Task{
  public:
    Task(){
    }
    ~Task(){
    }
    void SetTask(int data ,the_ways_task handle){
      _data=data;
      _handle=handle;
    }
    bool Run(){
      return _handle(_data);
    }
  private:
    int _data;
    the_ways_task _handle;
};
class PthreadPool{
  private:
    int _capcity;
    std::queue<Task> _queue;
    int _max_pthr;
    int _cur_pthr;
    pthread_cond_t _cond_constomer;
    pthread_cond_t _cond_productor;
    pthread_mutex_t _mutex;
    int _quit_flag;
  public:
    PthreadPool(){
    }
    ~PthreadPool(){
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond_constomer);
      pthread_cond_destroy(&_cond_productor);
    }
    bool pthreadInit(int max_pthr=MAX_thr,int max_que=MAX_QUE){
      _quit_flag=false;
      _capcity=max_que;
      _max_pthr=max_pthr;
      _cur_pthr=max_pthr;
      pthread_mutex_init(&_mutex,NULL);
      pthread_cond_init(&_cond_constomer,NULL);
      pthread_cond_init(&_cond_productor,NULL);
      int ret;
      pthread_t tid[MAX_thr];
      int i;
      for(i=1;i<MAX_thr;i++){
        ret=pthread_create(&tid[i],NULL,pthr_star,(void*)this);
        if(ret!=0){
          cout<<"pthread create fail\n";
          return false;
        }
        pthread_detach(tid[i]);
      }
      return true;
    }
  private:
    void Queuelock(){
      pthread_mutex_lock(&_mutex);
    }
    void QueueUnlock(){
      pthread_mutex_unlock(&_mutex);
    }
    void ConstomerWait(){
      //进入消费者等待说明这个时候没有数据要处理,则解锁退出
      if(_quit_flag==true){
        pthread_mutex_unlock(&_mutex);
        cout<<pthread_self()<<endl;
        _cur_pthr--;
        pthread_exit(NULL);
      }
      pthread_cond_wait(&_cond_constomer,&_mutex);
    }
    void WakeupConstomer(){
      pthread_cond_signal(&_cond_constomer);
    }
    void Productorwait(){
      pthread_cond_wait(&_cond_productor,&_mutex);
    }
    void WakeupConstomerall(){
      cout<<"Wakeup all"<<endl;
      pthread_cond_broadcast(&_cond_constomer);
    }
    void WakeupProductor(){
      pthread_cond_signal(&_cond_productor);
    }
    bool QueueIsEmpty(){
      return _queue.empty();
    }
    bool QueueIsFull(){
      return(_capcity==_queue.size());
    }
    void PopTask(Task &task){
      task=_queue.front();
      _queue.pop();
    }
  public:
    bool PushTask(Task &task){
      if(_quit_flag==true){
        return false;
      }
      Queuelock();
      while(QueueIsFull()){
        //特殊情况当队列满的时候
        Productorwait();
      }
      _queue.push(task);
      ConstomerWait();
      QueueUnlock();
      return true;
    }
    void threadquit(){
      if(_quit_flag!=true){
        _quit_flag=true;
      }
      while(_cur_pthr>0){
        WakeupConstomerall();
        sleep(1);
      }
      return ;
    }
  private:
    static void *pthr_star(void*argc){//类里面有this指针所以要静态
      //入口函数处理任务
      PthreadPool *pool=(PthreadPool*)argc;
      while(1){
        pool->Queuelock();
        while(pool->QueueIsEmpty()){//特殊情况
          pool->ConstomerWait();
        }
        Task task;
        pool->PopTask(task);
        pool->WakeupProductor();
        pool->QueueUnlock();
        task.Run();
      }
    
      return NULL;
    }
};
    int main(int argc,char* argv[]){
     PthreadPool pool;
      pool.pthreadInit();
      int i;
      //添加任务
      Task task[MAX_TASK];
      for(i=0;i<MAX_TASK;i++){
        //  task[i].SetTask( int data, the_ways_task handle )
        task[i].SetTask(i,dealdata);
        pool.PushTask(task[i]);
      }
      pool.threadquit();
      return 0;
    }

