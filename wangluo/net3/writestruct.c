#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
  int id;
  int sex;
  int age;
  char name[32];
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
  write(fd,(void*)&s,sizeof(stu));
  lseek(fd,0,SEEK_END);
  stu child;
  read(fd,(void*)&child,sizeof(stu));
  printf("name:-%s:%d age:%d sex:%d\n",child.name,child.id,child.age,
      child.sex);
  close(fd);
  return 0;

}
