//实现一个最简单的http服务端程序
//<html><body><h1>nihaoshijie</h1><body></html>
#include<sys/types.h>
#include <stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(int argc,char*argv[]){
  //首先实现tcp服务端程序
  if(argc!=3){
    printf("usage:./httpserv ip port \n");
    return -1;
  }
  int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//ipv4流式套接字tcp协议
  if(sockfd<0){
    perror("socker erron\n");
    return -1;
  }
  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_port=htons(atoi(argv[2]));
  addr.sin_addr.s_addr=inet_addr(argv[1]);
  socklen_t len=sizeof(struct sockaddr_in);//获取 地址信息长度为了绑定
  int ret;
  //bind( int __fd, const struct sockaddr *__addr, socklen_t __len  )
  //本来是sockaddr*但是内部又重新定义了一下让其变成sockaddr_in->类型
  ret=bind(sockfd,(struct sockaddr*)&addr,len);
  if(ret<0){
    perror("bind errnr\n");
    return -1;
  }
  //listen(int _fd,int _n)//n队列的最大结点
  ret=listen(sockfd,5);
  if(ret<0){
    perror("listen errno\n");
    return -1;
  }
  while(1){
    struct sockaddr_in cli_addr;
    int newfd;
    // accept(int _fd,struct sockaddr *_restrict _addr,socklen_t *_restrict)
    newfd=accept(sockfd,(struct sockaddr*)&cli_addr,&len);
    if(newfd<0){
      perror("accept error\n");//一个服务器错误程序不能退出服务要要稳定
      continue;//继续接受更新的
    }
    char header[1024]={0};//头
    ret=recv(newfd,header,1023,0);
    if(ret<=0){
      //当连接被关闭的时候它将返回0,管道是所有写端关闭的时候返回0
      //对端关闭则写端为0
      perror("recv error\n");
      close(newfd);
      continue;//重新获取接受
    }
    printf("header :[%s]\n",header);
    //响应
    char* body="<html><body><h1>chen yong jie!!! </h1><body></html>";
    //组织首行
    char *first= "HTTP/1.1 200 OK\r\n";
    //头部
    char head[1024]={0};
    sprintf(head,"Content-Length :%d\r\n\r\n",strlen(body));
    send(newfd,first,strlen(first),0);
    send(newfd,head,strlen(head),0);
    send(newfd,body,strlen(body),0);
    close(newfd);
  }
  close(sockfd);
  return 0;
}
