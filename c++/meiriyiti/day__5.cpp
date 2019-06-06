#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
void test(){
  int i=1;
  cout<<i++<<endl;//1
  int i1=1;
  cout<<++i1<<endl;//2
}
void test2(){
char p1[15]="a,b,c,d";
char*p2="ABCD";
char str[50]="xyz";
strcpy(str+2,strcat(p1+2,p2+1));
cout<<str<<endl;//xyb,c,dBCD
}
void test3(){
char p1[15]="abcd";
char*p2="ABCD";
char str[50]="xyz";
strcpy(str+2,strcat(p1+2,p2+1));
cout<<str<<endl;
//xycdBCD
}
void test4(){
  int n[][3]={10,20,30,40,50,60};
  int (*p)[3];
  p=n;
  cout<<p[0][0]<<","<<*(p[0]+1)<<","<<(*p)[2]<<endl;//10 20 30
}
void test5(){
int a;float b,c;
scanf("%2d%3f%4f",&a,&b,&c);//98765432101
cout<<a<<" "<<b<<" "<<c<<endl;//98 765 4321
printf("\na=%d,b=%d,c=%f\n",a,b,c);//98 0 765.000000
}
class A{
  public:
  void test(float a){cout<<"1";}
};
class B:public A{
  void test(int b){cout<<"2";}
};
//int main(){
////test();
//A *a=new A;
//B *b=new B;
//a=b;
//a->test(1.1);//1
//b->A::test(1.1);
////test2();
////test3();
////test4();
////test5();
//return 0;
//}
////一个母串插入一个字符串并判断插入后的字符串是否为回文
bool ishuiwen(const string s){
  size_t begin=0;
  size_t end=s.size()-1;
 // for(begin,end;begin!=end;end--,begin++){
 //   if(s[begin]!=s[end]){
 //     return false;
 //   }
 // }
  while(begin!=end){
    if(s[begin]!=s[end]){
      return false;
    }
    begin++;
    end--;
  }
  return true;
}
void test6(){
  int count;
string str1,str2,str3;
getline(cin,str1);
getline(cin,str2);
for(size_t i=0;i<str1.size();++i){
str3.insert(i,str2);
if(ishuiwen(str3)){
++count;
}
}
cout<<count<<endl;
}
void test9(){
//一个数有n个元素求连续子数组的最大和
//假设sum[i-1]是以数组中第nums[i-1]为最后一个元素的一段子数组最大和
//sum[i]是以数组中第nums[i]为最后一个元素的一段子数组最大和
//那么sum[i] = max(sum[i-1], 0) + nums[i]用sum1表示sum[i-1]
//，sum2表示sum[i]，如果计算出更大的子数组和则保存到result中。如果sum[i]，
//及sum2都小于0了，则置为0，因为他加上数组下一个数，不会计算出更大的子数组和
int size;
cin>>size;
std::vector<int> num(size);
for(int i=0;i<size;i++){
cin>>num[i];
}
int result=num[0];
int sum1=0,sum2=0;
for(int i=0;i<size;i++){
  if((sum2=sum1)>=0){//sum2和sum1大于0说明当下数是最大的加上之前的数
    sum1=sum2=sum1+num[i];
  }else if((sum2=sum1)<0){//如果小于0则一定不是最大的
    sum1=sum2=num[i];
  }
  if(sum2>result){
    result=sum2;
  }
  if(sum2<0){
    sum2=0;
  }
  sum1=sum2;
}
cout<<result<<endl;
}
int main(){
//test6();
test9();
}
