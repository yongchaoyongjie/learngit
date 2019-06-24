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
#include<fcntl.h>
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
      _socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
      if(_socketfd<0){
        cout<<"cerate errno"<<endl;
        return false;
      }
      return true;
    }
    bool SetNonBlock(){
      //设置非阻塞-->man fcntl
      //设置获取描述符状态属性信息
//int fcntl(int fd, int cmd, ... /* arg */ );1文件描述符2对描述符进行申明操作
//3获取描述符的属性信息通过返回值来返回,和通过传入的数据去返回,也可以通过参数3
//设置描述符的某些属性F_DUPFD复制文件描述符(将这个描述符复制一个新的返回新的描述
//符F_GETFL获取文件的访问权限信息(访问模式),通过返回值返回这个模式
//F_SETFL
//模式有O_RDONLY,  O_WRONLY, O_RDWR O_CREAT, O_EXCL, O_NOCTTY, O_TRUNC等
//O_NOBLOCK将描述符设置成非阻塞所有操作都是非阻塞包括accept
//cmd:F_GETFL获取  F_SETFL 设置
int flag=fcntl(_socketfd,F_GETFL,0);//第三个参数为0忽略通过返回值返回当前属性
//int flag=fcntl(_socketfd,F_SETFL,O_NONBLOCK);不能直接设置,直接设置代表是一种
//覆盖其他属性都没有了只剩下O_NONBLOCK
fcntl(_socketfd,F_SETFL,flag | SOCK_NONBLOCK);
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
char buf1[4096]={0};
  while(1){
    //在用水平触发的时候保证一次性将数据读完要循环读取
int ret=recv(_socketfd,buf1,5,0);//一次读取去5个字节
if(ret<0){
//EAGAIN/EWOULDBLOCK表示缓冲区取没有数据
//EINTR表示当前读取操作被信号打断
  if(errno==EAGAIN||errno==EWOULDBLOCK||errno==EINTR){//错误信息
    //EINTR信号中断
    return true;//接受成功没有数据
  }
  perror("recv errno");
return false;
}
if(ret==0){
  cout<<"connect shutt down"<<endl;
return false;
}
buf1[ret]='\0';//加到\0为止
buf+=buf1;
//每次加一下放到buf直到循环到\0读完但是会出问题,会一直阻塞,它阻塞到recv,不知道
//对方发多少数据只能死循环一直读数据,但是死循环读数据会有一种情况假设接收缓冲区
//有一些数据一次读五个字节,如果这些数据在读到最后不够5个字节返回实际读取字节数
//接下来因为不知道数据从什么时候为止依然还要读,这时候没有数据则就阻塞了(recv)默认
//阻塞,所以要求不能阻塞-->边缘触发要求一次性将数据读完但是一次性读完就会导致
//程序阻塞所以将套截止至描述符设置为非阻塞
}
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
