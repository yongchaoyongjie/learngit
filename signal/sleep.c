#include<signal.h> 
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
void sigcb(int signo){

}
int mysleep(int nsec){
  signal(SIGALRM,sigcb);
  alarm(nsec);
  pause();//永久阻塞但是被信号打断了

}
int main(){
mysleep(2);
printf("-----");
}
