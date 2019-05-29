#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>//算法的头文件
#include<string>
using std::cin;
using std::cout;
using std::endl;
void test1(){
int x,y;
int c=0;
for(x =0,y=0;(y=123)&&(x<4);x++){
++c;
}
cout<<c<<endl;//执行4次
}
void test2(){
  printf("s,5.3s\n");
  printf("%s,%5.3s\n","computer","computer");//前面五个字节后面3个字节","一个
  //字节一共9个字节
}
void test3(){
  int year=1009;
 int  *p=&year;
 if(year<1015){
 // (*p)++;
 ++(*p);
 *p+=1;
// *p++;//c++里面是先执行++然后解引用
  printf("%d\n",*p);
 }
}
void compare1(){
  //输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)第二行包括3*n个整
  //数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
  //输出描述：
  //输出一个整数表示所有队伍的水平值总和最大值.--->找每个组的第二大然后相加
int n;
while (cin>>n){
long long sum=0;
std::vector<int> a;
a.resize(3*n);
int i=0;
for(;i<(3*n);i++){
  cin>>a[i];
}
//排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，
//相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，
//大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来
std::sort(a.begin(),a.end());
i=n;
for(i=n;i<3*n-2;i+=2){
sum+=a[i];
}
cout<<sum<<endl;
}
}
void erasezifu(){//其他地方实现不了
//删除两个字符串的公共字符
  std::string str1,str2,str3;
  //不能用cincin遇到空格停止
getline(cin,str1);
getline(cin,str2);
//遍历
int hashtable[1000]={0};
int i=0;
//使用哈希映射思想先str2统计字符出现的次数
for(i=0;i<=str2.length()-1;++i){
hashtable[str2[i]]++;
}
//遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
//// str2中没有出现过，则将他+=到ret。
for(i=0;i<=str1.length()-1;++i){
  if(hashtable[str1[i]]==0){
   str3+=str1[i];
  }
}
cout<<str3<<endl;
}
int main(){
//test1();
//test2();
//test3();
//compare1();
erasezifu();
return 0;
}
