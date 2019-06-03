#include<iostream>
#include <algorithm>
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>
using std::cin;
using std::cout;
using std::endl;
void test(){
char a[10]={'1','2','3','4','5','6','7','8','9','0'};
//char a[10]={'1','2','3','4','5','6','7','8','9',0};//6789

char *p;
int i;
i=8;
p=a+i;
printf("%s\n",p-3);//67890

}
void test2(){
 // int ta[2][]={{0,1,2},{3,4,5}};
  int ta3[2][4]={{0,1,2},{3,4}};
  int ta1[][3]={{0,2},{},{3,4,5}};
  int ta2[][3]={{0,1,2},{3,4,5}};
  int ta4[][3]={{0,2},{2,0},{3,4,5}};
}
void test3(){
int i,j,k=0;
for(i=0,j=-1;j=0;i++,j++){//j=0则执行但是j=-1为假所以不执行
 k++;
}
cout<<k<<endl;//执行0次
}
void test4(){
  std::vector<int> array;
  array.push_back(100);
array.push_back(300);
//  array.push_back(300);
 // array.push_back(300);
  array.push_back(300);
  array.push_back(500);
  std::vector<int>::iterator it;
  for(it=array.begin();it!=array.end();it++){
    if(*it==300){
      it=array.erase(it);
    }
  }
  for(it=array.begin();it!=array.end();it++){
cout<<*it<<" ";
  }
}
void test5(){
//输出一个字符串中数字最长的的数字串
  std::string str1,str2,str3;

  getline(cin,str1);
  int i=0;
  for(i=0;i<=str1.size();i++){
//遍历字符串如果不是则表示连续数字串结束了则将数字串和之前的比较如果小则更新大则不变
    if(str1[i]>='0'&&str1[i]<='9'){
      str2+=str1[i];
    }
    else{
      if(str2.size()>=str3.size()){
        str3=str2;
      }
      str2.clear();
    }
  }
cout<<str3<<endl;
}
void fun(char*str,char*newstr){
  char *s=str;
  char *snew=newstr;
  char*temp,*final;
  int count=0,maxlen=0;
  while(*s!='\0'){
    if(*s>='0'&&*s<='9'){
      for(temp=s;*s>='0'&&*s<='9';s++){
        count++;
      }
    }
    else{
      s++;
    }
      if(maxlen<count){
maxlen=count;
count=0;
final=temp;
      }
  }
  int i=0;
  for(;i<maxlen;i++){
    *snew=*final;
    final++;
    snew++;
  }
  *snew='\0';
  cout<<"number geshu"<<maxlen<<endl;
  cout<<"shuziwei"<<newstr<<endl;
}
//int main(){
////test();
////test3();
////test4();
////test5();
//char string1[]="abc123dk3456333dlk12";
//char*newstr=(char*)malloc(100);
//fun(string1,newstr);
//  return 0;
//}
//n个数出现次数大于n/2的数
void test6(){
  //排序,计超过中间的数
int n;
std::vector<int> vec;
while(cin>>n){
vec.push_back(n);
}
sort(vec.begin(),vec.end());
cout<<vec[(vec.size()-1)/2]<<endl;
}
void test7(){
//插入后用一个变量记录每个变量变化的次
//因为要找过半的数，用一个变量count记录读取每个变量变化的次数，一个变量temp记录可能过
//半的数，先让count=1，然后让temp=vec[0]，然后往后遍历一遍，碰到和temp相同的数就给count++，否
//则就count--，如果，count变成0，就让temp=vec[i](vec数组遍历过程中的当前值),并让count=1，如此遍历
//一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数
int n;
std::vector<int> vec;
while(cin>>n){
  vec.push_back(n);
}
int count=1;
int i=0;
int temp=vec[0];
for(i=1;i<vec.size();++i){
  if(vec[i]==temp){
    ++count;
  }
  else{
    --count;
  }
  if(count==0){
    temp=vec[i];
    ++count;
  }
}
cout<<temp<<endl;
}
int main(){
  test7();
  return 0;
}
