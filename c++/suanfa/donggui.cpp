#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//法2动规
//1. 状态定义
//2. 状态间的转移方程定义
//3. 状态的初始化
//4. 返回结果,定义的状态一定要形成递推关系
int fib1(int n){
  int ret,fn1,fn2;
  if(n<0){
    return 0;
  }
  if(n==1||n==2){
    return 1;
  }
  for(int i=3;i<=n;++i){
    ret=fn1+fn2;
    fn1=fn2;
    ret=fn1;
  }
  return ret;
}
int fib(int n){
//保存中间值-->需要数组
//初始化
vector<int>arr(n+1,0);
arr[1]=arr[2]=1;
//状态转移
//f(n)=f(n-1)+f(n-2)
//返回值f(n)
//中间状态ret[i],
for(int i=3;i<=n;i++){
arr[i]=arr[i-1]+arr[i-2];
}
return arr[n];
}
//跳台阶一次跳1..n一共多少种方法
//第一次跳1 然后跳f(n)=f(n-1)+f(n-2)+...+f(2)+1,跳到f(n-1)
//f(n-1)=f(n-2)+f(n-3)+..+f(2)+1;两个式子可以得到f(n)=2f(n-1);f(n-1)=2f(n-2);
//f(3)=2f(2);
//初始状态f(1)=1;
int jum1(int n){
  if(n==1){
    return 1;
  }
  int chushi=1;//初始状态
  for(int i=2;i<n;++i){
   chushi=2*chushi;
  }
  return chushi;
}
//优化
int jum2(int n){
  if(n<=0){
    return 0;
  }
  else{

    return 1<<(n-1);
  }
}
void test(){
  int n;
  while(cin>>n){
    cout<<jum2(n)<<endl;
  }
}
//最大连续子数组的和（6，-3，-2,7，-15,1,2,2）
//定义状态第f(i)表示前i项和最大
//f(i)=f(i-1)+a[i],-->判断f(i)=max(f(i-1)+a[i],a[i])
//f(i-1)>0继续+,i-1小于0不加
//初始状态f(0)=a(0),返回值为max(f(i));
int maxarrychild(vector<int>arr){
  if(arr.empty()){
    return 0;
  }
  vector<int>ret(arr.size(),0);
  ret[0]=arr[0];
  for(int i=0;i<arr.size();++i){
    ret[i]=max(ret[i-1]+arr[i],arr[i]);
  }
  int maxnum=ret[0];
  for(int i=0;i<arr.size();++i){
    maxnum=max(maxnum,ret[i]);
  }
return maxnum;
}
//判断字符串能否拆分s="nihaoshijie"
//dict=["ni","hao","shijie"]
//初始状态为f,中间状态,表示第i个是否能切割f(i):f(i-1)f(1),...f(j)能切割不和
//j+1~i能否切分,初始状态为f(0)=ture,没有切分
bool divstring(string s,unordered_set<string>&dict){
  if(s.empty()){
    return  false;
  }
  if(dict.empty()){
    return false;
  }
  vector<bool>can_div(s.size()+1,false);//越界
  //初始化状态
 can_div[0]=true;
  for(int i=1;i<=s.size();i++){//总字符串
    for(int j=i-1;j>=0;j--){//切割的长度
      if(can_div[j]&&dict.find(s.substr(j,i-j))!=dict.end()){
        can_div[i]=true;
        break;
      }
    }
  }
  return can_div[s.size()];
}
int main(){
test();
}
