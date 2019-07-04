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
        perror("epoll create errno");
        return false;
      }
      return true;
    }
    bool Add(TcpSocket sock,uint32_t events=EPOLLIN){
      int fd=sock.Getsocketfd();
      //定义事件
      struct epoll_event ev;//事件结构
      ev.events=events;//默认水平触发EPOLLIN
      ev.data.fd=fd;//ev.data.fd/ev.data.ptr都可以使用(ev.data.ptr=&sock)
      //void*,返回sock前提是tcpsocket不能是局部变量,不然会被销毁掉,new数据合适
      //int epoll_ctl(int epfd,int op,int fd, struct epoll_event *event);
      //create返回的epoll句柄,op用户要进行的操作,EPOLL_CTL_DEL移除监控事件结构
      //EPOLL_CTL_MOD修改内核中所监控的事件结构,fd用户所要监控的描述符,event描述符对
      //应所要监控的事件信息
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
      //int epoll_wait(int epfd, struct epoll_event *events,
      // int maxevents, int timeout);开始监控让操作系统监控,epoll在内核中循环遍历
      // 判断双向链表是否为空,从而实现描述符监控,并且在返回之前,将就绪事件拷贝到
      //struct epoll_event 结构数组当中
      //1定义数组
      struct epoll_event evs[10];//10最好定义成宏
      int nfd=epoll_wait(_epfd,evs,10,ms_timeout);//第一个参数_epfd,第二个参数数组
      //evs,获取最大就绪结点数目给10(一般和数组一样)第四个参数超时时间
      if(nfd<0){
        perror("epoll wait errno");
        return  false;
      }else if(nfd==0){
        cout<<"epllwait  time out"<<endl;
        return false;
      }
      //成功后把数据放到evs中,有几个就绪就有几个结点里面有数据,只需要取数组中前
      //nfd个数据就可以了
      for(int i=0;i<nfd;++i){
        int fd=evs[i].data.fd;//获取描述符
        TcpSocket sock;
        sock.Setsocketfd(fd);//创建fd
        list.push_back(sock);//将sock放进去
      }
      return true;
    }
};
int main(){
 // //tcp服务器流程,接收数据,但是不发送数据
 // TcpSocket lst_sock;
 // CHECK_RET(lst_sock.Socket());
 // CHECK_RET(lst_sock.Bind("0.0.0",9000));//绑定地址
 // CHECK_RET(lst_sock.Listen());
 // while(1){
 //   TcpSocket cli_sock;
 //   lst_sock.Accept(cli_sock);
 //   std::string buf;
 //   cli_sock.Recv(buf);
 //   cout<<"client say "<<buf<<endl;
 // }
  TcpSocket lst_sock;
  CHECK_RET(lst_sock.Socket());
  CHECK_RET(lst_sock.Bind("0.0.0",9000));//绑定地址
  CHECK_RET(lst_sock.Listen());
  Epoll epoll;//将epoll放进去
  CHECK_RET(epoll.Init());//创建epoll
  CHECK_RET(epoll.Add(lst_sock));//添加监控,将监听描述符添加进去
  while(1){
    //集中监控
    std::vector<TcpSocket>list;
    bool ret=epoll.Wait(list);//开始监听,list保存的监听描述符和普通描述符
    if(ret==false){
      continue;
    }
    //保存的就绪的
    for(int i=0;i<list.size();++i){//等待成功list保存的是就绪的描述符,
      //就绪的描述符有1监听描述符2普通描述符客户端新连接的描述符
      if(list[i].Getsocketfd()==lst_sock.Getsocketfd()){//是监听描述符
        TcpSocket cli_sock;
        lst_sock.Accept(cli_sock);
        epoll.Add(cli_sock,EPOLLIN);//将它添加进来进行监控
        //接受了新的_sock,也要对它进行监控所以要epoll.add
      }else{
        //接受数据
        std::string buf;
        list[i].Recv(buf);
        std::cout<<"clie say: "<<buf<<endl;
      }
    }
  }
  lst_sock.Close();
  return 0;
}
