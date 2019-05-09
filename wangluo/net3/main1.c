#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
  int a=100;//将数据进行持续化存储,存到磁盘上-->写入到文件里
  int c=200;
  char buff[1024]={0};
  sprintf(buff,"a=%d;c=%d",a,c);//a=%d,c=%d,就是序列化已经序列好了只不过序列的是
  //字符串的形式-->最典型的就是JSON-->是一种轻量级的数据交换格式-->数据如何组织
  //解析eg:{"firstName":"Json"}-->还有一种最简单的序列化直接写(二进制序列化)
int fd=open("./tmp.txt",O_CREAT|O_RDWR,0664);//0664权限
if(fd<0){
  printf("open errno\n");
  return  -1;
}
write(fd,(void*)buff,sizeof(int));
int b=-1;
read(fd,(void*)&b,sizeof(int));//存了什么对象以什么格式存了一个对象解析就以
//什么格式解析称为反序列化-->以二进制存就以二进制进行反序列化-->如果是结构体
//解析就是结构推荐解析
printf("%d\n",b);
close(fd);
}

