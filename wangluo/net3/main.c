#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
//写数据
int main(){
  int a=100;//将数据进行持续化存储,存到磁盘上-->写入到文件里
int fd=open("./tmp.txt",O_CREAT|O_WRONLY,0664);//0664权限
if(fd<0){
  printf("open errno\n");
  return  -1;
}
//以什么格式存储
write(fd,(void*)&a,sizeof(int));//数据的地址(void*)&a
close(fd);
}
