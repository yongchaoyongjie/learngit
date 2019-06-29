#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void test(){
int n[][3]={10,20,30,40,50};
int (*p)[3];
p=n;
cout<<p[0][0]<<","<<*(p[0]+1)<<","<<(*p)[2]<<endl;
//10 20 30
}
#define SRQ(A)A*A
void test2(){
  int x=6,y=3,z=2;
  x/=SRQ(y+z)/SRQ(y+z);
  cout<<x<<endl;//0?

}
//struct st_task{
//  uint16_t id;
//  uint32_t value;
//  uint64_t timestamp;
//};
//void  test3(){
//  st_task task={};
//  uint64_t a=0x00010001;
//  memcpy(&task,&a,sizeof(uint64_t));
//  printf("%11u,%11u,%11u",task.id,task.value,task.timestamp);//1 0 0
//
//}
void func(const int &v1,const int &v2){
  cout<<v1<<endl;
  cout<<v2<<endl;
}
void test4(){
  int i=0;
  func(++i,i++);//2 0
  int j=0;
  func(j++,++j);//1 2
}
class A{
  public:
  int bar(char x){
return (int )x;
  }
  virtual int bar(int x){
    return (2*x);
  }
};
class B:public A{
  int bar(char x){
return (int )(-x);
  }
  int bar(int  x){
return (x/2);
  }
};
void test5(){
  B obj; 
  A *pobj=&obj;
printf("%d\n",pobj->bar((char)(100)));//100,基类的100
printf("%d\n",pobj->bar(100));//50//多态是子类的50 virtual

}
//统计每个月兔子的个数,一个兔子每3个月生1个兔子
void test6(){
  int month;
  while(cin>>month){
      int first=1, second=1,result;
      for(int i=3;i<=month;++i){
result=first+second;
first=second;
second=result;

      }
      cout<<result<<endl;
  }
}
class AA{
  public:
    void print(){
    cout<<"AA:print()"<<endl;
}
};
class BB :public AA{
  public:
    void print(){
    cout<<"BB:print()"<<endl;
}
};
class CC:public B{
  public:
    void print(){
    cout<<"BB:print()"<<endl;
}
};
void test7(){
CC b;
b.print();
}
//三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换
//多少瓶汽水喝？”是5瓶,如果是n瓶呢?
int shuliang(int number){
 int sum=0;//总共兑换的个数
   while(number>1){
     //3换1
     int duihuan=number/3;
     //不足三瓶保留
     int shenxia=number%3;
     sum=sum+duihuan;
     //下次可以兑换的空瓶
     number=duihuan+shenxia;
     if(number==2) {
       sum++;
       break;
     }
   }
   return sum;
}
void test8(){
int num;
while(cin>>num){
  cout<<shuliang(num)<<endl;
}
}
int main(){
//test();
//test2();
//test3();
test4();
test5();
//test6();
test7();
test8();
return 0;
}
