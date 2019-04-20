#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <signal.h>
struct sigaction oldact;
void sigcb(int signo){
  printf("recv signo:%d\n",signo);
  sigaction(signo,&oldact,NULL);//将信号的行为修改成oldact
}
int main(){
 // sighandler_t signal(int signum, sighandler_t handler);
 // typedef void (*sighandler_t)(int);
 // 修改信号的处理函数,实际上修改下标对应的函数地址
 // 参数1信号编号修改哪个信号的处理方式 SIG_IGN忽略处理
 // SIG_DFL默认处理方式  第二个参数
 // handler是一个函数没有返回值并且有个int型参数,
// signal(SIGINT,sigcb);//SIGINT是2号信号,把2号信号改成自定义的sigcb
// //把默认的处理方式改回来所以写SIG_IGN改成忽略
//   //忽略就是信号来了不注册也就不处理,所以不会调用默认的处理方式
//   //就不会退出了
//   signal(SIGQUIT,sigcb);
//int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
//重新自定义函数行为只不过用struct sigaction修改的,给指定信号替换成新的行为
//第三个参数把原来的信号 行为保存下来
//struct sigation{
//void(*sa_handler)(int);//信号的回调函数同sigcb没有返回值只有一个int
////参数
//void (*sa_sigaction)(int,siginfo_t*,void*);//也是信号的回调函数
////三个参数,第一个参数表明信号值第二个为信号的具体信息(参数)
////所以发送信号携带参数就用这个而不是上一个回调函数
////有两个回调函数怎么确定用哪个,有标志位标志用哪个接口
//sigset_t sa_mask;// sigset_t是位图  sa_mask 在进行信号处理的时候临时阻塞一些
////信号当信号被处理完则这些信号接触阻塞(防止一个信号处理的时候又有其他信号
////处理被打断所以阻塞其他信号)
//int sa_flags;//标志位给0代表为sa_handler回调接口如果被指定为SA_SIGINFO则
////信号的处理函数为sa_sigaction,所以默认为_handler
//void (*sa_restorer)(void);//预留没用
//};
struct sigaction act;//定义行为结构
//struct sigaction oldact;//保存原有行为
act.sa_handler=sigcb;//定义新行为默认处理方式所以要给sa_handler给回调就是sigcb
act.sa_flags=0;//默认为_handler被指定为SA_SIGINFO则回调为sa_sigaction
//act.sa_mask;//临时阻塞信号,就是把这个清空不受原有值影响(法1为数组所以memset)
//法二:清空指定的信号集合int sigemptyset(sigset_t *set);
sigemptyset(&act.sa_mask);
sigaction(SIGINT,&act,&oldact);
  while(1){
    printf("-----\n");
    sleep(1);
  }
  return 0;
}
