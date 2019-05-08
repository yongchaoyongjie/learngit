#include"tcp_com.h"
class TcpServer{
  //接受客户端的连接通信
  private:
    TcpSocket sock;
  public:
    bool Start(std::string &ip,uint16_t port){
     CHECK_RET (sock.Socket());//拿返回值判断-->直接返回
     CHECK_RET(sock.Bind(ip,port));
     CHECK_RET(sock.Listen());
     while(1){//第一次循环走完的客户端没有被保存需要保存不然在发送一次数据后
       //就接受不到了-->多个客户端通信就要全部记录下来通信-->一个客户端无法持续
       //根服务器进行通信-->根本原因--<阻塞-->不知道连接请求什么时候来什么时候
       //来数据死等-->用线程
       TcpSocket cli_sock;
     CHECK_RET(sock.Accept(&cli_sock));//获取应该接受一个就通信而且保证接受多个只能在循环里
     //此处的sock只是接受请求一旦接受成功后就单独通信了(单独服务员),所以进行数据
     //传输是新建的socket,所以用cli_sock
    // while(1){//此处加只能代表和一个客户端通信-->不可取
char buff[1024]={0};
cli_sock.Recv(buff,1023);//为什么不用sock(门迎)cli_sock 相当于是special的服务员
printf("client say :%s\n",buff);
memset(buff,0x00,1024);
scanf("%s",buff);
cli_sock.Send(buff,strlen(buff));
     //}
     }
     CHECK_RET(sock.Close());
    }
};
int main(int argc,char*argv[]){
  if(argc!=3){
    printf("usage:./tcp_ser ip port \n");
    return -1;
  }
  uint16_t port=atoi(argv[2]);//通过参数赋值ip地址和端口
  std::string ip=argv[1];
  TcpServer server;
  server.Start(ip,port);
  return 0;
}
