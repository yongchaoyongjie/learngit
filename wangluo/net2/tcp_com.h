#ifndef _M_TCP_H_
#define _M_TCP_H_ 
#include <iostream>
#include<string>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#define CHECK_RET(q)  if((q)==false){return false;}
//头文件冲突-->define 根据宏参数不同使用不同函数
class TcpSocket{
  private:
    int _socketfd;
  public:
    TcpSocket():_socketfd(-1){}//构造函数初始化为-1
    //1创建socket()
    bool Socket(){
      //socket( int __domain, int __type, int __protocol ) 
      //domain:地址域(协议族)  AF_INET--->ipv4
      //type套接字类型参数三协议流式套接字默认给0指的是tcp数据报套接字默认给0指的是u    dp
      //参数2:SOCK_STREAM   IPPROTO_TCP 6 流式套接字默认协议
      // SOCK_DGRAM IPPROTO_UDP  17数据报套接字默认udp
      //返回值成功返回一个文件描述新的socket(为新的套接字返回一个文件描述符)失败-1
      _socketfd=socket(AF_INET,SOCK_STREAM,6);
      if(_socketfd<0){
        perror("socket errno\n");
        return false;
      }
      return true;
    }
    //绑定地址信息,端口
    bool Bind(std::string &ip,uint16_t port){
      //int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);          第一个套接字描述符第二个地址信息(ip地址端口号)struct socketaddr{sa_family sa_family;地址域什么样的地址信息char sa_data[14]//真正的地址信息如何排布各个自己的结构体就好};第三参数地址信息返回值成功0失败-1
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr("192.168.96.128");
      return true;
      socklen_t len=sizeof(sockaddr_in);
      int ret=bind(_socketfd,(sockaddr*)&addr,len);
      if(ret<0){
        perror("bind errno\n");
        return false;
      }
      return true;
    }
    //3服务端开始监听
    //int listen(int s, int backlog);一个参数socket描述符第二个参数:最大并发连接数,服务端同时接受到多个连接请求-->同一时间最大的连接数,返回值成功0失败-1
    bool Listen(int baklog=5){
      int ret=listen(_socketfd,5);
      if(ret<0){
        perror("listen errno\n");
        return false;
      }
      return true;
    }
    //4服务端获取连接成功的scoket描述符(accept 2系统调用)
    //int accept(int s, struct sockaddr *addr, socklen_t *addrlen);
    //accept功能从已完成连接队列中将数据拿出 
    //s:套接字描述符 addr:新连接客户端的地址信息addrlen:地址信息长度(输入输出复合参数),不但指定地址多长还要获取实际的长度有多长
    //返回值:成功新建立socket的描述符失败-1
    bool Accept(TcpSocket*sock,sockaddr_in*_addr=NULL){
      int newfd;
      sockaddr_in addr;
      socklen_t len=sizeof(sockaddr_in);
      newfd=accept(_socketfd,(sockaddr*)&addr,&len);
      if(newfd<0){
        perror("accept errno\n");
        return false;
      }
      sock->_socketfd=newfd;//返回新的socket
      if(_addr!=NULL){
        memcpy((void*)_addr,(void*)&addr,len);//获取地址信息
      }
      return true;
    }
    //5服务端收发数据
    ssize_t Recv(char*buf,ssize_t len){
      //tcp有连接并且为每个客户端都创建了socket进行单独通信意味着在接收数据的时候不需要再获取客户端的地址信息已经很明确了和谁通信
      //ssize_t recv(int sockfd, void *buf, size_t len, int flags);1:数据传输的socket描述符2:接收的数据放到哪一块len接受数据长度flag默认给0阻塞接收
      //flag参数有MSG_PEEK-->探测性接收(看数据干什么的符合要求则接受不符合则不接受)
      //返回值:返回实际的接收长度   失败:-1
      //ssize_t rlen=0;//接受数据时候不知道接受数据有多长(所以用一个宽泛的数字1024
      //获取了如果给了1024但是缓冲区只有100个字节第一次获取100个字节然后获取剩下的剩下的获取不到就阻塞了没办法返回直到1024才返回-->也会存在这种错误此处不考虑
      //while(rlen!=len){
      ssize_t ret=recv(_socketfd,buf,len,0);
      return ret;
    }
    ssize_t Send(char*buf,ssize_t len){
      //ssize_t send(int s, const void *buf, size_t len, int flags);
      //参数1socket描述符,buf中的数据,长度为len;flags默认给0阻塞操作
      //返回值成功实际的发送长度失败:-1-->实际完成操作是将数据拷贝到缓冲区里-->会被打断->进程终端,信号,-->万一被打断就继续发
      int slen=0;//slen表示当前已经发送的数据的长度
      //len-slen要发送剩下的数据->但是发送数据永远是从buf的起始位置发送代表剩下数据
      //发送数据是从开始位置(buf的起始位置进行发送)发送-->发送出错应该从上次打断的
      //位置开始发送-->buf+slen发送,发送长度为len-slen
      while(slen!=len){
        ssize_t s=send(_socketfd,buf+slen,len-slen,0);
        if(s<0){
          if(errno==EINTR||errno==EAGAIN){
            //EINTR操作被信号产生打断-->没传送完就是出错-->信号打断产生的错误-->适用场景在非阻塞场景
            continue;
          }
          //EAGAIN/EWOULDBLOCK-->错误原因叫当前在接受发送数据的时候
          return -1;
        }
        slen+=s;//发送多少就加多少下次就从加多少后的位置开始发送
      }
      return slen;
    }
    //3客户端发起连接请求
    //int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
    //客户端向服务端发起连接请求告诉socket请求的服务端地址是多少
    //参数1:客户端socket描述符2:服务端的地址信息(通过socket向服务端发起连接请
    //求)参数3:地址信息的长度返回值0  -1
    bool Connect(std::string &ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      socklen_t len=sizeof(sockaddr_in);
      int ret=connect(_socketfd,(sockaddr*)&addr,len);
      if(ret<0){
        perror("connect errno\n");
        return false;
      }
      return true;
    }
    //6关闭socket
    bool Close(){
      if(_socketfd>=0){
        close(_socketfd);
        _socketfd=-1;
      }
      return true;
    }

    };
#endif
