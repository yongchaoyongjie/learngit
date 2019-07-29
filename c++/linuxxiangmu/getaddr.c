#include<stdio.h>
#include<ifaddrs.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
  struct ifaddrs* addr;
getifaddrs(&addr);
while(addr!=NULL){
  struct sockaddr_in* ip=(struct sockaddr_in*)addr->ifa_addr;
  struct sockaddr_in* mask=(struct sockaddr_in*)addr->ifa_netmask;
  if(ip->sin_family!=AF_INET){
addr=addr->ifa_next;
continue;
  }
  if(ip->sin_addr.s_addr==inet_addr("127.0.0.1")){
addr=addr->ifa_next;
continue;
  }
printf("name:%s\n",addr->ifa_name);
printf("%s\n",inet_ntoa(ip->sin_addr));
printf("mask:%s\n",inet_ntoa(mask->sin_addr));
//将一个32位网络字节序的二进制ip地址准换为点分十进制的ip地址
uint32_t net=ntohl(ip->sin_addr.s_addr&&mask->sin_addr.s_addr);//转换为主机号
//ntohl网络字节序转换为主机字节序
uint32_t host=ntohl(!mask->sin_addr.s_addr);
//得到最大主机号
int i;
for(i=1;i<host;i++){
  struct in_addr ip;
  ip.s_addr=htonl(net+i);
//htonl长整型的主机字节序转为网络字节序

  printf("ip:%s\n",inet_ntoa(ip));
}
addr=addr->ifa_next;
}
  return 0;
}
