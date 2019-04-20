//关键字 volatile功能
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<signal.h>
volatile int i=1;//保持内存可见性,每次操作变量都需要重新从内存中获取
//功能:防止编译器过度优化
void sigcb(int signo){
  i=0;
  printf("-----\n");
 // printf("i changed\n");
}
int main(){
 while(i){
signal(SIGINT,sigcb);//按cotrl +c退出打印i change,不是因为终端默认
//退出而是因为把判断条件改了i的值改了
//sleep(2);
//printf("hhe\n");
 }
  return 0;
}
