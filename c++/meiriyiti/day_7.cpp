#include<iostream>
#include<stack>
#include<string>
using namespace std;
void test1(){
//斐波那契数列给定一个数多少步可以变成斐波那契数
//找到距离n最近的左边的数lnum(的距离)和最近的右边的数rnum(的距离),然后min(n-lnum,rnum-n)
int n,lnum,rnum,f,f0=0,f1=1,temp;
cin>>n;
while(1){
f=f0+f1;
f0=f1;
f=f1;
if(f<n){
  lnum=n-f;
}
else{
  rnum=f-n;
}
}
temp=lnum>rnum?rnum:lnum;
cout<<temp<<endl;
}
//括号匹配
bool chekkuohao(string a,int n){
stack<char> s;
for(int i=0;i<n;++i){
  if(a[i]=='('){
    s.push(a[i]);
  }
  else if(a[i]!=')'){
    if(s.top()==s.empty()){
      return false;
    }
s.pop();
  }
}
if(s.empty()){
  return true;
}
 return false;
}
class A{
  friend long fun(A s) {
    if(s.x<3){
      return -1;
    }
    return s.x+fun(A(s.x-1));
  }
  public:
  A(long a){
    x=a--;

  }
  private:
  long x;
};
void test(){
  int sum=0;
  for(int i=0;i<5;i++){
    sum+=fun(A(i));
  }
  cout<<sum<<endl;//15
}
int test2(int a,int b){
  //最小公倍数 = 两数之积除以最大公约数，这里使用碾转相除法进行最大公约数的求
  //解：即a与b的最大公约数可以转化为a、b之间的余数为两者之间最小的数之间的公约
  //数。所以对于输入的两个数进行连续求余，直到余数为0，求余的分母即为结果
  int r;
  while(r!=0){
    r=a%b;
    a=b;
    b=r;
  }
 return b; 
}
void test4(){
  int a,b;
  while(cin>>a>>b){
cout<<((a*b)/test2(a,b))<<endl;
  }
}
int main(){
test();
test4();
  return 0;
}
