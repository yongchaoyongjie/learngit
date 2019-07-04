#include<netinet/in.h>
#include<iostream>
#include<sys/socket.h>
#include<string.h>
#include<string>
#include<errno.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
//使用c++封装一个udp的socket类
//贯穿整个upd的数据是套接字描述符socketfd-->就是私有成员-->句柄
class UdpSocket{
  private:
    int _sockfd;
  public:
    UdpSocket():_sockfd(-1){}//构造函数
    //1创建套接字
    bool Socket(){
      //int socket(int domain, int type, int protocol);AF_INET-->ipv4
      //参数2:SOCK_STREAM   IPPROTO_TCP 6 流式套接字默认协议
      //   SOCK_DGRAM IPPROTO_UDP  17数据报套接字默认udp
      //
      _sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
      if(_sockfd<0){
        perror("socket create errno\n");
        return false;
      }
      return true;
    }
    //2为套接字绑定地址信息//ip地址和端口
    bool Bind(std::string &ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;//地址域
      addr.sin_port=htons(port);//端口
      addr.sin_addr.s_addr=inet_addr(ip.c_str());//点分十进制转换
      socklen_t len=(sizeof(sockaddr_in));
      //bind( int __fd, const struct sockaddr *__addr, socklen_t __len  )
      int ret=bind(_sockfd,(sockaddr*)&addr,len);
      if(ret<0){
        perror("bind errno\n");
        return false;
      }
      return true;
    }
    //3接受数据-->返回实际接受的长度
    ssize_t Recv(char*buf,size_t len,sockaddr_in*addr=NULL){
      //buf获取发的sockaddr_in获取地址信息-->只要获取数据不需要获取地址信息--
      //null,len为接受的数据长度
      int ret;
      //recvfrom( int __fd, void *__restrict __buf, size_t __n, int __flags, )
      //套接字描述符,获取的数据放到buf,长度-->指定不合适-->接受数据不知道阻塞
      //获取地址信息,和地址信息长度
      sockaddr_in _addr;
      socklen_t addr_len=sizeof(sockaddr_in);
      ret=recvfrom(_sockfd,buf,len,0,(sockaddr*)&_addr,&addr_len);
      //防止addr为空所以要定义
      if(addr){
        //addr不为空拷贝长度为addr_len如果想获取addr就会给个地址进来把地址
        //信息放进去不赋值直接为空不需要拷贝,如果空拷贝会段错误
        memcpy((void*)addr,(void*)&_addr,addr_len);
      }
      return ret;
    }
    //4发送数据,地址信息必须指定,要发送给谁(但是接受信息地址信息没必要获取)
    ssize_t Send(const char*buf,size_t len,sockaddr_in *addr){
      int ret;
      //0为默认阻塞addr地址信息 
      socklen_t addr_len=(sizeof(sockaddr_in));
      ret=sendto(_sockfd,buf,len,0,(sockaddr*)addr,addr_len);
      return ret;
    }
    //5关闭套接字
    bool IsClose(){
      if(_sockfd!=-1){
        close(_sockfd);
        _sockfd=-1;
      }
      return true;
    }
};
#define CHECK_RET(q) if((q)==false){return -1;}
int main(){
  UdpSocket sock;//创建套接字
  CHECK_RET(sock.Socket());
  sockaddr_in serv_addr;//服务端的地址
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(9000);
  serv_addr.sin_addr.s_addr=inet_addr("192.168.96.128");
  while(1){
    //绑定数据有操作系统自己绑定,然后发数据
    //std::string str;
    //std::cin>>str;
    //sock.Send(str.c_str(),str.length(),&serv_addr);//str.const_str
    //std::cout<<"client say:"<<str<<std::endl;
    char buff[1024]={0};
    scanf("%s[^\n]",buff);//获取一行
    sock.Send(buff,strlen(buff),&serv_addr);
    printf("client say :%s\n",buff);
    //接收
    char buf[1024]={0};
    sock.Recv(buf,1024);//地址可以不需要
    printf("server buf:%s\n",buf);
  } 
  sock.IsClose();
  return 0;
}
