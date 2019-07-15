#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
//几个fork
void test(){
fork();
fork();
fork();
//cout<<"hellow "<<endl;//8个?
printf("hellow\n");
}
void adjustarr(vector<int>&arr,int len){
//给定一个长度不小于2的数组,写一个函数调整,所有偶数位为偶数,奇数位为奇数
    len=arr.size();
long i=0,j=1;
while(i<len&&j<len){
  if(arr[i]%2==0){
    i+=2;
    continue;
  }
  if(arr[j]%2!=0){
    j+=2;
    continue;
  }
swap(arr[i],arr[j]);
}
std::vector<int>::iterator it=arr.begin();
while(it!=(arr.end())){
  cout<<*it<<" ";
  *it++;
}
}
void fentao(){
  //因为每次分5堆就会多一个那么给它借4个则每次刚好能分五队堆而且每次老猴子的桃子
  //都不会在我们借的那四个桃子中,最后的结果减去4就可以了
//假设最初由x个桃子,我们借给猴子4个,则此时有x+4个,第一个猴子得到
//(x+4)/5，剩余(x+4)(4/5)个第二个猴子分完后剩余(x+4)(4/5)^2个 第三个
// 猴子分完后剩余()x+4)(4/5)^3个依次类推，第n个猴子分完后剩余
//(x+4)(4/5)^n要满足最后剩余的为整数并且x最小,则当x+4=5^n时满足要求,此时
//x=5^n-4;老猴子得到的数量为(x+4)*(4/5)^n+n-4=4^n+n-4最后的+n是因为每个小猴
//子都会多出一个给老猴子-4是还了借的4个
int n,houzi,oldhouzi;
while(cin>>houzi){
//猴子个数给定求最少要多少个桃子,和老猴子得到多少桃子
  if(n==0){
    break;
  }
n=pow(5,houzi)-4;
oldhouzi=pow(4,houzi)+houzi-4;
}
cout<<n<<" "<<oldhouzi<<endl;
}
  //正整数组最小不可组成和
 //{3,2,5}arr的min为2，max为10，在区间[2,10]上，4是不能被任何一个子集相加得到
 //的值中最小的，所以4是arr的最 小不可组成和； arr = {3,2,4} arr的min为2，
 //max为9，在区间[2,9]上，8是不能被任何一个子集相加得到的值中最小的，所以8是
 //arr的最小不可组成和；arr={3,1,2} arr的min为1，max为6，在区间[2,6]上，任何
 //数都可以被某一个子集相加得到，所以7是arr的最小不可组成和；请写函数返回arr
 //的最小不可组成和。 
int getnum(vector<int>&arr,int len){
  int sum,min=arr[0];
  int i,j;
  for(int i=0;i<len;++i){
    sum+=arr[i];
    if(arr[i]<min){
min=arr[i];
    }
  }
  std::vector<int>dp(sum+1,0);
  for(i=0;i<len;++i){
    for(j=sum;j>=arr[i];--j){
      if(dp[j]<dp[j-arr[i]]+arr[i]){
        dp[j]=dp[j-arr[i]]+arr[i];
      }else{
        dp[j]=dp[j];
      }
    }
  }
  for(i=min;i<=sum;++i){
    if(i!=dp[i]){
      return i;
    }
    return sum+1;
  }
}
//最快时间找到一张假币
void test3(){
//平均分三份,两份称重,对比第三份,
//两份进行称重（对比出三个的重量 ），后对最重的那份再次进行称重，直到称重
//的个数不足2个时则结束，获得假币 如果无法平均分3分则余数要么是1要么是2，因
//为是要最多称几次，n=n/3+1
//满足每次取最大分称3份，取两份一样多的过秤，然后把三份中最多的那份继续分，
//直到硬币剩余0或1时截至
long long n;
int cut1;
while(scanf("%11d,&n")!=EOF){
  if(n==0){
    break;
  }
  while(n>2){
    if(n%3){//不可以整除则取最差情况：最重的一份是 n/3 + 1个金币
      n=n/3+1;
    }
    else{
      ///可以整除在直接整除，能够获取到最重的一份
      n/=3;
    }
  }
  cut1++;
}
cout<<cut1<<endl;
}
//密码加密破解,原文与密码差五个英文字符
//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 原文字母：V W X Y Z A B C D E F G H I J K L M N
//O P Q R S T  U
//密码>E 则原文=密码-5,否则原文=密码+21
void test4(){
char c;
while((c=getchar())!=EOF){
  if('A'<=c&&c<='Z'){
    if(c>'E'){
      c=c-5;
    }
    else{
      c=c+21;
    }
  }
  putchar(c);
}
}
int main(){
  //test();
  return 0;
}
