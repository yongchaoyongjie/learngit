#include<iostream>
using std::cin;
using std::cout;
using std::endl;
//找出字符串里面最后一个单词的长度
void findlast(){
  std::string s1;
  getline(cin,s1);
size_t end=s1.size()-1;
size_t start=0;
size_t npos=s1.rfind(' ');
cout<<s1.size()-1-npos<<endl;
}
bool isdaxie(char c){
if('A'<=c&&c<='Z'){
  return true;
}
return false;
}
bool judgehuiwen(std::string s1){
int end=s1.size()-1;
int start=0;
int i=0;
for(;i<=end;i++){
  if(isdaxie(s1[i])){
s1[i]+=32;
  }
}
//cout<<s1<<endl;
  while(start<end){
   if(s1[start]==s1[end]){
    start++;
    end--;
  }
   else{
     return false;
   }
}
}
int main(){
//findlast();
  std::string s1;
  cin>>s1;
  if(judgehuiwen(s1)){
    cout<<"yes"<<endl;
  }
  else{
  cout<<"no"<<endl;
  }
  return 0;
}
