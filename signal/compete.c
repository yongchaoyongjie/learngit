//竞态条件的初步认识
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int  a=0;
int b=0;
int add(){
  a++;
  sleep(10);
  b++;
  return a+b;
}
void sigcb(int signo){//睡眠十秒钟在这之间
printf("signal----%d\n",add());
}
int main(){
  signal(SIGINT,sigcb);
 printf("main---%d\n",add()) ;//2
}
