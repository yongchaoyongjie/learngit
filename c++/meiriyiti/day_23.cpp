#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
using namespace std;
//微信红包,找到金额超过一半的
int getvalue(vector<int>gifts,int n){
  map<int,int>count;
  int middle=gifts.size()/2;
  for(const auto &e:gifts){
    ++count[e];
  }
  for(const auto&e:count){
    if(e.second>=middle){
return e.first;
    }
  }
  return 0;
}
void data_inint(){
vector<int> a{1,1};
  int i;
  for(i=2;i<10005;++i){
      a.push_back((a[i-2]+a[i-1])%1000);
  }
  int n,t;
  while(cin>>n){
    while(n--){
      cin>>t;
      printf("%04d",a[t]);
    }
    printf("\n");
  }
}
//求数根
int shuru(int n){
  int a=0;
  while(n>0){
 a+=n%10;
  n/=10;
}
while(a>9){
  a=shuru(n);
}
return a;
}
void test(){
  string shuzi;
  while(cin>>shuzi){
    int sum=0;
    //将每位相加
    for(int i=0;i<shuzi.length();++i){
sum+=shuzi[i]-'0';
    }
    cout<<shuru(sum)<<endl;
  }
}
int add1(int a,int b){
  while(b!=0){
    int sum=a^b;
    int jinwei=(a&b)<<1;
    a=sum;
    b=jinwei;
  }
  return a;
}
//一个字符串中字串出现的个数
void test2(){
  string s1,s2;
  while(cin>>s1>>s2){
    int res=0;
    size_t pos=0;
    while((pos=s1.find(s2,pos))!=string::npos){
      pos+=s2.size();//跳过第一次计算的字符串
      res++;
    }
  cout<<res<<endl;
  }
}
//求斐波那契某一段的和
#define  MAX 83
void feibo(long long num[]){
  for(int i=2;i<MAX;++i){
num[i]=num[i-1]+num[i-2];
  }
}
long long sumall(long long num[],int from,int to){
  return num[to+1]-num[from];
}
long long sumall1(long long num[],int from,int to){
long long sum1=0;
for(int i=from-1;i<=to-1;++i){
  sum1+=num[i];
}
return sum1;
}
void test3(){
  int from ,to;
  long long num[MAX]={1,1};
feibo(num);
while(cin>>from>>to){
  cout<<sumall(num,from,to)<<endl;
}
}
//兔子问题
void test31(){
int n;
long long Sum[100]={1,1};
  for(int i=2;i<=90;++i){
Sum[i]=Sum[i-1]+Sum[i-2];
  }
while(cin>>n){
  cout<<Sum[n]<<endl;
}
}
int main(){
cout<<add1(2,3)<<endl;
test2();
}
  
