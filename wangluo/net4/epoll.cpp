#include<sys/epoll.h>
#include<vector>
#include"tcpsocket.hpp"
class Epoll{
  private:
 int    _epfd;
  public:
    bool Init(){
//创建描述符
_epfd=epoll_create(1);//size描述监控描述符的上限现在默认给定大于1就可以
if(_epfd<0){
  cout<<"create errno"<<endl;
  return false;
}
return true;
    }
bool Add(TcpSocket sock,uint32_t events=0){
 int fd=sock.Getsocketfd();
 struct epoll_event ev;
 ev.events=events;//默认水平触发EPOLLIN
ev.data.fd=fd;
//int epoll_ctl(int epfd,int op,int fd, struct epoll_event *event);
//create返回的epoll句柄,op用户要进行的操作,EPOLL_CTL_DEL移除监控事件结构
//EPOLL_CTL_MOD修改内核中所监控的事件结构,fd用户所要监控的描述符,event描述符对
//应所要监控的事件
int ret=epoll_ctl(_epfd,EPOLL_CTL_ADD,fd,&ev);
if(ret<0){
  cout<<"epoll ctl errno"<<endl;
  return false;
}
return true;
}
bool DEL(TcpSocket sock ){
  int fd=sock.Getsocketfd();
   int ret=epoll_ctl(_epfd,EPOLL_CTL_DEL,fd,NULL); 
   if(ret<0){
     cout<<"del is errno"<<endl;
     return false;
   }
   return true;
}
bool Wait(std::vector<TcpSocket>&list,int ms_timeout=1000){
 //int epoll_wait(int epfd, struct epoll_event *events,
  //                         int maxevents, int timeout);
struct epoll_event evs[10];
int nfd=epoll_wait(_epfd,evs,10,ms_timeout);
if(nfd<0){
  cout<<"epoll Wait errno"<<endl;
  return  false;
}
for(int i=0;i<nfd;++i){
  int fd=evs[i].data.fd;
  TcpSocket sock;
  sock.Setsocketfd(fd);
  list.push_back(sock);
}
return true;
}
};
int main(){
  TcpSocket lst_sock;
  CHECK_RET(lst_sock.Socket());
  CHECK_RET(lst_sock.Bind("0.0.0",9000));
  CHECK_RET(lst_sock.Listen());
  Epoll epoll;
  CHECK_RET(epoll.Init());
  CHECK_RET(epoll.Add(lst_sock,EPOLLIN));
  while(1){
    std::vector<TcpSocket>list;
    bool ret=epoll.Wait(list);
    if(ret==false){
      continue;
      sleep(3);
    }
    for(int i=0;i<list.size();++i){
      if(list[i].Getsocketfd()==lst_sock.Getsocketfd()){
        TcpSocket cli_sock;
        lst_sock.Accept(cli_sock);
        epoll.Add(cli_sock,EPOLLIN);
      }else{
        std::string buf;
        list[i].Recv(buf);
        std::cout<<"clie say: "<<buf<<endl;
      }
    }
  }
  lst_sock.Close();
  return 0;
}
