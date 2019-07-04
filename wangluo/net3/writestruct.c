#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
  char name[32];
  int id;
  int sex;
  int age;
}stu;
int main(){
  stu s;
  s.id=10;
  s.age=16;
  s.sex=1;
  strcpy(s.name,"xiaoming");
  int c=200;
  int a=100;
  char buff[1024]={0};
  sprintf(buff,"a=%d,c=%d",a,c);
  int fd=open("./tmp.txt",O_CREAT|O_RDWR,0664);
  if(fd<0){
    printf("open erron\n");
    return -1;
  }
  write(fd,(void*)&s,sizeof(stu));//结构体存储到文件里一个stu整体长度为12+32=44
  //个字节-->二进制形式存储,存到文件里面依次为id,age,sex-->解析的时候录一个44个
  //字节结构体直接录就可以了(直接结构体上直接解析完毕了)
  lseek(fd,0,SEEK_SET);//跳转,跳转到起始位置,进行读取
  stu child;
  read(fd,(void*)&child,sizeof(stu));
  printf("name:%s id:%d age:%d sex:%d\n",child.name,child.id,child.age,
      child.sex);
  close(fd);
  return 0;

}
