#include<iostream>
#include<vector>
#include <stdio.h>
#include<algorithm>
using namespace std;
//查找两个字符串的最长公共字串
void test(){
string s1,s2;
while(cin>>s1>>s2){
//vv[i][j]记录短字符串s1前i个字符和长字符串s2前j个字符的最长子串的长度,初始
//化所有值为0.当s1[i-1]=s2[j-1]时vv[i][j]=vv[i-1][j-1]+1,这里使用一个额外的值
//start来记录最长子串在短字符串s1中出现的起始位置maxlen记录当前最长子串的长
//度，当vv[i][j] >maxlen 时，maxlen = vv[i][j]则
//start=i-maxlen,当s1[i-1]!=s2[j-1]时不需要任何操作,最后获取
//substr(start, maxlen)即为所求
  if(s1.size()>s2.size()){
    swap(s1,s2);
  }
int len1=s1.size();
int len2=s2.size();
int i,j,start=0,max=0;
vector<vector<int> > vv(len1+1,vector<int>(len2+1,0));
for(i=1;i<len1;++i){
for(j=1;j<len2;++j){
  if(s1[i-1]==s2[j-1]){
vv[i][j]=vv[i-1][j-1]+1;
  }
  if(vv[i][j]>max){
    //有更长的字符串则更新字符串
    max=vv[i][j];
    //以i结尾的最大长度为max,则字串的起始位置为i-max 
    start=i-max;
  }
}
}
cout<<s1.substr(start,max)<<endl;
}
}
string reversstring(string s1){
  if(s1.empty()){
    return s1;
  }
size_t start=0;
size_t end=s1.size()-1;
while(start<end){//不能用start!=end
  swap(s1[start],s1[end]);
  start++;
  end--;
}
return s1;
}
void test1(){
string s1;
getline(cin,s1);
cout<<reversstring(s1)<<endl;
}
//求解最大公共字符串长度,不区分大小写
void test2(){
//求最大公共子串用递推实现 假设 x(i): 字符串第i个字符 y(j): 字符串第j个字
//符 vv[i][j]: 以x(i),y(j)结尾的最大子串长度比如：x: "abcde" y:"bcdae"
//vv[2][1]: 以x(2),y(1)结尾的最大子串长度 即：x遍历到"abc", y遍历 到"bc", 都
//以字符'c'结尾时最大公共子串为"bc" 故：当计算vv[i][j]时，首先看x(i),y(j)的
//值(1):x(i)==y(j)当前两个字符串结尾的字符相等vv[i][j] = vv[i-1][j-1] + 1 即
//它的长度加1(2):x(i)!=y(j)当前两个字符串结尾的字符不相等，说明没有
//以这连个字符结尾的公共子串即vv[i][j] = 0 (3)vv[0][j]和vv[i][0]表示以
// 某个子串的第一个字符结尾,最大长度为1如果x(0)==y(j)或者x(i)==y(0),
//则长度为1,否则为0当vv中的所有元素计算完之后，从中找打最大的值输出
  int max=0;
  string s1,s2;
  int len1=s1.size()-1;
  int len2=s2.size()-1;
  //所有vv中的值初始化为0
  vector<vector<int> > vv(len1,vector<int>(len2,0));
  for(int i=0;i<=len1;++i){
  for(int j=0;j<=len2;++j){
    //如果当前尾字符相等则在vv[i-1][j-1]的基础上+1
    if(s1[i]==s1[j]){
      if(i>0&&j>0){
        vv[i][j]=vv[i-1][j-1]+1;
      }
      else{
        //abcd   aqwer-->只有a同
        //vv[0][j],vv[i][0]
        vv[i][j]=1;
      }
    }
    //更新最大值
    if(vv[i][j]>max){
      max=vv[i][j];
    }
  }
cout<<max<<endl;
}
}
int f(int n){
  static int i=1;
  if(n>=5){
    return n;
  }
  n=n+i;//1 1  2  2  4 3
 i++;
  return f(n);
}
void test3(){
  int n=1;
  cout<<f(n)<<endl;//7
}
#define  N 9
//函数fun的功能是：把形参a所指数组中的最小值放在元素a[0]中，接着把a所指数组
//中的最大值放在a[1]元素中;再把a所指数组元素中的次小值放在a[2]中，把a索取数
//组元素中的次大值放在a[3]，以此类推例如:若a所指数组中的数据最初排列为：
//9,1,4,2,3,6,5,8,7;按规则移动后，数据排列为:1,9,2,8,3,7,4,6,5。形参n中存放
//a所指数组中数据的个数。规定fun函数中的max存放的当前所找的最大值,px存放当前
//所找最大值得下标
void fun(int a[],int n){
  int i,j,max1,min1,px,pn;
  for(i=0;i<n-1;i+=2){
    max1=min1=a[i];
    px=pn=i;
    for(j=i+1;j<n;j++){
      if(max1<a[j]){
        max1=a[j];
        px=j;//最大下标
      }
      if(min1>a[j]){
        min1=a[j];
pn=j;//最小下标
      }
    }
    //换下标
    if(pn!=i){
      swap(a[i],a[pn]);
     //t=a[i];
     //a[i]=min1;
     //a[pn]=t;
      if(px==i){
        px=pn;
      }
    }
      if(px!=i+1){
        swap(a[i+1],a[px]);
      //  t=a[i+1];
      //  a[i+1]=max1;
      //  a[px]=t;
      }
  }
}
void test4(){
  int b[N]={9,1,4,2,3,6,5,8,7};
//  printf("\n the original data:\n");
  cout<<(" the original data:")<<endl;
  for(int i=0;i<N;i++){
    cout<<b[i];
  }
  cout<<endl;
 //  printf("%4d",b[i]);
  // printf("\n");
    fun(b,N);
  //  printf("\n the data after mocing\n");
    cout<<("the data after mocing")<<endl;
    for(int i=0;i<N;i++){
      cout<<b[i];
   // printf("%4d",b[i]);
   // printf("\n");
    }
 cout<<endl; 
}
int main(){
  //test1();
  test3();
test4();
  return 0;
}

