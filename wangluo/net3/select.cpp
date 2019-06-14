#include<vector>
#include<iostream>
#include<sys/select.h>
#include"tcpsocket.hpp"
class Select{
  public:
    Select():_max_fd(-1)
    { 
   // 清空集合
   //void FD_ZERO(fd_set *set)
   FD_ZERO(&_rfds);
    }
    bool Add (TcpSocket &sock){
   //对描述符添加监控 
  // FD_SET(int fd,fd_set *set);
  int fd=sock.Getsocketfd();
  //Getsocketfd-->获得一个只读的fd描述符
   FD_SET(fd,&_rfds);
   if(fd>_max_fd){
     _max_fd=fd;
   }
   return true;
    }
    bool Del(TcpSocket&sock){
    //将描述符移除监控  
    int fd=sock.Getsocketfd();
   //FD_ CLR(int fd, fd_set *set);-->从集合当中移除指定的描述符
  FD_CLR(fd,&_rfds);
  for(int i=_max_fd ;i>=0;--i){
//FD_ISSET(int fd,fd_set*set)//判断描述符是否在集合中
    if(!FD_ISSET(i,&_rfds)){
      //从最大的开始向前遍历,如果没有一个描述符子集合中则继续
      //还在集合中的第一个就是最大的
      continue;
    }
_max_fd=i;
break;
  }
  return true;
    }
    bool Wait(std::vector<TcpSocket>&list,int timeout=300){
//用于保存所要监听的描述符,用的时候拷贝一份新的
//select(int _nfds,fd_set*_restrict _readfds,fd_set*_restrict _writefd,
//  fd_set *exceptfds, struct timeval *timeout);
//fd_set-->描述符集合,将集合拷贝到内核进行监控,监控的原理:对所有描述符进行轮询
//遍历状态当有描述符就绪时,在返回调用前,将没有就绪的描述符剔除,
//select返回值大于0就绪的描述个数,等于0超时等待,小于0监控出错
//参数1监控的个数,监控的描述符,可以是读描述符写描述符合错误信息描述符最后一
//个参数是时间的结构体,将描述符放到一个容量的列表里
fd_set rfds=_rfds;//不能直接对私有成员操作,把它变成只读模式
struct timeval tv;
tv.tv_sec=0;
tv.tv_usec=timeout*1000;
int ret=select(_max_fd+1,&rfds,NULL,NULL,&tv);
    if(ret<0){
      cout<<"select errno"<<endl;
      return false;
    }
    if(ret==0){
      cout<<"timeout"<<endl;
      return false;
    }
    //select返回后集合中保存的就是就绪的描述符(没有就绪的已经移除了)
    for(int i=0;i<=_max_fd;++i){
      if(FD_ISSET(i,&rfds)){//判断描述符是否在集合,如果在则将描述符放到list
      TcpSocket sock;
      sock.Setsocketfd(i);//设置描述符
      list.push_back(sock);//将这个描述符放到list
    }
    }
    return true;
    }
  private:
    fd_set _rfds;
int _max_fd;
};
int main(){
TcpSocket sock;
CHECK_RET(sock.Socket());
CHECK_RET(sock.Bind("0.0.0.0",9000));//0.0.0.0本地网卡的任意一个地址
CHECK_RET(sock.Listen());
Select s;
s.Add(sock);
while(1){
  std::vector<TcpSocket>list;
bool ret=s.Wait(list);
if(ret==false){
  continue;
}
for(int i=0;i<list.size();++i){
  //变量就绪的描述符列表,若就绪描述符和监听描述符相等则获取新连接的客户端socket
  if(list[i].Getsocketfd()==sock.Getsocketfd()){
TcpSocket clisock;
ret=sock.Accept(clisock);//继续描述符合监听的相等则获取新的连接客户端socket.
if(ret==false){
  continue;
}
s.Add(clisock);//对描述符添加监控
  }
else{
  std::string buf;
ret=list[i].Recv(buf);
if(ret==false){
    s.Del(list[i]);//将描述符移除监控
    list[i].Close();
}
std::cout<<"cliet say"<<endl;
}
}
}
sock.Close();
  return 0;
}
