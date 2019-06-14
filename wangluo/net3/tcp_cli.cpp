#include"tcpsocket.hpp"
#include <iostream>
int main(int argc,char*argv[]){
  if(argc!=3){
    std::cout<<"tcp_cli ip port"<<endl;
  }
  std::string ip=argv[1];
  uint16_t port=atoi(argv[2]);
TcpSocket sock;
CHECK_RET(sock.Socket());
CHECK_RET(sock.Connect(ip,port));
while(1){
  std::string buf;
  std::cout<<"kehuduan say"<<endl;
  fflush(stdout);
  std::cin>>buf;
  sock.Send(buf);
}
sock.Close();
  return 0;
}
