#include<boost/filesystem.hpp>
#include<stdio.h>
#include<vector>
#include<netinet/in.h>
#include<ifaddrs.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<iostream>
#include<string>
#include<fstream>
#include<boost/algorithm/string.hpp>
#include"httplib.h"
using namespace httplib;
 namespace bf=boost::filesystem;
class P2PClient{
  private:
    int16_t _srv_port;
  int _host_idx;//用户选中的ip地址
  std::vector<std::string>_onlien_list;//获取在线主机列表
  std::vector<std::string>_file_list;//获取文件列表
//下载的文件直接可以获取到文件名,所以不需要保存它
  private:
  bool Getallhost(std::vector<std::string>&list){
    //获取所有主机ip地址列表
struct ifaddrs *addrs=nullptr;    
struct sockaddr_in *ip=nullptr;
struct sockaddr_in *mask=nullptr;
getifaddrs(&addrs);
for(;addrs!=nullptr;addrs=addrs->ifa_next){
 ip=(struct sockaddr_in*)addrs->ifa_addr;
 mask=(struct sockaddr_in*)addrs->ifa_netmask;//获取去掩码
 if(ip->sin_family!=AF_INET){
   continue;
 }
 if(ip->sin_addr.s_addr==inet_addr("127.0.0.1")){//等于该地址依然continue
 continue;
 }
 uint32_t net,host;//获取网络号和最大的主机号
 net=ntohl(ip->sin_addr.s_addr & mask->sin_addr.s_addr);
 //ip地址&子网掩码,然后转换成主机字节序
 //主机号mask取反--最大主机号,ntohl转换成主机字节序
 host=ntohl(~mask->sin_addr.s_addr);
 for(int i=1;i<host;i++){
   struct in_addr ip;//inet_ntoa是in_addr类型
   ip.s_addr=htonl(net+i);
 list.push_back(inet_ntoa(ip));//inet_ntoa转换为字符串,要强转
//获取到所有的地址信息
}
}
freeifaddrs(addrs);//要释放
    return true;
  }
  //发送主机配对功能进行主机配对请求获取在线主机列表
  bool Getonlinehost(std::vector<std::string>&list){
//逐个发送配对请求将响应成功的放到私有成员onlinelist里
    for(auto & i:list){
//拿到字符串发起配对请求
//client类 *host ,port=80,超时等待时间---只需要地址和端口
//get()接口给个路径,返回值Response指针,等于200配对成功
Client client(&i[0],_srv_port);//&i.c_str(),_srv_port端口
auto rsp=client.Get("/hostpair");//发起请求,获取响应
if(rsp&&rsp->status==200){
  std::cerr<<"host"<<i<<"pair success";
  _onlien_list.push_back(i);
  continue;
}
  std::cerr<<"host"<<i<<"pair success";
    }
return true;
  }
  bool Showonlinehost(){
    //显示在线主机,给编号逐个打印出来就好,输入下标获取在线主机
    //遍历显示
    for(int i=0;i<_onlien_list.size();i++){
      std::cout<<i<<"."<<_onlien_list[i]<<"\n";
    }
    //用户选择
    std::cout<<"please choose:";
    std::cin>>_host_idx;
      fflush(stdout);
    if(_host_idx<0||_host_idx>_onlien_list.size()){
      //失败将其置位-1
      _host_idx=-1;
      std::cerr<<"choose error\n";
      return false;
    }
    return true;
  }
  bool Getfilelist(){
    //获取共享文件列表(指定的主机)
    Client client(_onlien_list[_host_idx].c_str(),_srv_port);//实例化对象
  auto rsp=client.Get("/list");//获取路径
  if(rsp&&rsp->status==200){//200表示成功
//成功处理文件列表在正文里面body,存放的就是文件列表信息,文件名 之间以/n间隔,
//把它解析出来放到filelist里面,split,对一个字符串以指定字符间隔
//split( SequenceSequenceT &Result, RangeT &Input, PredicateT Pred, 
//对input以指定字符进行间隔进行切割切割之后将切割的结果的每个字符串放到容器里
    std::vector<std::string >list;
    boost::split(_file_list,rsp->body,boost::is_any_of("\n"));
  //boost::is_any_of (),以anyof里面字符串里面任意一个字符来进行切割间隔,
  //相当于把filename1 filename2整个正文以/n进行切割,将每个文件名放到list当中 
  
  }
    return true;
  }
  bool Shownfilelist(std::string &name){
    //显示/打印文件列表
    for(int i=0;i<_file_list.size();i++){
      //打印
      std::cout<<i<<"."<<_file_list[i]<<std::endl;
    }
    std::cout<<"please choose:";
    int file_idx;
    fflush(stdout);
    std::cin>>file_idx;
    if(file_idx<0||file_idx>_file_list.size()){
      return  false;
    }
    return true;
    
  }
  bool Downloadfile(std::string &name){
    //下载文件--下载哪个主机的那个文件host指定主机,和文件名称
std::string host=_onlien_list[_host_idx];
std::string uri="/list/"+name;
Client client(host.c_str(),_srv_port);
auto rsp=client.Get(uri.c_str());
if(rsp&&rsp->status==200){
  std::string realpath="shared/"+name;
  std::ofstream file(realpath,std::ios::binary);
  if(!file.is_open()){
    std::cerr<<"file"<<realpath<<"open failed\n";
  }
  //写数据
  file.write(&rsp->body[0],rsp->body.size());
  if(file.good()){
    std::cerr<<file<<"realpath"<<"write body error\n";
    return false;
  }
  file.close();
  std::cout<<"file "<<realpath<<"download success\n";
}
else{
  std::cout<<"file "<<realpath<<"download failed\n";

}
    return true;
  }
  int Doface(){
    //做界面
    std::cout<<"1. 搜索附近主机\n";
    std::cout<<"2. 显示在线主机\n";
    std::cout<<"3. 显示文件列表\n";
    std::cout<<"0. 退出\n";
    int choose;
    std::cout<<"please choose:";
    fflush(stdout);
    std::cin>>choose;
    return choose;
  }
  public:
  P2PClient(uint16_t port):_srv_port(port){}
  bool Start(){
    while(1){
      int choose=Doface();
      std::vector<std::string> list;
        std::string filename;//switch里面不能定义局部变量
      switch(choose){
case 1:
//搜索附近在线主机需要getallhost-->获取所有的主机
Getallhost(list);
//主机配对
Getonlinehost(list);
        break;
case 2:
//显示在线主机
        if(Showonlinehost()==false){
          break;
        }
//获取文件列表
Getfilelist();
        break;
case 3:
        Shownfilelist(filename);//用户选择通过shownfilelist获取文件
Downloadfile(filename);
        break;
case 0:
        exit(0);
default:
        break;

      }
    }
  }
};
int main(){
P2PClient client (9000);
client.Start();
return 0;

}
