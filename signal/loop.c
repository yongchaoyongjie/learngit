#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main(){
  //int kill(pid_t pid,int sig);
  //给指定进程发送指定信号
//  kill(getpid(),11);//kill(getpid(),SIFSEGV)
  //发送11号信号
  //int raise(int sig);//给自己(调用进程/线程)发送一个信号不用指定ID
 // raise(SIGQUIT);//3号信号
 // void abort(void),给一个进程发送一个SIGABRT信号给调用进程发
 //abort();
 //unsigned int alarm(unsigned int seconds);
 // seconds秒之后给调用进程发送SIGALRM信号,seconds为0取消定时器
 // 返回值值返回上一个定时器剩余的时间或者为0(之前没有定时器为0)
int ret= alarm(3);
sleep(1);
ret=alarm(0);
  while(1){
    printf("nihaoa ---[%d]\n",ret);
    sleep(1);
  }
  return 0;
}
