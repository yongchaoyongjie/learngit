#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int stringtoint(string str1){
  //字符串转数字
  //123-->sum=sum*10+1
//判断字符串是否为空
  if(str1.empty()){
    return 0;
  }
  int biaozhi=1;
  if(str1[0]=='-') {
biaozhi=-1;
str1[0]='0';
  }
  if(str1[0]=='+') {
biaozhi=1;
str1[0]='0';
  }
int i;
int sum=0;
for(i=0;i<str1.size();++i){
  if(str1[i]<'0'||str1[i]>'9'){
    sum=0;
    break;
  }
  else{
sum=sum*10+str1[i]-'0';
  }
}
return  sum*biaozhi;
}
void test(){
string s1;
cin>>s1;
cout<<stringtoint(s1)<<endl;
}
string addstring(string s1,string s2){
  //当前位没有进位和当前位有进位
  //两个字符串相加加的结果放到第三个串
  int i=s1.size()-1;
  int j=s2.size()-1;
  string s3="";
  int dangqianwei=0;
  while(i>=0||j>=0){
    if(i>=0){
dangqianwei+=s1[i]-'0';
    }
    if(j>=0){
dangqianwei+=s2[j]-'0';
    }
s3+=(char)(dangqianwei%10+'0');//同位相加的数字小于10
dangqianwei/=10;//取到大于10的有进位的数.因为最大9+9=18,没有超过20,所以标志要么等
//于1 要么等于0,等于1表示有进位,等于0表示没有进位,而且此处biaozhi\=10,还表示了
//向前进了一位
i--;
j--;
  }
  if(dangqianwei=='1'){
    s3+='1';//此处表示相加完整体还有进位则+1
  }
reverse(s3.begin(),s3.end());
return s3;
}
void test2(){
  string s11,s21;
  while(cin>>s11>>s21){
    cout<<addstring(s11,s21)<<endl;
  }
}
void test3(){
  string s1("nihaoshijie");
  cout<<s1.size()<<endl;//11
  cout<<s1.length()<<endl;//11
  cout<<s1.capacity()<<endl;//11
  cout<<s1<<endl;//nihaoshijie
  s1.clear();
  cout<<s1.size()<<endl;//清空后个数变成0
  cout<<s1.capacity()<<endl;//但是容量不变
 s1.resize(15,'a') ;//有效字符增加到15个多出的用a补-->resize增容并初始化
 //因为之前已经清0所以全部是a
  cout<<s1.size()<<endl;//15
  cout<<s1.capacity()<<endl;//22
  cout<<s1<<endl;
s1.resize(20);
  cout<<s1.size()<<endl;//20
  cout<<s1.capacity()<<endl;//22,发现容量没有变化
  cout<<s1<<endl;
}
void test4(){
  string s;
  s.reserve(100);
  cout<<s.size()<<endl;//0
  cout<<s.capacity()<<endl;//100
  //reserve只是扩容但是不改变string中s的有效个数
  s.reserve(50);
  cout<<s.size()<<endl;//0
  cout<<s.capacity()<<endl;//100
}
void testreverse(){
  string s;
s.reserve(100);
size_t sz=s.capacity();
for(int i=0;i<1000;++i){
  s.push_back('c');
  if(sz!=s.capacity()){
    sz=s.capacity();
cout<<sz<<endl;
  }
}
}
//void test5(){
////三种遍历string的方式
//string s("nihaoshijie");
//for(int i=0;i<s.size();++i){
//  cout<<s[i]<<endl;
//}
//string::iterator it=s.begin();
//while(it!=s.end()){
//  cout<<*it<<endl;
//  ++it;
//}
//for(auto e :s){
//  cout<<e<<endl;
//}
//}
void test6(){
  //截断一个字符串
  string s;
  s.push_back(' ');//插入一个字符
  s.append("nihao");
s+=' ';
s+="shijie";
cout<<s<<endl;
cout<<s.c_str()<<endl;//c风格方式打印字符串
string filel("string.cpp");
size_t pos=filel.rfind('.');//从.后面向后找
string sb=(filel.substr(pos,filel.size()-pos));//substr截断字符串
cout<<sb<<endl;
}
void test7(){
//取出一段字符串的域名
string url("http://www.cplusplus.com/reference/string/string/find/");
cout<<url<<endl;
size_t start=url.find("://");
if(start==string::npos){
  cout<<"erro"<<endl;
}
start+=3;
size_t finish=url.find("/",start);
string address=url.substr(start,finish-start);
cout<<address<<endl;
}
void test8(){
   //翻转一个字符串
   string s1;
   cin>>s1;
   size_t start=0;
   size_t end=s1.size()-1;
   while(start!=end){
swap(s1[start],s1[end]);
++start;
--end;
   }
cout<<s1<<endl;
}
void test9(){
//找到一个字符串第一次只出现一次的个数
string  s;
cin>>s;
int count[256]={0};
int size=s.size();
for(int i=0;i<size;++i){
count[s[i]]+=1;
}
for(int i=0;i<size;++i){
  if(count[s[i]]==1){
    cout<<s[i]<<endl;
  }
}
}
void test10(){
//字符串里最后一个单词的长度
string line;
while(getline(cin,line)){
  size_t pos=line.rfind(' ');
  cout<<line.size()-1-pos<<endl;
}
}
bool ishuiwen(char c){
  if(c>='0'&&c<='9'){
    return true;
  }
  if(c>='a'&&c<='z'){
    return true;
  }
  if(c>='A'&&c<='Z'){
    return true;
  }
 return false; 
}
void test11(){
  //验证一个字符串是否是回文
  string s1;
   cin>>s1;
   if(s1.empty()){
     return;
   }
   int begin=0;
   int end=s1.size();
   while(begin<end){
     while(begin!=end){
       if(ishuiwen(s1[begin])){
         break;
       }
         ++begin;
     }
     while(begin!=end){
       if(ishuiwen(s1[end])){
         break;
       }
--end;
     }
     if(begin<end){
       if(((s1[begin]+32-'a')%32)==((s1[end]+32-'a')%32)){
cout<<s1[begin];
       }
       ++begin;
       --end;
     }
   }
}
int main(){
// testreverse();
//test();
//test2();
//test4();
//test5();
//test6();
//test7();
//test8();
test9();
}
