#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int gongyueshu(int a,int b){
  int c;
  while(c=a%b){
a=b;
b=c;
  }
  return b;
}
void test2(){
int a,b;
while(cin>>a>>b){
cout<<"最大公约数"<<endl;
cout<<gongyueshu(a,b)<<endl;
}
}
  //找到一个数超过现有总数的一半
  //如果一个数出现超过总数的一半了排序后必然在中间,遍历整个数组看是否符合
  //法1排序
class Gift{
  public:
  int getvalue(vector<int>gifts,int n){
sort(gifts.begin(),gifts.end());
int middle=gifts[n/2];
int count=0;
for(int i=0;i<n;++i){
  if(gifts[i]==middle){
    count++;
  }
}
if(count>(n/2)){
  return middle;
}
else{
  return 0;
}
  }
  
};
//法2map
class Gift1{
  int getvalue1(vector<int>gifts1,int n){
    map<int,int>count1;
    int middle1=gifts1.size()/2;
    for(const auto &e:gifts1){
      ++count1[e];
    }
    for(const auto &e:count1){
      if(e.second>=middle1){
        return e.first;
      }
  } 
return 0;
  }
};
//计算字符串的距离
//用动态规划,状态子状态word1的前1,2,3...m个字符转换成word2的前1,2,3...n
//个字符需要的编辑距离
//F(i,j):word1的前i个字符于word2的前j个字符的编辑距离 状态递推：
//F(i,j) = min{F(i-1,j）+1,F(i,j-1)+1,F(i-1,j-1)+(w1[i]==w2[j]?0:1)})}
int mindistance(string s1,string s2){
  //s1与空串之间的距离为s2的长度
  if(s1.empty()||s2.empty()){
    return max(s1.size(),s2.size());
  }
  int len1=s1.size();
  int len2=s2.size();
  //f(i,j)初始化
  vector<vector<int>>f(1+len1,vector<int>(1+len2,0));
  for(int i=0;i<=len1;++i){
f[i][0]=i;
  }
  for(int i=0;i<=len2;++i){
f[0][i]=i;
  } 
  //F(i,j)=min{F()i-1,j)+1,F(i,j-1)+1,F(i-1,j-1)+w1[i]==w2[j]?0:1)})}
  for(int i=0;i<=len1;++i){
    for(int j=0;j<len2;++j){
      //判断s1的第一个字符是否等于s2的第一个字符
      if(s1[i-1]==s2[j-1]){
        f[i][j]=1+min(f[i][j-1],f[i-1][j]);
        //字符相等距离不变
        f[i][j]=min(f[i][j],f[i-1][j-1]);
      }
      else{
        f[i][j]=1+min(f[i][j-1],f[i-1][j]);
        //字符不相等f(i-1,j-1)距离+1
        f[i][j]=min(f[i][j],1+f[i-1][j-1]);
      }
    }
  }
return f[len1][len2];
}
void test3(){
string a,b;
while(cin>>a>>b){
  cout<<mindistance(a,b)<<endl;
}
}
//跳台阶1-n,可以跳1,2,3,,,n一共有多少种方法
int jumptaijie(int number){
  //总跳法为f(n)=f(n-1)+f(n-2)++f(1)+1;
  //f(n)=2^(n-1);
  return 1<<(number-1);
}
//输入半径算周长
void test4(){
  double n,r;
  while(cin>>n>>r){
    if(n<(2*r*3.1415)){
      cout<<"yes"<<endl;
    }
    cout<<"no"<<endl;
  }
}
//不用+-法实现+法
int add1(int num1,int num2){
  while(num2!=0){
    int sum=num1^num2;//异或得到相加后不包含进位
    int jinwei=(num1&num2)<<1;//得到进位
    num1=sum;
    num2=jinwei;
  }
}
void test6(){
  int a,b;
  while(cin>>a>>b){
    cout<<add1(a,b)<<endl;
  }
}
//输入三个数判断是否满足构成三角形
#define CMP(x,y) ((x)>(y))
#define ADD(x,y) ((x)+(y))
void test5(){
  double a,b,c;
  while(cin>>a>>b>>c){
    if(CMP(ADD(a,b),c)&&CMP(ADD(b,c),a)&&CMP(ADD(a,c),b)){
      cout<<"yes"<<endl;
    }
    cout<<"no"<<endl;
  }
}
int main(){
test2();
  return 0;
}
