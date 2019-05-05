//基于upd协议的简单网络通信程序
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
#include <errno.h>
#include <netinet/in.h>
#include<arpa/inet.h>
int main(){
  //1创建套接字建立网卡之间的关联
  //2为套接字绑定信息
  //3接受数据
  //4发送数据
  //5关闭套接字
  //int socket(int domain, int type, int protocol);
  //domain:地址域(协议族)  AF_INET--->ipv4
  //type套接字类型参数三协议流式套接字默认给0指的是tcp数据报套接字默认给0指的是udp
  //参数2:SOCK_STREAM   IPPROTO_TCP 6 流式套接字默认协议
  //   SOCK_DGRAM IPPROTO_UDP  17数据报套接字默认udp
  //返回值成功返回一个文件描述新的socket(为新的套接字返回一个文件描述符)失败-1
  int socketfd=socket(AF_INET,SOCK_DGRAM,17);
  if(socketfd<0){
    perror("socket erron\n");
    return -1;
  }
  //2为套接字绑定信息
  //int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
  //第一个套接字描述符
  //第二个地址信息(ip地址端口号)struct socketaddr{sa_family sa_family;
  ////地址域什么样的地址信息 
  //char sa_data[14]//真正的地址信息如何排布各个自己的结构体就好};
  //第三参数地址信息长度
  //返回值成功0失败-1
  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  //转换htons
  //uint16_t htons(uint16_t hostshort);短整型的主机字节序到网络字节序的转换-->
  //两个字节整型数据的主机字节序到网络字节序的转换
  //addr.sin_port=9000;//范围0-65535之间但是0-1024不推荐使用要么被知名协
  //议使用要么预留出来了
  //uint32k_t htonl(uint32_t hostshort);
  addr.sin_port=htons(9000);//实现对主机字节序的判断,判断主机是大端小端是否
  //需要字节序转换需要则转换,不可以用htonl(转换为4个字节的数据)
  //uint32k_t htonl(uint32_t hostshort);
  //4个字节整型数据的主机字节序到网络字节序的转换
  //htonl()//长整型的转换
  //addr.sin_addr.s_addr=htonl(0xc0a87a87);//地址信息,主机字节序小端需要将地址信息转换为
  addr.sin_addr.s_addr=inet_addr("192.168.122.135");
  //int_addr_t inet_addr(const char*cp)点分十进制的字符串ip地址直接转换成为网络字节序的ip地址
  //大端,存储长度大于1个字节它是4个字节需要进行转换,9000也是是short类型
  //unint32_t的数据直接赋值字符串不可以,把点分十进制的ip信息转换为16进制数字
  //192.168.122.135--->16进制为0xc0 a8  7a 87
  socklen_t len=sizeof(struct sockaddr_in);
  int ret=bind(socketfd,(struct sockaddr*)&addr,&len);//类型不一样强转
  if(ret<0){
    perror("bind error\n");
    return -1;
  }
  //3接受数据
  //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
  //struct sockaddr *src_addr, socklen_t *addrlen);
  //sockfd:套接字描述符buf:要接收的数据len要接受的数据长度
  //flags里面MSG_DONTWAIT使操作变为一个非阻塞操作没有数据则直接报错返回错误
  //信息为EAGAIN 或者EWOULDBLOCK
  //flags:0
  //默认阻塞 MSG_PEEK(从接受队列里找出队首数据进行返回)探测性接受数据
  //从缓冲区接受数据但是并不从缓冲区移除掉意味着下次接收数据的时候依然
  //接受的是这条数据-->想接受某种数据的时候探测性的接受一下看数据是否
  //完整(是不是自己想要的数据)完整则接受不完整则不接收
  //src_addr接受数据每条数据都有源地址源端口需要知道到底谁发的才能给谁
  //回就是源地址信息
  //addrlen源地址信息长度(复合长度必须指定长度,接收多长并返回实际接收长
  //度)给0接收长度为0不会接收地址信息给太长地址信息地址信息没有这么长
  //返回真实的地址信息长度(输入输出复合参数)返回值:返回数据的实际接
  //收数据长度失败:-1
  char buff[1024]={0};//一定要初始化
  struct sockaddr_in cli_addr;
  recvfrom(socketfd,buff,1023,0,(struct sockaddr*)&cli_addr,&len);
  printf("client say:%s\n",buff);
  //发送数据
  // ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
  //const struct sockaddr *dest_addr, socklen_t addrlen);
  //sickfd:套接字描述符 buf:要发送的数据len要发送的数据长度 flag:0默认阻
  //塞dest_addr:要发送的对端地址,对于服务端来说都是客户端-->客户端的地址
  //信息add_rlen地址信息长度返回值:实际发送的字节长度失败:-1
  memset(buff,0x00,1024);//数据清空
  scanf("%s",buff);//获取字符串
  sendto(socketfd,buff,strlen(buff),0,
   (struct sockaddr*)&cli_addr,len);
  printf("sever say:%s\n",buff);
  close(socketfd);
  return 0;
}
