#include<iostream>
#include<vector>
using namespace std;
bool check(vector<vector<int> >a){
  int i,j,sum;
  int row=a.size();
  for(i=0;i<row;++i){//检查每一行是否相等
    sum=0;
    for(j=0;j<row;++j){
      sum+=a[i][j];
    }
    if(sum==row){
      return true;
    }
  }
  for(i=0;i<row;++i){
    sum=0;
    sum+=a[i][i];
    if(sum==row){
      return true;
    }
  }
  for(i=0;i<row;++i){//检查每一行是否相等
    sum=0;
    for(j=0;j<row;++j){
      sum+=a[j][i];
    }
    if(sum==row){
      return true;
    }
  }
  return false;
}
int zimu(string s,int k){
  //判断字母大小写
  int big=0;//大写
  int small =0;//小写
  for(int i=0;i<k;++i){
    if(s[i]>='A'&&s[i]<='Z'){
      big++;
    }
    if(s[i]>='a'&&s[i]<='z'){
      small++;
    }
    if(small+big==0) {
      return 0;
    }
    if(small==k||big==k){
      return 10;
    }
    if(small+big==k){
      return 20;
    }
  }
}
int shuzi(string s,int k){
  int i;
  int shuzi=0;
  for(i=0;i<k;++i){
    if(s[i]>='0'&&s[i]<='9'){
      shuzi++;
    }
  }
  if(shuzi==0) {
    return 0;
  }
  if(shuzi==1){
    return 10;
  }
  if(shuzi>1){
    return 20;
  }
}
int fuhao(string s,int k){
  int fuhaonum=0;
  int i;
  for(i=0;i<k;++i){
    if(!(s[i]>='A'&&s[i]<='Z')
        &&!(s[i]>='a'&&s[i]<='z')
        &&!(s[i]>='0'&&s[i]<='9')){
      fuhaonum++;
    }
  }
  if(fuhaonum==0){
    return 0;
  }
  if(fuhaonum==1){
    return 10;
  }
  else{
    return 25;
  }
}
void test(){
  string s1;
  while(cin>>s1){
int sum1,sum2,sum3,sum4,sum5;
int c=s1.size();
//密码长度
if(c<=4){
sum1=5;//小于等于4个字符得五分
}
else if(c>=8){//大于等于8得25分
  sum1=25;
}
else {
  sum1=10;//4~7的10分
}
sum2=shuzi(s1,c);//0  10  20 
sum3=fuhao(s1,c);//0  10  25
sum4=zimu(s1,c);//0   10  20
//字母为10都是大写或者小写
if((sum2>0)&&(sum3>0)&&(sum4>0)){
  if(sum2==10){
    sum5=3;
  }else{
    sum5=5;//大小写混和有数字字符
  }
}
else if((sum2>0)&&(sum4>0)&&(sum3==0)){
  sum5=2;
}
if(sum1+sum2+sum3+sum4+sum5>=90){
  cout<<"very safe"<<endl;
}
else if(sum1+sum2+sum3+sum4+sum5>=80){
  cout<<"safe"<<endl;
}
else if(sum1+sum2+sum3+sum4+sum5>=70){
  cout<<"very strong"<<endl;
}
else if(sum1+sum2+sum3+sum4+sum5>=60){
  cout<<"strong"<<endl;
}
else if(sum1+sum2+sum3+sum4+sum5>=50){
  cout<<"average"<<endl;
}
else if(sum1+sum2+sum3+sum4+sum5>=25){
  cout<<"weak"<<endl;
}
else {
  cout<<"very weak"<<endl;
}
  }
}
int main(){
test();
  return 0;
}
