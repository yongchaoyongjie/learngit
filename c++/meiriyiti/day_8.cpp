#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
void  test(){
  int p[][4]={{1},{3,2},{4,5,6},{0}};
  cout<<p[1][2]<<endl;//0
  cout<<p[0][0]<<endl;//1
  cout<<p[0][3]<<endl;//0
  cout<<p[1][1]<<endl;//2
  cout<<p[2][2]<<endl;//6
}
void test1(){
  int a=1,b=0,c=-1,d=0;
  d=++a||++b&&++c;//1后面短路了
  cout<<d<<endl;
}
void test2(){
  //1 3 3
  int a=1,b=2,c=3,d=0;
  if(a==1&&b++==2){
  
  if(b!=2||c--!=3){
printf("%d%d%d\n",a,b,c);
  }else{
printf("%d%d%d\n",a,b,c);
  }
}else{
printf("%d%d%d\n",a,b,c);
  }
}
//template<class T>class bignumber{
//long n;
//  public:
//bignumber(T,i):n(i){
//}
//bignumber operator+(bignumber b){
//return (n+b.n);
//}
//};
//int main(){
//test();
////test1();
//test2();
//bignumber<int>b1;
//bignumber<int>b2;
//b1+b2;
//b1+3;
////3+3;
//3+b1;
//return 0;
//
//}
class A{
  public:
    A(int aa,int bb) {
      a=aa--;
      b=a*bb;
    }
int a;
int b;
};
void test4(){
A x(4,5);
cout<<x.a<<endl;//4//后置返回之前的值
cout<<x.b<<endl;//20
}
class parent{
int i;
  protected:
int x;
  public:
parent(){
  x=0;
  i=0;
}
void change(){
    x++;
    i++;
}
void display();
};
class son:public parent{
  public:
    void modify();
};
void parent::display(){
  cout<<"x="<<x<<endl;
}
void son::modify(){
  x++;
}
void test5(){
  son A;
    parent B;
  A.display();//0
  A.change();
  A.modify();
  A.display();//2
  B.change();
  B.display();//1
}
//输入第一行为字符串个数
//接下来的n行每行一个字符串字符串长度小于100由小写字母组成
//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//如果根据长度排列而不是字典序排列输出"lengths",
//如果两种方式都符合输出"both"，否则输出"none"
//将接受的字符串都放到vector容器中，利用string的operator>=运算符重载来按ascii比较字符
//串，利用string的size来比较字符串的长度
void test6(){
int n;
cin>>n;
vector<string> v;
v.resize(n);
for(auto &str:v){
  cin>>str;
}
bool lensys=true,lenxsys=true;//len长度lenx字典序
for(size_t i=1;i<v.size();i++){
  if(v[i-1].size()>=v[i].size()){
    lensys=false;
    break;
  }
}
for(size_t i=1;i<v.size();i++){
  if(v[i-1]>=v[i]){
lenxsys=false;
break;
  }
}
if(lensys&&lenxsys){
  cout<<"both"<<endl;
}
else if(!lensys&&lenxsys){
  cout<<"lexicographically"<<endl;
}
else if(lensys&&!lenxsys){
  cout<<"lengths"<<endl;
}
else if(!lensys&&!lenxsys){
  cout<<"none"<<endl;
}
}
int main(){
//test4();
//test5();
test6();
return 0;
}
