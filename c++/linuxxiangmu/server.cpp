#include"httplib.h"
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<boost/filesystem.hpp>//文件系统里的
using namespace httplib;
namespace bf=boost::filesystem;
#define  SHARED_PATH "Download"
//#define LOG(...) std<<cout<<__VA_ARGS__
//法1...表示不定参,std<<cout表示打印出来,打印里面的信息,...可以用一个宏表示
//既作为下载的存放目录也作为共享目录存在,当前工作路径,当前目录download是共享目录
//如果在当前目录下运行程序目录创建在当前目录,如果在上一次目录运行程序则创建
//到上层目录---以当前工作路径作为标准
//
//宏为__VA_ARGS__,代表里面所有的参数
#define LOG(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
//法2fprintf表示格式化字符串写入文件,stderr,将一段数据写到标准错误格式是fmt,
//参数信息__VAARGS__,调用LOG就相当于调用fprintf
class P2PServer{
  private:
    Server _server;
  private:
    static void Gethostpair(const Request&req,Response &rsp){
rsp.status=200;
    }      
    static void Getfilelist(const Request&req,Response &rsp){
      bf::directory_iterator item_begin(SHARED_PATH);
      bf::directory_iterator item_end;//什么不传就是结束位置
      std::stringstream body;
      //body<<"<html><body>";
      for(;item_begin!=item_end;++item_begin){
      if( bf::is_directory(item_begin->status())){
         continue;
        }
      std::string name=item_begin->path().filename().string();//获取文件名
      rsp.body+=name+"\n";
      }
rsp.set_header("Content-Type","text/html");//正文信息渲染到浏览器身上
      rsp.status=200;
    }      
    static void Getfiledata(const Request&req,Response &rsp){
//将文件内容读取出来然后响应给对方
//a.txt--转换为 download/a.txt
      bf::path path(req.path);//实例化path对象
     // path.filename();//文件名称
      std::stringstream  name;
   name<<SHARED_PATH<<"/"+path.filename().string();//不能加是常量字符串?
      std::ifstream file(name.str(),std::ios::binary);
      //ifstream文件流,打开文件ifstream用于读以ios::binary二进制方式打开
      if(!file.is_open()){
        std::cerr<<"open file"<<name.str()<<"failed\n";
        rsp.status=404;
        return ;
      }
      int64_t fsize=bf::file_size(name.str());//获取文件大小
        rsp.body.resize(fsize);//重新定义body大小为fsize
file.read(&rsp.body[0],fsize);//读取,&rsp就已经读入到body里了
if(!file.good()){
  //文件是否完好
  std::cerr<<"read file"<<name.str()<<"body error\n";
  rsp.status=500;
  return;
}
file.close();
rsp.status=200;
rsp.set_header("Content-Type","application/octet-stream");//设置头信息,
//类型为appication
//octet-stream是一个二进制流下载过来
    }      
  public:
    P2PServer(){
      //判断共享目录,若不存在则创建
      if(!bf::exists(SHARED_PATH)){
        //如果文件不存在则创建它  
        //create_directory创建目录
        bf::create_directory(SHARED_PATH);
      }
    }
    bool Start(uint16_t port){
      _server.Get("/hostpair",Gethostpair);
      _server.Get("/list",Getfilelist);
      _server.Get("/list/(.*)",Getfiledata);
      _server.listen("0.0.0.0",port);
    }

};
int main(){
P2PServer srv;
srv.Start(9000);
  return 0;
}
