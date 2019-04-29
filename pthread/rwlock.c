//读写锁的基本使用:设置写优先
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
pthread_rwlock_t rwlock;
void* thr_reader(void*arg){
  while(1){
    pthread_rwlock_rdlock(&rwlock);//加读锁
printf("thread reader--\n");
    usleep(1000);
    pthread_rwlock_unlock(&rwlock);//解锁
  }
return NULL;
}
void*thr_writer(void*arg){
  while(1){
    pthread_rwlock_wrlock(&rwlock);//加写锁
printf("thread writer---\n");
    usleep(1000);
    pthread_rwlock_unlock(&rwlock);//写锁
  }
  return NULL;
}
int main(){
  pthread_t rtid[4],wtid[4];
  int i,ret;
  //设置属性初始化改变优先级
  //int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
  //int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
  //int phtread_rwlockattr_setkind_np(pthread_rwlockattr_t*attr,
  //int _pref)
  //attr读写锁属性,pref优先级属性
  //PTHREAD_RWLOCK_PREFER_READER_NP//读优先             
  // 128   PTHREAD_RWLOCK_PREFER_WRITER_NP,//读优先
  //  129   PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,//写优先
  //   130   PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
  // 读写锁 默认读优先 
  // 比如写优先加写锁但是一直有人在读等到正在读的人读完但是后序有人继续要加读
  // 锁它是加不上的
  pthread_rwlockattr_t attr;
  pthread_rwlockattr_init(&attr);
pthread_rwlockattr_setkind_np(&attr,PTHREAD_RWLOCK_PREFER_READER_NP);
  //读写锁初始化
  pthread_rwlock_init(&rwlock,&attr);
  //销毁属性
  pthread_rwlockattr_destroy(&attr);
  for(i=0;i<4;i++){
    ret=pthread_create(&rtid[i],NULL,thr_reader,NULL);
    if(ret!=0){
      printf("create thread erron\n");
      return -1;
    }
  }
  for(i=0;i<4;i++){
    ret=pthread_create(&wtid[i],NULL,thr_writer,NULL);
    if(ret!=0){
      printf("create thread erron\n");
      return -1;
    }
  }
  for(i=0;i<4;i++){
    pthread_join(rtid[i],NULL);
    pthread_join(wtid[i],NULL);
  }
  pthread_rwlock_destroy(&rwlock);//读写锁的销毁
  return 0;
}
