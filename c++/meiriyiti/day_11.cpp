#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int gonggongzuxian(int a,int b){
//1234567 
  while(a!=b){
    if(a>b){
      a/=2;
    }
    else{
      b/=2;
    }
    return a;
  }
}
void test(){
  //输入一个数求转换成二进制后连续1的个数
  //获取第i位的二进制中的1的值(n>>i)&1
int n;
cin>>n;
  int count=0,maxcount=0;
  while(n){
    if(n&1){
      count++;
      maxcount=max(count,maxcount);
    }else{
      count=0;
    }
    n=n>>1;
  }
  cout<<maxcount<<endl;
}
void test1(){
  int n;
  cin>>n;
  int i=0;
  int count,maxcount;
  for(i=0;i<32;++i){
    n=n>>i;
    if(n&1){
      count++;
      maxcount=max(count,maxcount);
    }else{
      count=0;
    }
  }
  cout<<maxcount<<endl;
}
int issushu(int num){
  int temp=sqrt(num);
  int i;
  for(i=2;i<=temp;++i){
    if(num%i){
      return num;
    }
  }
}
void test2(){
  //查找一个偶数最近的两个素数
  int num;
int half;
int i;
while(cin>>num){
  half=num/2;
  for(i=half;i>0;--i){
    if(issushu(i)&&issushu(num-i)){
      break;
    }
  }
  cout<<i<<endl;
  cout<<num-i<<endl;
}
}
void test3(){
string s1;
while(getline(cin,s1)){
int count=0;
  for(int i=0;i<s1.size();++i){
    if(s1[i]==' '){
      count++;
    }
    if(s1[i]=='"'){
i=i+1;
while(s1[i]!='"'){
  i++;
}
    }
  }
cout<<count+1<<endl;//空格表示参数个数,参数个数比空格个数多1
//flag是标志,表示是否包含双引号,双引号中的空格要打印出来
//flag=0表示有双引号
//用异或改变flag的值,两个双引号可以使flag复原
int flag=0;
for(int i=0;i<s1.size();++i){
  if(s1[i]=='"'){
    flag^=0;
  }
  if(s1[i]!='"'&&s1[i]!=' '){
    cout<<s1[i];
}
//遇到双引号之外的空格就换行
if(s1[i]==' '&&(flag)){
  cout<<endl;
}
}
cout<<endl;
}
}
//统计二进制中1的个数
void test4(){
int n;
while(cin>>n){
int count;
count=0;  
for(int i=0;i<32;++i){
  if(((n>>i)&1)==1){
    count++;
  }
}
cout<<count<<endl;
}
}
int count1(int n){
  int count=0;
  while(n){
      count++;
      n=n&(n-1);
}
return count;
}
void test6(){
  int n;
  while(cin>>n){
    cout<<count1(n)<<endl;
  }
}
void test5(){
  int n;
  while(cin>>n){
    int count=0;
    while(n){
      if((n&1)==1){
        count++;
      } 
    n=n>>1;
    //n>>=1;
  }
    cout<<count<<endl;
}
}
int main(){
//test1();
//test();
//test2();
//test3();
test6();
  return 0;
}
