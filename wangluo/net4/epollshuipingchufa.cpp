#include<sys/epoll.h>
#include<vector>
#include "tcpsocketxiugaihou1.hpp"
class Epoll{
  private:
    int    _epfd;
  public:
    bool Init(){
      _epfd=epoll_create(1);
      if(_epfd<0){
        perror("epoll create errno");
        return false;
      }
      return true;
    }
    bool Add(TcpSocket sock,uint32_t events=0){
  sock.SetNonBlock();//设置成非阻塞
      int fd=sock.Getsocketfd();
      struct epoll_event ev;
      ev.events=EPOLLIN|events;
      ev.data.fd=fd;
      int ret=epoll_ctl(_epfd,EPOLL_CTL_ADD,fd,&ev);
      if(ret<0){
        perror("epoll ctrl errno");
        return false;
      }
      return true;
    }
    bool DEL(TcpSocket sock ){
      int fd=sock.Getsocketfd();
      int ret=epoll_ctl(_epfd,EPOLL_CTL_DEL,fd,NULL); 
      if(ret<0){
        perror("epoll ctrl errno");
        return false;
      }
      return true;
    }
    bool Wait(std::vector<TcpSocket>&list,int ms_timeout=1000){
      struct epoll_event evs[10];//10最好定义成宏
      int nfd=epoll_wait(_epfd,evs,10,ms_timeout);
      if(nfd<0){
        perror("epoll wait errno");
        return  false;
      }else if(nfd==0){
        cout<<"epllwait  time out"<<endl;
        return false;
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
  CHECK_RET(lst_sock.Bind("0.0.0",9000));//绑定地址
  CHECK_RET(lst_sock.Listen());
  Epoll epoll;//将epoll放进去
  CHECK_RET(epoll.Init());//创建epoll
  CHECK_RET(epoll.Add(lst_sock,EPOLLET));
  while(1){
    std::vector<TcpSocket>list;
    bool ret=epoll.Wait(list);
    if(ret==false){
      continue;
    }
    for(int i=0;i<list.size();++i){
      if(list[i].Getsocketfd()==lst_sock.Getsocketfd()){//是监听描述符
        TcpSocket cli_sock;
        lst_sock.Accept(cli_sock);
        epoll.Add(cli_sock,EPOLLET);//改为边缘触发
//对于可读事件新数据到来触发一次可读事件对于可写事件只有缓冲区空闲空间从没有
//空间变成有空间时候才会触发--->从没有变陈有的时候才会触发
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
