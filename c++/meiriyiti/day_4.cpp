#include<iostream>
#include<string>
#include <stdio.h>
#include<algorithm>
using namespace std;
int cnt=0;
int fib(int n){
  cnt++;
  if(n==0){
    return 0;
  }
  if(n==1){
    return 2;
  }
return fib(n-1)+fib(n-2);
}
//int main(){
//  fib(8);
//  cout<<cnt<<endl;
//}
void test1(){
int a[5]={1,3,5,7,9};
int *p=(int*)(&a+1);
printf("%d%d\n",*(a+1),*(p-1));
}
void test2(){
int flag;
//第二个比特位置1
cin>>flag;//4/7
cout<<(flag&=~2)<<endl;//4/5--->对的
cout<<(flag|=2)<<endl;//6/7
cout<<(flag^=2)<<endl;//4/5
cout<<(flag>>=2)<<endl;//1//右移1位相当于除以2/1
}
//int main(){
//  test2();
//test1();
//return 0;
//}
class A{
 public:
   A (char* s){
     cout<<s<<endl;
   }
   ~A(){}
};
class B:virtual public A
{
  public:
    B(char *s1,char*s2):A(s1){
      cout<<s2<<endl;
    }
};
class C:virtual public A{
  public:
    C(char* s1,char*s2):A(s1){
      cout<<s2<<endl;
    }
};
class D: public B ,public C{
  public:
    D(char*s1,char*s2,char*s3,char*s4):B(s1,s2),C(s1,s2),A(s1){
      cout<<s4<<endl;
    }
};
//int main(){
//D*p=new D("class A","class B","class C","class D");//结果为classAclassBclassC
////classD
//delete p;
//  return 0;
//}
//A - B = a 2、B - C = b 3、A + B = c 4、B + C = d 这道题目的实质是：判断三元一次方程组是否有解及求
 //1+3可以得到A=(a+c)/2；4-2可以得到C=(d-b)/2;
void test(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int A=(a+c)/2;
  int B=(c-a)/2;
  int B1=(b+d)/2;
  int C=(d-b)/2;
  if(B==B1){
cout<<A<<" "<<B<<" "<<C;
  }
  else{
    cout<<"no"<<endl;
  }
}
void test5(){
//给定一个十进制数M-->转换为N进制数
//N进制数，每个进制位的值分别是X0*N^0，X1*N^1, X2*N^2.....，X0，
//  X1，X2就是这些进制位的值，就是就是进行取模余数就是当前低进制的位的值是多少
//，通过除掉进制数，进入下一个进制位的计算。
int m,n;
cin>>m>>n;
int savedata[1000];//保存转换后的位数
int count=0;//统计转换后是几位数
//转换基数2表示二进制8表示8进制
//有个缺陷16进制有问题
int i=0;
int x;//余数
for(i=0;m;++i){
 x=m%n;
  m=m/n;
  savedata[i]=x;
  ++count;
}
int j;
for(j=count-1;j>=0;--j){
  cout<<savedata[j];
}
}
void test8(){
  string s,table="0123456789ABCDEF";
 int m,n;
 cin>>m>>n;
 int flag=-1;
// bool flag=false;
 if(m<0){
   m=0-m;
   flag=0;//flag=true;
 }
 while(m!=0){
s+=table[m%n];
m/=n;
 }
 if(flag==true){
s+='-';
 }
 reverse(s.begin(),s.end());
cout<<s<<endl;
}
int main(){
  test1();
 // test5();
// test8() ;
  return 0;
}
