#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void test(){
  char a[]="programming";
  char b[]="language";
  char *p1,*p2;
  int i;
  p1=a;
  p2=b;
  for(int i=0;i<7;i++){
    if(*(p1+i)==*(p2+i)){
      //cout<<*(p1+i)<<endl;//g a
      cout<<*(p2+i)<<endl;//g a
    }
  }
}
struct str_t{
  long long len;
  char data[32];
};
struct data1_t{
  long long len;
  int data[2];
};
struct data2_t{
  long long len;
  char* data[1];
};
struct data3_t{
  long long len;
  void* data[];
};
void test1(){
struct str_t str;
memset((void*)&str,0,sizeof(struct str_t));
str.len=sizeof(struct str_t)-sizeof(int);
snprintf(str.data,str.len,"hello");
struct data3_t *pData=(struct data3_t*)&str;
printf("data:%s%s\n", str.data,(char*)(&(pData->data[0])));
//  long long len;
//  int data[2];
struct data1_t *p1Data=(struct data1_t*)&str;
printf("data:%s%s\n", str.data,(char*)(p1Data->data));
  //long long len;
  //char* data[1];
struct str_t *p2Data=(struct str_t*)&str; 
printf("data:%s%s\n",str.data,(char*)(p2Data->data));
//struct data2_t *p3Data=(struct data2_t*)&str;
//printf("data:%s%s\n", str.data,(char*)(p3Data->data[0]));//错误不能输出hello
//结构体指针访问的时候不能用p3Data->data[0],表示指向元素后面为数组名,
  //long long len;
  //void* data[];//是void*类型无法转化为具体的类型
}
int foo(int x,int y){
  if(x<=0||y<=0){
    return 1;
  }
  return 3*foo(x-6,y/2);
}
void test2(){
  cout<<foo(20,13)<<endl;//20  14  8  2
  //6  3  1  0 -->4个3 结果81
}
//给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的 序列。
//洗牌过程，牌被分成两组，且每组数量相等，然后每组牌从最后一个牌交叉排列，最
//后再把排列逆序就是一次洗牌的过程，K次需要重复K次这样的过程
//每次读取一个数之后，算出他经过k次洗牌后的位置，用一个长度为2n数组用来输出
//根据当前数的位置，可以算出经过一次洗牌后的位置
//如果当前数小于等于n（即在左手），则他下次出现的位置是 2*当前位置
//与之对应的当前位置 + n(在右手),的牌,则下次出现的位置是2*当前位置+1

void test3(){
int T,n,k;
//T数据组数(T<=100),k需要洗牌的个数,n总数的一半
cin>>T;
while(T--){
  cin>>n>>k;
  int number=2*n;
  vector<int> table(number);
  for(int i=0;i<number;++i){
    cin>>table[i];//输入要排序的数字
    //洗k次牌
    while(k--){
vector<int > n1(table.begin(),table.end());
for(int i=0;i<n;++i){
///如果当前数小于等于n即在左手，则他下次出现的位置是2*当前位置 
//与之对应的当前位置+n即在右手的牌,则他下次出现的位置是2*当前位置 + 1
table[2*i]=n1[i];
table[2*i+1]=n1[n+i];
}
    }
for(int i=0;i<number;++i){
  cout<<table[i]<<" ";
  cout<<table[number-1]<<endl;
}
  }
}
}
//int main(){
//  test();
//  test1();
//  test3();
//  return 0;
//}
class xipai{
vector<int> cards,left,right;
    int cardsNum;
//切牌
    void qiepai(int n,vector<int>&cards){
      for(int i=0;i<n;++i){
        left.assign(cards.begin(),cards.begin()+n);
      }
      for(int j=n;j<2*n;++j){
        right.assign(cards.begin()+n,cards.end());
      }
    }
    //洗牌
    vector<int>insert1(int n,vector<int>&cards){
qiepai(n,cards);
vector<int>newcard;
for(int i=0;i<n;++i){
newcard.push_back(left[i]);
 newcard.push_back(right[i]);
}
return newcard;
}
public:
xipai(int n):cardsNum(n){}
void xipaicards(int n,int k,vector<int>& cards){
  for(int i=0;i<k;++i){
cards=insert1(n,cards);
  }
  for(int i=0;i<(2*n-1);++i){
    cout<<cards[i]<<" ";

  }
  cout<<cards[2*n]-1<<endl;
}
};
void test5(){
  int T;
  cin>>T;
  while(T--){
 int n,k; 
 cin>>n>>k;
 vector<int>cards;
 for(int i=0;i<2*n;++i){
   int temp;
   cin>>temp;
   cards.push_back(temp);
  }
xipai s(n);
s.xipaicards(n,k,cards);
}
}
int main(){
  test5();
  return 0;
}
