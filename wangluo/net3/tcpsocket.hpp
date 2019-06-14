#include<iostream>
#include <string>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<netinet/in.h>
using std::cout;
using std::cin;
using std::endl;
#define  CHECK_RET(q) if((q)==false){return -1;}
class TcpSocket{
  public:
    TcpSocket():_socketfd(-1)
  {}
    void Setsocketfd(int fd){
fd=_socketfd;
    }
    int Getsocketfd(){
      return _socketfd;
    }
    bool Socket(){
      //绑定套接字第一个参数是AF_INET(IPV4)SOCK_STREAM(TCP)SOCK_DGRAM(UDP)
      //6IPPROTO_TCP支持tcp 17IPPROTO_UDP-->udp
//socket( int __domain, int __type, int __protocol )
      _socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
      if(_socketfd<0){
        cout<<"cerate errno"<<endl;
        return false;
      }
      return true;
    }
    bool Bind(const std::string &ip,const uint16_t port){
//bind((int _fd,const struct sockaddr *_addr, socklen_t _len)
//绑定套接字fd套接字描述符 _addr地址信息 _len地址信息长度
struct sockaddr_in addr;
addr.sin_family=AF_INET;
addr.sin_port=htons(port);//绑定端口
addr.sin_addr.s_addr=inet_addr(ip.c_str());//ip地址用的是c风格的字符串
socklen_t len=sizeof(sockaddr_in);
int ret=bind(_socketfd,(struct sockaddr*)&addr,len);
if(ret<0){
  cout<<"bind errno"<<endl;
  return false;
}
return true;
    }
bool Listen(const int n=10){
//listen(int _fd,int n)-->_fd文件描述符 n最大并发连接数监听最多几个
int ret=listen(_socketfd,n);
if(ret<0){
  cout<<"listen errno"<<endl;
  return false;
}
return true;
}
bool Connect( const std::string &ip,const uint16_t port){
  //建立连接要有端口号和ip地址
//connect(int _fd,const struct sockaddr *_addr,socklen_t _len)
//建立连接
struct sockaddr_in addr;
addr.sin_port=htons(port);
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=inet_addr(ip.c_str());
socklen_t len=sizeof(sockaddr_in);
int ret=connect(_socketfd,(struct sockaddr*)&addr,len);
if(ret<0){
  cout<<"connect errno"<<endl;
  return false;
}
return true;
}
bool Accept(TcpSocket &csock,struct sockaddr_in *addr=NULL){
//accept(int _fd, struct sockaddr *_restrict _addr, socklen_t *_restrict _ );
//addr 客户端的地址信息len输入参数指定接收的长度和接收的实际长度
//返回值为一个新的套接字描述符
//这个描述符可以与指定的客户进行通信
struct sockaddr_in _addr;
socklen_t len=sizeof(sockaddr_in);
int newfd=accept(_socketfd,(sockaddr*)&_addr,&len);
if( newfd<0){
  cout<<"accept errno"<<endl;
  return false;
}
if(addr!=NULL){
  memcmp(addr,&_addr,len);
}
csock.Setsocketfd(newfd);//_socketfd接收请求,newfd用于专门通信-->门迎和里面服务员
return true;
}
bool Recv(std::string &buf){
//recv(int __fd, void *__buf, size_t __n, int __flags)
//接收的数据放在数组里,n接收的长度,flag0默认阻塞接受
//返回值小于0接收错误,等于0连接断开
char buf1[4096]={0};
int ret=recv(_socketfd,buf1,4096,0);
if(ret<0){
cout<<"rec errno"<<endl;
return false;
}
if(ret==0){
  cout<<"connect shutt down"<<endl;
return false;
}
buf.assign(buf1,ret);//buf.assign 什么意思-->拷贝
return true;
}
bool Send(std::string &buf){
//发送数据的长度
//send(int __fd, const void *__buf, size_t __n, int __flags )
int ret=send(_socketfd,buf.c_str(),buf.size(),0);
if(ret<0){
  cout<<"send errno"<<endl;
  return false;
}
return true;
}
bool Close(){
  close(_socketfd);
  _socketfd=-1;
}
  private:int _socketfd;
};
