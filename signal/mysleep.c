#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<unistd.h>
void sigcb2(int signo){
  sleep(10);
}

void sigcb(int signo){
//什么都不做,进程不会退出
}
int mysleep(int  nsec){
  signal(SIGALRM,sigcb);//重新定义改变SIGALRM的处理方式不让它
  //退出进程让它变成sigcb
  //此处用sigaction合适,最后还得还原SIGALRM原来的处理方式
  sigset_t set,old;
  sigemptyset(&set);
  sigprocmask(SIG_BLOCK,&set,&old);//阻塞了SIGALRM
  alarm(nsec);//ns之后的信号
 // sigprocmask(SIG_UNBLOCK,&set,&old);//接触阻塞此处sigprocmask
  //和pause也不是原子操作,需要的是接触SIGALRM的阻塞以及陷入暂停
//int sigsuspend(const sigset_t *mask);
//临时拿marsk中的信号阻塞信号然后陷入休眠,被唤醒之后阻塞集合还原
sigset_t mask;
//法1
sigfillset(&mask);
sigdelset(&mask,SIGALRM);//只把SIGALRM移除了,阻塞了所有信号但是没有
//阻塞SIGALRM,意味着只有SIGALRM可以唤醒,也就是除了SIGALRM
//阻塞所有的信号,陷入休眠
//法二sigemptyset(&mask);//清空mask,没有有阻塞任何信号,等价于法1
sigsuspend(&mask);//不包含SIGALRAM对SIGALRM解除了阻塞,
sigprocmask(SIG_SETMASK,&old,NULL);//还原其他的阻塞信号
signal(SIGALRM,SIG_DFL);//还原SIGALRM原来默认方式
}
int main(){
  signal(SIGQUIT,sigcb2);
  mysleep(3);
  printf("--------\n");
  return 0;
}
