#include<iostream>
#include<vector>
#include<string>
using namespace std;
void test(){
//mp3光标移动位置是第一行输入歌曲数量，第二行输入指令，最后需要显式的输出也为
//两行，第一行为当前歌曲所
//在的列表，第二行为光标所指向的歌曲。
int n;//歌曲数量
//命令
string order;
while(cin>>n>>order){
  //将歌进行编号,num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌的
  //编号
  int num=1,first=1;//
  if(n<=4){
    //歌曲不超过4所有歌曲一页显示完不需要翻页
    //
  for(int i=0;i<order.size();++i){
    if((num==1)&& (order[i]=='U')){
num=n;//当歌曲在第一个按u则到最后一个歌
    }
   else if((num==n)&&(order[i]=='D')){
      num=1;//当歌曲是最后一个,按d则到第一首
    }
    else if(order[i]=='D'){
      num++;
    }
    else{
      num--;
    }
  }
    for(int i=1;i<=n-1;++i){
      cout<<i<<" ";
    }
      cout<<n<<endl;
      cout<<num<<endl;
}
else{
  //大于4构成一个页
  for(int i=0;i<(order.size());++i){
    if((num==1)&&(first==1)&&(order[i]=='U')){
      num=n;
      first=n-3;
    }
    else if((num==n)&&(first==n)&&(order[i]=='D')){
      num=1;
      first=1;
    }
    else if((first!=1)&&(num==first)&&(order[i]=='U')){
      //屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键
      //后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。
   first--;
   num--;
    }
    else if((first!=n-3)&&(num==first+3)&&(order[i]=='D')){
      //向后移动页
      first++;
      num++;
    }
    else if(order[i]=='D'){
      num++;
    }
    else{
      num--;
    }
  
  for(int i=first;i<first+3;++i){
    cout<<i<<" ";
  }
  cout<<first+3<<endl;
  cout<<num<<endl;
}
}
}
}
//找出字符串中第一个只出现一次的字符
void test1(){
  string s;
  int hastable[256]={0};
  while(cin>>s){
    int i;
    for( i=0;i<s.size();++i){
hastable[i]++;
    }
    for(size_t i=0;i<s.size();++i){
      if(hastable[i]==1){
        cout<<s[i]<<endl;
        break;
      }
    }
    if(i>=s.size()){
      cout<<-1<<endl;
    }
  }
}
int gongyueshu(int a,int b){
  int c;
  while(c=a%b){
a=b;
b=c;
  }
  return b;
}
void test3(){
//打怪兽
int n,power;
vector<int> num;
while(cin>>n>>power){
num.resize(n);//扩容
for(int i=0;i<n;++i){
//每个怪的防御力
cin>>num[i];
}
for(int k=0;k<n;++k){
  //如果怪的能力小于自己则战力提升为power+怪物的防御力
  if(num[k]<power){
    power+=num[k];
  }
  else {
    power+=gongyueshu(power,num[k]);
  }
}
cout<<power<<endl;
}
}
int main(){
test();
  return 0;
}
