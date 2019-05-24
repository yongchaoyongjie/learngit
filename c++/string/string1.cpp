#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
void finding1(){
  std::string filed1("string.cpp.gz");
  size_t pos=filed1.rfind('.');
  std::string suf=filed1.substr(pos,5);//截断字符串,大小为5
  //找到到.的位置截断字符串大小截断字符串的大小为5从右到左截断,
  //从当前找到的位置从左到右取5个
  cout<<suf<<endl;
  std::string str1=("https://tower.im/teams/c7c7881c3dd841bebb1565bb6d939333/projects/");
  size_t start=str1.rfind("://");//找到://就是找到第一个/然后+3从第一个/开始
  start+=3;
  size_t finish=str1.rfind("/");
  std::string address=str1.substr(start,finish-start);
  cout<<address<<endl;
}
void test_string(){
  //删除一个字符串中的公有字符
  std::string str1,str2;
  std::string ret;
getline(cin,str1);
getline(cin,str2);
int hashtable[256]={0};
size_t i=0;
for(;i<=str1.size();i++){
  hashtable[str1[i]]++;//统计每个字符出现的个数
}
for(;i<str2.size();i++){
  if(hashtable[str1[i]]==0){
  ret+=str2[i] ;
  }
cout<<ret<<endl;
}
}
void test_string1(){
  std::string str1;
  std::string str2;
  std::string str3;
getline(cin,str1);
int i=0;
for(;i<=str1.length();i++){
  if(str1[i]>='0'&&str1[i]<='9'){
    str2+=str1[i];
  }
  else{
  if(str3.size()<str2.size()){
    str3=str2;
  }
    str2.clear();
}
}
cout<<str3<<endl;
}
int main(){
//finding1();
//test_string();
test_string1();
  return 0;
}
