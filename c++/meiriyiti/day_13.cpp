#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void test(){
//  输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格
//，如：4 4 4 4- joker JOKER。
//    请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
string line;
while(getline(cin,line)){
  if(line.find("joker JOKER")!=-1){
    cout<<"joker JOKER"<<endl;

  }else{
    int divide1=line.find("-");
    string  card1=line.substr(0,divide1);
string card2=line.substr(divide1+1);
int c1=count(card1.begin(),card1.end(),' ');
int c2=count(card2.begin(),card2.end(),' ');
string fisrt1=card1.substr(0,card1.find(' '));
string fisrt2=card2.substr(0,card2.find(' '));
string str="345678910JQKA2jokerJOKER";
if(c1==c2){
  if(str.find(fisrt1)>str.find(fisrt2)){
    cout<<card1<<endl;
  }else{
    cout<<card2<<endl;
  }
}else{
  if(c1==3){
    cout<<card1<<endl;
  }
 else  if(c2==3){
    cout<<card2<<endl;
  }
  else{
    cout<<"errno"<<endl;
  }
}
  }
}
}
//实现字符串模糊匹配
//*匹配0个或者以上?匹配一个字符
bool pipei(const char*str1,const char*str2){
  if(*str1=='\0'&&*str2=='\0'){
    return true;
  }
  if(*str1=='\0'&&*str2!='\0'){
    return false;
  }
  if(*str1!='\0'&&*str2=='\0'){
    return false;
  }
  if(*str1=='?'){
    return pipei(str1+1,str2+1);
  }
  if(*str1=='*'){
    return pipei(str1+1,str2+1)||pipei(str1,str2+1)||pipei(str1+1,str2);
    
  }
  else if(*str1==*str2){
    return pipei(str1+1,str2+1);
  }
  return false;
}
void test1(){
string str1,str2;
while(cin>>str1>>str2){
  bool ret=pipei(str1.c_str(),str2.c_str());
  if(ret){
    cout<<"ture"<<endl;
  }else{
    cout<<"false"<<endl;
  }
}
}
void test3(){
//  第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子，会生一只兔子f(n-
//      2)。所以第n个月兔子总数： f(n) = f(n - 1) + f(n - 2)。
int month;
while(cin>>month){
  int first=1;
  int second=1;
  int result;
  for(int i=3;i<=month;++i){
    result=first+second;
    first=second;
    second=result;
  }
  cout<<result<<endl;
}
}
int main(){



}
