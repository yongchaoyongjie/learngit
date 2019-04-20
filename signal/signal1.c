#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <signal.h>
struct sigaction oldact;
void sigcb(int signo){
  printf("recev signo :%d\n",signo);
  sigaction(signo,&oldact,NULL);//将信号的行为变成oldact,不是还原,
  //因为signo有可能会屏蔽多个信号,比如SINGIN和SINQUIT
  //oldact保存的是SIGQUIT,而不是SIGINT了如果是2号信号不是还原而是使用
  //SIGQUIT的行为
}
int main(){
  struct sigaction act;
  act.sa_handler=sigcb;
  act.sa_flags=0;
  sigemptyset(&act.sa_mask);
sigaction(SIGINT,&act,&oldact);
sigaction(SIGQUIT,&act,&oldact);
while(1){
  printf("------\n");
  sleep(1);
}
  return 0;
}
