#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main(){
//  raise(SIGTTOU);//signal
//abort();//lib库函数
int ret=alarm(1);
//返回上一个定时器剩余的时间或为0
  while(1){
    printf("nihaoa ===%d\n",ret);
    sleep(1);
  }
  return 0;
}
